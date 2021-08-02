//
// Created by baiiu on 2021/6/8.
//
#include "call_once.h"
#include <mutex>
#include <iostream>
#include <thread>

using namespace std;

static std::once_flag flag;

void testCallOnce() {

    auto f = [] {
        std::call_once(flag, []() {
            cout << "call once " << endl;
        });
    };

    thread t1(f);
    t1.join();

    thread t2(f);
    t2.join();

}