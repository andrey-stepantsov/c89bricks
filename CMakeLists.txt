cmake_minimum_required(VERSION 3.14)
enable_testing()
set(CBricksLibVER 1.0)
message("current version: ${CBricksLibVER}")
project(CBricksLib VERSION 1.0 LANGUAGES C)

set(CMAKE_C_COMPILER clang)

set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 90)

add_executable(cprime cprime.c)
# set_property(TARGET CBricksLib PROPERTY C_STANDARD 90)
configure_file(CBricksLibConfig.h.in CBricksLibConfig.h)

#target_include_directories(CBricksLib PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(cprime PUBLIC "${PROJECT_BINARY_DIR}")

add_test(NAME VersionCheck COMMAND cprime)
set_tests_properties(VersionCheck PROPERTIES PASS_REGULAR_EXPRESSION ".*v1\.0")
