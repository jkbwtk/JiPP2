cmake_minimum_required(VERSION 3.16)

project(lab4Destructor)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(lab4Destructor 
  src/main.cpp
  src/Test.cpp
)
