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

void charArrArr() {
    char arr[5][15] = {"Google", "Facebook", "LinkedIn", "Amazon", "Microsoft"};
    char *p[5]; //指针数组

    for (int i = 0; i < 5; ++i) {
        p[i] = arr[i];
    }

    char **p2 = p;
    for (int i = 0; i < 5; ++i) {
        puts(*(p2 + i)); // 二级指针偏移，偏移一个sizeof(char *)
        puts(p2[i]);
    }
}

void charArrArr2() {
    char arr[5][15] = {"Google", "Facebook", "LinkedIn", "Amazon", "Microsoft"};
    char **p2 = malloc(5 * sizeof(char *));

    for (int i = 0; i < 5; ++i) {
        *(p2 + i) = arr[i]; // 直接赋值
    }

    for (int i = 0; i < 5; ++i) {
        puts(*(p2 + i)); // 二级指针偏移，偏移一个sizeof(char *)
        puts(p2[i]);
    }
}


void day5_testPointerPointer() {
//    passPointerPointer();
//    charArrArr();
    charArrArr2();
}