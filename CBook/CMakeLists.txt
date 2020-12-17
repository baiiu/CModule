cmake_minimum_required(VERSION 3.17)
project(CBook)

set(CMAKE_C_STANDARD 11)

add_executable(
        CBook

        main.c

        day1.c day1.h

        day2.c day2.h common.h)