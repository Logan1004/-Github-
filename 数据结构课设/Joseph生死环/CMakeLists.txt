cmake_minimum_required(VERSION 3.8)
project(Joseph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Joseph.h)
add_executable(Joseph ${SOURCE_FILES})