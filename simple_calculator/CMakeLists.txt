cmake_minimum_required(VERSION 3.16)

project(simple_calculator)
set(CMAKE_CXX_STANDARD 17)

add_executable(simple_calculator src/main.cpp src/calc.cpp)
include_directories(include)
