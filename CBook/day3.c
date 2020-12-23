//
// Created by baiiu on 2020/12/20.
//

#include <string.h>
#include "day3.h"

void testArr() {
    int arr[10] = {1}; // 不赋值的默认为0

    printf("%d\n", sizeof(arr));

    for (int i = 0; i < 10; ++i) {
        printf("%d", arr[i]);
    }
}

// 二维数组传递，列数必须要加，传递行号
void printArrArr(int a[][4], int row) {
//    printf("%d\n", sizeof(a[0]));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < sizeof(a[0]) / sizeof(int); ++j) {
            printf("%d,", a[i][j]);
        }
        printf("\n");
    }

}

void testArrArr() {
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    printArrArr(arr, 3);
}

void testCharArr() {
    char c[5] = "hello"; // 6个字符，会打印乱码
    printf("%s,%d", c, sizeof(c));
}

/*
 * strlen函数，获取char*长度，\0结束判断即可
 * strcpy(to,from)，把from拷贝到to，赋值字符串
 * strcmp(s1,s2) 返回-1即s1<s2；0相等；1即s1>s2
 * strcat(s1,s2) 把s2拼接到s1中，s1空间必须比s1+s2大；
 */
void testStrFun() {
    char c[20] = "hello world";
    size_t len = strlen(c);
    printf("%d,%d\n", sizeof(c), len);

    char d[20];
    strcpy(d, c);
    printf("d = %s\n", d);

    printf("strcmp = %d\n", strcmp(c, d));
}

// 数组
void day3() {
//    testArr();
//    testArrArr();
//    testCharArr();
    testStrFun();
}