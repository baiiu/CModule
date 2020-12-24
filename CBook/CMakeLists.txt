cmake_minimum_required(VERSION 3.17)
project(CBook)

set(CMAKE_C_STANDARD 11)

add_executable(
        CBook

        main.c
        common.h

        day1.c day1.h
        day2.c day2.h
        day3.c day3.h

        day4.c day4.h day4_passpointer.c day4_passpointer.h day4_pointerAndArr.c day4_pointerAndArr.h day4_野指针.c day4_野指针.h day4_stackoverflow.c day4_stackoverflow.h day4_栈和堆差别.c day4_栈和堆差别.h)