//
// Created by baiiu on 2020/12/24.
//

#include "day4_数组指针.h"


void printArray(int (*p)[]) {
    int sizePointer = sizeof(p);
    int size = sizeof(p);
//    int len = sizeof(*p) / sizeof(int);
//    printf("size: %s, len: %d", size, len);
    printf("sizeof(int): %lu, sizePointer: %d, size: %d, %p",
           sizeof(int), sizePointer, size, p);
}

// 传递数组指针，2列的
void printArr(int (*p)[2], int row) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < sizeof(*p) / sizeof(int); ++j) {
            printf("%d,", p[i][j]);
        }
        printf("\n");
    }
}

void printArr2(int (*p)[2], int row) {
    // *p指向行，*(*p)指向具体元素
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < sizeof(*p) / sizeof(int); ++j) {
            printf("%d,", *(*(p + i) + j));
        }
        printf("\n");
    }
}

void testTwo() {
    int zippo[4][2] = {{2, 4},
                       {6, 8},
                       {1, 3},
                       {5, 7}};
    int (*pz)[2]; // 数组指针，pz指向一个内含2个int类型值的数组
    pz = zippo;

    printArr(zippo, 4);
    printf("===============\n");
    printArr2(pz, 4);
}


void day4_testArrPoint() {
    int arr[10] = {1, 2, 3};
    int len = sizeof(arr) / sizeof(int);
    printf("sizeof(arr): %lu, sizeof(int): %lu, arr len: %d\n", sizeof(arr), sizeof(int), len);

    // 指向数组第一个元素的指针
    int *p1 = arr;
    int *p2 = &arr[0];
    for (int i = 0; i < len; ++i) {
        printf("%d, %d; ", p1[i], p2[i]);
    }
    printf("\n");

    printf("sizeof(p): %lu, sizeof(*p): %lu\n", sizeof(p1), sizeof(*p1));
    printf("指向数组第一个元素的指针: %d\n", p1[0]);
//    printArray1(arr);
//    printArray2(p);
    printf("===============\n");


    printf("===============\n");

    int (*parr)[] = &arr; // 数组指针
    printf("sizeof(parr): %lu\n", sizeof(parr));
    for (int i = 0; i < len; ++i) {
        printf("%d, ", (*parr)[i]); // []运算符优先级高于*运算符
    }
    printf("\n");

    printf("传递数组指针到函数：\n");
    printArray(parr);

    // testTwo();
}