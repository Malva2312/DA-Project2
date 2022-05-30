cmake_minimum_required(VERSION 3.20)
project(DA_project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_project2 main.cpp classes/Graph.cpp classes/Graph.h classes/FileReader.cpp classes/FileReader.h classes/minHeap.h classes/maxHeap.h)
