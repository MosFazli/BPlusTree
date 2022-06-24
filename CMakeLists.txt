cmake_minimum_required(VERSION 3.17)
project(BPlusTree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BPlusTree
        BPlusTree.cpp
        BPlusTree.h
        display.cpp
        insert.cpp
        delete.cpp
        search.cpp
        functions.cpp)
