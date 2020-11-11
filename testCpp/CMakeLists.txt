cmake_minimum_required(VERSION 3.17)
project(testCpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(testCpp main.cpp testClass.cpp testClass.h)