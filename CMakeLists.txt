cmake_minimum_required(VERSION 3.15)

project(Homework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/utility.cmake)

add_target_subdir(utility STATIC)

add_target_subdir(module-1)
add_target_subdir(module-2)
add_target_subdir(module-3)
add_target_subdir(module-4)
add_target_subdir(module-5)
add_target_subdir(module-6)
add_target_subdir(module-7)
add_target_subdir(module-8)