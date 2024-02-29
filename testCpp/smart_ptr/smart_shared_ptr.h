//
// Created by ByteDance on 2024/2/29.
//

#ifndef TESTCPP_SMART_SHARED_PTR_H
#define TESTCPP_SMART_SHARED_PTR_H

#include <iostream>

using namespace std;

class shared_count {
public:
    shared_count() noexcept: _count(1) {}

    void add_count() noexcept { ++_count; }

    unsigned long reduce_count() noexcept {
        return --_count;
    }

    unsigned long get_count() const noexcept { return _count; };

private:
    unsigned long _count;
};

template<typename T>
class smart_shared_ptr {
public:
    explicit smart_shared_ptr(T *ptr = nullptr) : _ptr(ptr) {
        if (ptr) {
            _shared_count = new shared_count();
        }
    }

    ~smart_shared_ptr() {
        if (_ptr && !_shared_count->reduce_count()) {
            delete _ptr;
            delete _shared_count;
        }
    }

    T *operator->() const { return _ptr; }

    T &operator*() const { return *_ptr; }

    long use_count() {
        if (_ptr) {
            return _shared_count->get_count();
        } else {
            return 0;
        }
    }

private:
    T *_ptr;
    shared_count *_shared_count;
};


#endif //TESTCPP_SMART_SHARED_PTR_H
