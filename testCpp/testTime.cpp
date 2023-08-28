//
// Created by ByteDance on 2023/8/28.
//


#include "testTime.h"

// 返回毫秒单位
int64_t getCurrentTimeOfDay() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void testTime() {
    int64_t start_time = getCurrentTimeOfDay();

    sleep(10);

    int64_t end_time = getCurrentTimeOfDay();
    cout << "cost: " << end_time - start_time << endl;

}