cmake_minimum_required(VERSION 3.16)

project(FinalProject)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(FinalProject 
  src/main.cpp
  src/colors.cpp
  src/Csv.cpp
  src/User.cpp
  src/UserContainer.cpp
  src/MediaElement.cpp
  src/Movie.cpp
  src/Episode.cpp
  src/Song.cpp
  src/Ebook.cpp
  src/Album.cpp
  src/LibraryContainer.cpp
  src/menu.cpp
)
