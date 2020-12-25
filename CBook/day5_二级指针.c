//
// Created by baiiu on 2020/12/25.
//

#include "day5_二级指针.h"

void changeIJ(int **p1, int **p2) {
    int *temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}

// 二级指针的传递，在子函数中改变一级指针变量指向的值
void passPointerPointer() {
    int i = 5;
    int j = 10;

    int *pi = &i;
    int *pj = &j;

    printf("i=%d, j=%d, *pi=%d, *pj=%d\n", i, j, *pi, *pj);
    changeIJ(&pi, &pj);
    printf("i=%d, j=%d, *pi=%d, *pj=%d\n", i, j, *pi, *pj);
}


void day5_testPointerPointer() {
    passPointerPointer();
}