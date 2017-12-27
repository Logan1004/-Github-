cmake_minimum_required(VERSION 3.8)
project(examineeInformationSystem)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp examineeInformationSystem.h init.h)
add_executable(examineeInformationSystem ${SOURCE_FILES})