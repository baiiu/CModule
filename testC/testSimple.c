//
// Created by baiiu on 2020/12/8.
//

#include <errno.h>
#include "testSimple.h"

// 就是0和非0的区别，0是false，非0是true
int result() {
//    return 0;
    return -1;
}

void testSimple() {

//    if (result()) {
//        printf("%s", "true true true");
//    } else {
//        printf("%s", "false false false");
//    }

    for (int i = 0; i < 140; ++i) {
        errno = i;
        printf("errno %d, \t %s\n", i, strerror(errno));
    }

}