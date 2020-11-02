cmake_minimum_required(VERSION 3.17)
project(testC C)

set(CMAKE_C_STANDARD 11)

add_executable(testC main.c hello.c hello.h animal.c animal.h hookFunction.c hookFunction.h)