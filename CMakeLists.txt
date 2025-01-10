cmake_minimum_required(VERSION 3.20)

# Define the project name and where to report bugs.
set(PACKAGE_BUGREPORT "https://github.com/snapverse/cdn-framework/issues")
project(CdnFramework VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(functions_framework_cpp REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Threads)

add_executable(CdnFramework app/main.cpp)
target_compile_features(CdnFramework PRIVATE cxx_std_17)
	
include(FetchContent)
include(GNUInstallDirs)
install(TARGETS CdnFramework RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

FetchContent_Declare(
	cpr
	GIT_REPOSITORY https://github.com/libcpr/cpr.git
	GIT_TAG dec9422db3af470641f8b0d90e4b451c4daebf64
)
	
FetchContent_MakeAvailable(cpr)

target_link_libraries(CdnFramework
	PRIVATE
		functions-framework-cpp::framework
		nlohmann_json::nlohmann_json
		cpr::cpr)
