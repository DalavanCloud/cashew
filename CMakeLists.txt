cmake_minimum_required(VERSION 2.8.12.2)
project(cashew CXX)
add_executable(cashew parser.cpp simple_ast.cpp test.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -std=c++11")

