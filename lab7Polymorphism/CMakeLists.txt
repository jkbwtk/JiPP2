cmake_minimum_required(VERSION 3.16)

project(lab7Polymorphism)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(lab7Polymorphism 
  src/main.cpp
  src/Figure.cpp
)
