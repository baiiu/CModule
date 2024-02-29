//
// Created by ByteDance on 2024/2/29.
//

#ifndef TESTCPP_SMART_UNIQUE_PTR_H
#define TESTCPP_SMART_UNIQUE_PTR_H

#include <iostream>

using namespace std;


template<typename T>
class smart_unique_ptr {
public:
    explicit smart_unique_ptr(T *ptr = nullptr) : _ptr(ptr) {
    }

    smart_unique_ptr(const smart_unique_ptr &ptr) = delete;

    smart_unique_ptr &operator=(const smart_unique_ptr &ptr) = delete;

    smart_unique_ptr(smart_unique_ptr &&other) noexcept {
        _ptr = other.release();
    }

    smart_unique_ptr &operator=(smart_unique_ptr &&other) noexcept {
        other.swap(*this);
        return *this;
    }

    ~smart_unique_ptr() {
        delete _ptr;
    }


    T &operator*() const { return *_ptr; }

    T *operator->() const { return _ptr; }

    explicit operator bool() const { return _ptr; }

    T *get() const { return _ptr; }

    T *release() {
        T *ptr = _ptr;
        _ptr = nullptr;
        return ptr;
    }

    void swap(smart_unique_ptr &rhs) {
        std::swap(_ptr, rhs._ptr);
    }

private:
    T *_ptr;
};


#endif //TESTCPP_SMART_UNIQUE_PTR_H
