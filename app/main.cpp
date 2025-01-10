#include <google/cloud/functions/framework.h>

#include <iostream>
#include <string>
#include <unordered_map>

namespace gcf = ::google::cloud::functions;

namespace {
auto get_pathname(const std::string& target) {
  auto question_mark_pos = target.find('?');
  const std::string pathname = target.substr(0, question_mark_pos);
  return pathname;
}

std::unordered_map<std::string, std::string> get_query_params(
    const std::string& target) {
  std::size_t question_mark_pos = target.find('?');
  std::string query_params_string = target.substr(question_mark_pos + 1);
  std::unordered_map<std::string, std::string> query_params{};

  std::size_t ampersand_sign_pos = query_params_string.find('&');

  if (question_mark_pos != std::string::npos && ampersand_sign_pos == std::string::npos) {
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

auto single_endpoint_http() {
  return gcf::MakeFunction([](gcf::HttpRequest const& request) {
    auto const& target = request.target();
    auto const& headers = request.headers();

    std::string const& pathname = get_pathname(target);
    auto const& query_params = get_query_params(target);

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

    return gcf::HttpResponse{}
        .set_header("Content-Type", "text/plain")
        .set_payload("Hello World!");
  });
}
}  // namespace

int main(int argc, char* argv[]) {
  char* port = argv[2];
  std::cout << "Listening at http://127.0.0.1:" << port << "\n";
  return gcf::Run(argc, argv, single_endpoint_http());
}
