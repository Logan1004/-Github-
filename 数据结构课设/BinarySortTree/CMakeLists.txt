cmake_minimum_required(VERSION 3.8)
project(BinarySortTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp binarySortTree.h init.h)
add_executable(BinarySortTree ${SOURCE_FILES})