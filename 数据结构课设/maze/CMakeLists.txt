cmake_minimum_required(VERSION 3.8)
project(maze)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Maze.h)
add_executable(maze ${SOURCE_FILES})