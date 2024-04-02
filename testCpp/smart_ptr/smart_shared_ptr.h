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

    size_t reduce_count() noexcept {
        return --_count;
    }

    size_t get_count() const noexcept { return _count; };

private:
    size_t _count;
};

template<typename T>
class smart_shared_ptr {
private:
    T *_ptr;
    shared_count *_shared_count;

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

    // 拷贝构造：other多一个引用指向他，要增加other和this的引用计数
    smart_shared_ptr(const smart_shared_ptr &other) {
        if (this == &other) return;

        _ptr = other._ptr;
        if (_ptr) {
            other._shared_count->add_count();
            _shared_count = other._shared_count;
        }
    }

    // 拷贝赋值
    smart_shared_ptr &operator=(const smart_shared_ptr &other) {
        if (this == &other) return *this;

        if (_ptr && !_shared_count->reduce_count()) {
            delete _ptr;
            delete _shared_count;
        }

        _ptr = other._ptr;
        if (_ptr) {
            other._shared_count->add_count();
            _shared_count = other._shared_count;
        }

        return *this;
    }

    smart_shared_ptr(smart_shared_ptr &&other) noexcept {
        if (this == &other) return;

        _ptr = other._ptr;
        if (_ptr) {
            _shared_count = other._shared_count;
            other._ptr = nullptr;
        }
    }

    smart_shared_ptr &operator=(smart_shared_ptr &&other) noexcept {
        if (this == &other) return *this;

        _ptr = other._ptr;
        if (_ptr) {
            _shared_count = other._shared_count;
            other._ptr = nullptr;
        }
        return *this;
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

};


#endif //TESTCPP_SMART_SHARED_PTR_H
