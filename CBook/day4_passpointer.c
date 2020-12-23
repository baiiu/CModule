//
// Created by baiiu on 2020/12/23.
//

#include "day4_passpointer.h"

/*
 * 函数调用原理：值传递；实参的值赋给形参(编译原理)
 */
void change(int j) {
    printf("changing j = %d\n", j);
    j = 5;
}

void testI() {
    int i = 10;

    printf("before change: %d\n", i);
    change(i);
    printf("after change: %d\n", i);
}

/*
 * 引用传递，间接访问；
 * 传递i的地址，用指针变量接收，j存储i的地址，*j即i
 */
void changeReference(int *j) {
    printf("changing j = %d, p = %p, &j = %p\n", *j, j, &j); // j是栈上分配的变量，&j即该j的地址；j存储i传递过来的地址； *j即i
    *j = 5;
}


void testReferenceI() {
    int i = 10;

    printf("before change: %d, p = %p\n", i, &i);
    changeReference(&i);
    printf("after change: %d\n", i);
}


void testMove() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr; // arr即首地址

    for (int i = 0; i < 5; ++i) {
        printf("%d", p[i]);
    }

    printf("\n");

    for (int i = 0; i < 5; ++i) {
        printf("%d", *(p + i)); // + 1即 +基类型的1个长度
    }

    printf("\n");

    p = &arr[4];
    for (int i = 0; i < 5; ++i) {
        printf("%d", *(p - i));
    }

}

void testPointerIncrease() {
    int arr[3] = {1, 5, 9};
    int *p;
    int j;

    p = arr;
    j = *p++;
//    j = (*p)++;
//    j = *++p;
//    j = ++*p;
//    j = *p++;
    printf("arr[0]=%d, j=%d, *p=%d\n", arr[0], j, *p);

    j = p[0]++;
    printf("arr[0]=%d, j=%d, *p=%d, p[0]=%d", arr[0], j, *p, p[0]);
}


// 指针传递、指针偏移
void day4_testPassPointer() {
//    testI();
//    testReferenceI();
//    testMove();
    testPointerIncrease();
}