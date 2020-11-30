//
// Created by baiiu on 2020/11/30.
//

#include "testStruct.h"


void testStruct() {
    SET_RCVTIMEO(tv, 30);

    char *str = (char *) &tv;

    printf("%s, sizeof: %d", str, sizeof(tv));

}