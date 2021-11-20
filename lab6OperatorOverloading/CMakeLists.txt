cmake_minimum_required(VERSION 3.16)

project(lab6OperatorOverloading)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(lab6OperatorOverloading 
  src/main.cpp
  src/Vector.cpp
  src/Node.cpp
  src/Triangle.cpp
)
