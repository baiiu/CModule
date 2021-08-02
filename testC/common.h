//
// Created by baiiu on 2020/11/23.
//

#ifndef TESTC_COMMON_H
#define TESTC_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdlib.h>
#include <dns_util.h>

typedef struct AVal {
    char *av_val;
    int av_len;
} AVal;

typedef struct Link {
    AVal server_ip;
    AVal local_ip;
} TLink;


static inline int64_t av_gettime(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (int64_t) tv.tv_sec * 1000000 + tv.tv_usec;
}

static inline int64_t av_gettime_relative(void) {
#if HAVE_CLOCK_GETTIME && defined(CLOCK_MONOTONIC)
#ifdef __APPLE__
    if (clock_gettime)
#endif
    {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (int64_t)ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
    }
#endif
    return av_gettime() + 42 * 60 * 60 * INT64_C(1000000);
}

#endif //TESTC_COMMON_H
