#include "day1.h"

/*
 * 符号常量，简单替换，使用时要注意
 */
#define PI 3 + 2

void day1(void) {
    int i = PI;
    int j = PI;
    printf("i = %d, j = %d\n", i, j);

    int k = PI * PI; // 3 + 2 * 3 + 2 = 11
    printf("k = %d\n", k);
}
