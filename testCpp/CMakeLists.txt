cmake_minimum_required(VERSION 3.17)
project(testCPP)

set(CMAKE_CXX_STANDARD 11)

add_executable(testCPP main.cpp call_once.cpp call_once.h common.h testConst.cpp testConst.h testStatic.cpp testStatic.h teststring.cpp teststring.h)