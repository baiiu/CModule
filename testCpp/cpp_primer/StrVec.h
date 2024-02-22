//
// Created by ByteDance on 2024/2/21.
//

#ifndef TESTCPP_STRVEC_H
#define TESTCPP_STRVEC_H

#include <string>

using namespace std;

class StrVec {
public:
    // 默认构造函数，支持隐式类型转换
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {};

    ~StrVec();

    StrVec(const StrVec &); // 拷贝构造
    StrVec(StrVec &&) noexcept; // 移动构造

    StrVec &operator=(const StrVec &); // 拷贝赋值
    StrVec &operator=(StrVec &&) noexcept; // 移动赋值

    void push_back(const std::string &); // 添加元素

    size_t size() { return first_free - elements; }

    size_t capacity() { return cap - elements; }

    std::string *begin() const { return elements; }

    std::string *end() const { return first_free; }


private:
    static std::allocator<std::string> alloc;

    // 确保空间足够分配
    void check_n_alloc() {
        if (size() == capacity()) reallocate();
    }

    // 拷贝构造或拷贝赋值时使用
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);

    void free(); // 销毁元素并释放内存

    void reallocate(); // 获得更多内存并拷贝已有元素

    std::string *elements; // 指向数组首元素的指针
    std::string *first_free; // 指向数组第一个空闲元素的指针
    std::string *cap; // 指向数据尾后位置的指针
};

#endif //TESTCPP_STRVEC_H
