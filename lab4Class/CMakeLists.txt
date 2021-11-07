cmake_minimum_required(VERSION 3.16)

project(lab4Class)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(lab4Class 
  src/main.cpp
  src/Prostopadloscian.cpp
  src/Kula.cpp
  src/FunkcjaKwadratowa.cpp
  src/Student.cpp
)
