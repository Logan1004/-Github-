cmake_minimum_required(VERSION 3.8)
project(ElectricityNet)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PrimTree.h)
add_executable(ElectricityNet ${SOURCE_FILES})