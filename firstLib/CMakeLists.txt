cmake_minimum_required(VERSION 3.16)

project(firstLib)
set(CMAKE_CXX_STANDARD 17)

add_library(firstLib STATIC src/lib.cpp)
include_directories(include)
