cmake_minimum_required(VERSION 3.20)
project(DA_project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_project2 main.cpp Graph.cpp Graph.h fileReader.cpp fileReader.h Edge.cpp Edge.h)
