//
// Created by baiiu on 2020/12/24.
//

#include "day4_数组指针.h"

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


void day4_testArrPoint() {

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