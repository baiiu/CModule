//
// Created by baiiu on 2021/3/4.
//

#include "testCPP.h"
#include "common.h"

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void swapCpp(int &p1, int &p2) {
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

void testCpp() {

    int a = 1, b = 2;


    swapCpp(a, b);
    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b);
    printf("a = %d, b = %d", a, b);


    uint8_t arr[] = {1, 2, 3};
    uint8_t *data = arr;




}