//
// Created by baiiu on 2021/6/8.
//

#ifndef TESTCPP_COMMON_H
#define TESTCPP_COMMON_H

#include <mutex>
#include <iostream>
#include <thread>
#include "vector"
#include "queue"
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

using namespace std;


/* Used to retry syscalls that can return EINTR. */
#define TEMP_FAILURE_RETRY(exp) ({         \
    __typeof__(exp) _rc;                   \
    do {                                   \
        _rc = (exp);                       \
    } while (_rc == -1 && errno == EINTR); \
    _rc; })

static bool IsValidPtr(void *p, size_t len = sizeof(void *)) {
    if (!p) {
        return false;
    }
    bool ret;

    auto ptr = reinterpret_cast<std::uintptr_t>(p);
    ret = !(ptr % sizeof(void *));

    if (!ret) {
        return false;
    }

    int fd = TEMP_FAILURE_RETRY(open("/dev/random", O_WRONLY));
    if (fd != -1) {
        if (TEMP_FAILURE_RETRY(write(fd, p, len)) < 0) {
            ret = false;
        } else {
            ret = true;
        }
        close(fd);
    } else {
        ret = false;
    }

    return ret;
}

#endif //TESTCPP_COMMON_H
