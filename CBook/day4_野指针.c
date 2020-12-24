//
// Created by zhezhu on 2020/12/24.
//

#include "day4_野指针.h"


void day4_testNoPointer() {

    int *p, *p1, *p2;

    p = (int *) malloc(4);
    *p = 1;

    p1 = (int *) malloc(4);
    *p1 = 2;


    free(p);
//    p = NULL;

    p2 = (int *) malloc(4);
    *p2 = 3;

    /*
     * p必须赋值NULL,否则程序执行会出错，此时打印p2为100；
     * 因为p被free了，malloc p2的时候用的是p的内存；
     * 所以这就是野指针，会修改别人正常内存地址里的值，极为难查；
     */
    *p = 100;

    printf("*p1=%d,*p2=%d", *p1, *p2);

}