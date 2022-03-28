//
// Created by baiiu on 2022/3/9.
//

#include "testSingleton.h"
#include <mutex>
#include <iostream>

using namespace std;

class Singleton {
private:
    Singleton() {};

    Singleton(const Singleton &other) {};

public:
    static std::atomic<Singleton *> mInstance;
    static std::mutex m_mutex;

    static Singleton *getInstance();
};

std::atomic<Singleton *> Singleton::mInstance;
std::mutex Singleton::m_mutex;


Singleton *Singleton::getInstance() {
    Singleton *temp = mInstance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire); // 获取内存fence

    if (temp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        temp = mInstance.load(std::memory_order_relaxed);

        if (temp == nullptr) {
            temp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release); // 释放内存fence
            mInstance.store(temp, std::memory_order_relaxed);
        }
    }

    return temp;
}


class SimpleSingleton {
private:
    static SimpleSingleton *sInstance;

    SimpleSingleton();

    SimpleSingleton(const SimpleSingleton &other);

public:
    // 线程非安全版本
    static SimpleSingleton *getInstance();
};


SimpleSingleton *SimpleSingleton::sInstance = nullptr;

SimpleSingleton::SimpleSingleton() {}

SimpleSingleton::SimpleSingleton(const SimpleSingleton &other) {}

SimpleSingleton *SimpleSingleton::getInstance() {
    if (sInstance == nullptr) {
        sInstance = new SimpleSingleton;
    }

    return sInstance;
}

// 在类内实现
class ASimpleSingleton {
private:
    static ASimpleSingleton *instance;
private:
    ASimpleSingleton() {};

    ~ASimpleSingleton() {};

    ASimpleSingleton(const ASimpleSingleton &);

    ASimpleSingleton &operator=(const ASimpleSingleton &);

public:
    static ASimpleSingleton *getInstance() {
        if (instance == NULL)
            instance = new ASimpleSingleton();
        return instance;
    }
};

// init static member
ASimpleSingleton *ASimpleSingleton::instance = NULL;

class BestSingle {
private:

    BestSingle() {}

    ~BestSingle() {}

    BestSingle(const Singleton &other) = delete;

    BestSingle &operator=(const Singleton &other) = delete;

public:
    static BestSingle &getInstance() {
        static BestSingle sInstance;
        return sInstance;
    }
};

void testSingleton() {
    ASimpleSingleton *a = ASimpleSingleton::getInstance();
    SimpleSingleton *b = SimpleSingleton::getInstance();
    Singleton *c = Singleton::getInstance();
    cout << "single: " << a << ", " << b << ", " << c << endl;


    BestSingle &d = BestSingle::getInstance();
    cout << &d << endl;
}