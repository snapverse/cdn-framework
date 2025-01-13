cmake_minimum_required(VERSION 3.20)

project(CdnFramework VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(functions_framework_cpp REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(CURL REQUIRED)
find_package(Threads)

add_executable(CdnFramework app/main.cpp)
target_compile_features(CdnFramework PRIVATE cxx_std_17)
	
include(GNUInstallDirs)
include_directories(${CURL_INCLUDE_DIR})
install(TARGETS CdnFramework RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

target_link_libraries(CdnFramework
	PRIVATE
		functions-framework-cpp::framework
		nlohmann_json::nlohmann_json
		${CURL_LIBRARIES})
