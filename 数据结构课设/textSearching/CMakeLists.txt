cmake_minimum_required(VERSION 3.8)
project(textSearching)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp createTxt.h Init.h searching.h counting.h)
add_executable(textSearching ${SOURCE_FILES})