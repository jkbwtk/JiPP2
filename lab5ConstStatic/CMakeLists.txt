cmake_minimum_required(VERSION 3.16)

project(lab5ConstStatic)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(lab5ConstStatic 
  src/main.cpp
  src/Pojazd.cpp
)
