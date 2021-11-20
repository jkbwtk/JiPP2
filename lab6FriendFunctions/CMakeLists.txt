cmake_minimum_required(VERSION 3.16)

project(lab6FriendFunctions)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(lab6FriendFunctions 
  src/main.cpp
  src/Node.cpp
)
