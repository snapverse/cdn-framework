cmake_minimum_required(VERSION 3.20)

# Define the project name and where to report bugs.
set(PACKAGE_BUGREPORT "https://github.com/snapverse/cdn-framework/issues")
project(CdnFramework)

set(CMAKE_CXX_STANDARD 17)

find_package(functions_framework_cpp REQUIRED)
find_package(Threads)

add_executable(CdnFramework app/main.cpp)
target_compile_features(CdnFramework PRIVATE cxx_std_17)
target_link_libraries(CdnFramework functions-framework-cpp::framework)

include(GNUInstallDirs)
install(TARGETS CdnFramework RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
