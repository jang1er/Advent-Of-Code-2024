cmake_minimum_required(VERSION 3.29)
project(day4)

set(CMAKE_CXX_STANDARD 20)
file(COPY input.txt DESTINATION .)
add_executable(day4 main.cpp)
