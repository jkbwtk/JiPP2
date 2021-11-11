cmake_minimum_required(VERSION 3.16)

project(lab5ClassCopy)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(lab5ClassCopy 
  src/main.cpp
  src/Pojazd.cpp
)
