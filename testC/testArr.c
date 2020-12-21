//
// Created by baiiu on 2020/12/21.
//

#include "testArr.h"


void printArr(int *arr) {
    printf("%p,%p\n", arr, &arr);
}

/*
 *  函数调用栈，压栈了，弹栈后就把该栈空间回收了继续使用了；
 *  所以在不同栈上形参分配的地址是不一样的
 */
void printArr2(int arr[]) {
    printf("%p,%p\n", arr, &arr);
    printArr(arr);
}

void testArr() {
    int arr[10] = {0};

    printArr2(arr);

}