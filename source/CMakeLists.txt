cmake_minimum_required(VERSION 3.2)

project(editBase VERSION 1.0)

add_subdirectory(lib)
add_subdirectory(program)
set(CMAKE_CXX_FLAGS "-std=c++11 -03")
