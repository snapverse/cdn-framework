#include <curl/curl.h>
#include <google/cloud/functions/framework.h>

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

namespace gcf = ::google::cloud::functions;

namespace http {
namespace {
auto WriteFunction(char* data, size_t size, size_t nmemb, void* userp) {
  *static_cast<std::ostream*>(userp) << data;
  return size * nmemb;
};

auto Request(const std::string& verb, const std::string& url) {
  CURL* hnd;
  CURLcode ret;
  std::string res;

  hnd = curl_easy_init();

  curl_easy_setopt(hnd, CURLOPT_URL, url.data());
  curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, verb.data());

  curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, WriteFunction);
  curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &res);

  curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/7.45.0");

  curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
  curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);

  ret = curl_easy_perform(hnd);

  curl_easy_cleanup(hnd);
  hnd = nullptr;

  if (ret != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(ret));
  }

  return nlohmann::json::parse(res);
}
}  // namespace
}  // namespace http

namespace util {
namespace {
std::string Pathname(const std::string& target) {
  auto question_mark_pos = target.find('?');
  const std::string pathname = target.substr(0, question_mark_pos);
  return pathname;
}
std::unordered_map<std::string, std::string> QueryParams(
    const std::string& target) {
  std::size_t question_mark_pos = target.find('?');
  std::string query_params_string = target.substr(question_mark_pos + 1);
  std::unordered_map<std::string, std::string> query_params{};

  std::size_t ampersand_sign_pos = query_params_string.find('&');

  if (question_mark_pos != std::string::npos &&
      ampersand_sign_pos == std::string::npos) {
    ampersand_sign_pos = query_params_string.size() - 1;
  }

  while (ampersand_sign_pos != std::string::npos) {
    std::string chunk = query_params_string.substr(0, ampersand_sign_pos);
    std::size_t equal_sign_pos = chunk.find('=');

    std::string const key = chunk.substr(0, equal_sign_pos);
    std::string const value = chunk.substr(equal_sign_pos + 1);

    query_params.insert({key, value});

    query_params_string = query_params_string.substr(chunk.size() + 1);
    ampersand_sign_pos = query_params_string.find('&');
  }

  return query_params;
}
}  // namespace
}  // namespace util

namespace {
gcf::Function handler() {
  return gcf::MakeFunction([](gcf::HttpRequest const& request) {
    auto const& target = request.target();
    auto const& headers = request.headers();

    std::string const& pathname = util::Pathname(target);
    auto const& query_params = util::QueryParams(target);

    std::cout << "Pathname" << "\n";
    std::cout << pathname << "\n\n";

    std::cout << "Headers" << "\n";
    for (auto const& [key, value] : headers) {
      std::cout << key << " : " << value << "\n";
    }
    std::cout << "\n";

    std::cout << "Query Params" << "\n";
    for (auto const& [key, value] : query_params) {
      std::cout << key << " : " << value << "\n";
    }

    auto comments =
        http::Request("GET", "https://jsonplaceholder.typicode.com/comments");

    return gcf::HttpResponse{}
        .set_header("Content-Type", "text/plain")
        .set_payload(comments.dump(4));
  });
}
}  // namespace

int main(int argc, char* argv[]) {
  char* port = argv[2];
  std::cout << "Listening at http://127.0.0.1:" << port << "\n";
  return gcf::Run(argc, argv, handler());
}
