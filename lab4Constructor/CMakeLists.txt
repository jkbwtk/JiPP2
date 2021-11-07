cmake_minimum_required(VERSION 3.16)

project(lab4Constructor)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(lab4Constructor 
  src/main.cpp
  src/Punkt.cpp
  src/Figura.cpp
)
