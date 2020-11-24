//
// Created by baiiu on 2020/11/23.
//

#ifndef TESTC_COMMON_H
#define TESTC_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct AVal {
    char *av_val;
    int av_len;
} AVal;

typedef struct Link {
    AVal server_ip;
    AVal local_ip;
} TLink;

#endif //TESTC_COMMON_H
