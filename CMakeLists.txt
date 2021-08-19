cmake_minimum_required(VERSION 3.5)

project(NB)

add_executable(NB
  main.cpp
  nbc.cpp
)

set_property(TARGET NB PROPERTY CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")
