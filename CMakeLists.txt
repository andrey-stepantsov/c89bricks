cmake_minimum_required(VERSION 3.14)
enable_testing()
project(CBricksLib VERSION 1.0 LANGUAGES C)

set(CMAKE_C_COMPILER clang)

set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 90)

add_subdirectory(src)
