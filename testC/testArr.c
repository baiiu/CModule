//
// Created by baiiu on 2020/12/21.
//

#include "testArr.h"


void printArr(int *arr) {
    printf("%p,%p\n", arr, &arr);
}

void printArr2(int arr[]) {
    printf("%p,%p\n", arr, &arr);
}

void testArr() {
    int arr[10] = {0};

    printArr(arr);
    printArr(arr);
    printArr(arr);
    printArr(arr);
    printArr(arr);
    printArr(arr);
    printArr(arr);

    printf("=================\n");

    printArr2(arr);
    printArr2(arr);
    printArr2(arr);
    printArr2(arr);
    printArr2(arr);
    printArr2(arr);

}