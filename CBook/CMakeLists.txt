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

        day4_直接访问间接访问.c day4_直接访问间接访问.h
        day4_指针传递和指针偏移.c day4_指针传递和指针偏移.h
        day4_字符指针和字符数组.c day4_字符指针和字符数组.h
        day4_野指针.c day4_野指针.h
        day4_stackoverflow.c day4_stackoverflow.h
        day4_栈和堆差别.c day4_栈和堆差别.h
        day4_数组指针.c day4_数组指针.h
        day5_二级指针.c day5_二级指针.h)