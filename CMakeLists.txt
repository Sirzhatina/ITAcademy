cmake_minimum_required(VERSION 3.15)

project(Homework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/utility.cmake)

add_subdir(module-1)
add_subdir(module-2)
add_subdir(module-3)