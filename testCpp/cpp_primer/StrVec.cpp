//
// Created by ByteDance on 2024/2/21.
//

#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &s) {
    // copy s有效空间到本StrVec
    auto data = alloc_n_copy(s.begin(), s.end());
    elements = data.first;
    first_free = cap = data.second;
}

/*
 * 与拷贝构造函数不同，移动构造函数不分配任何新内存；它接管给定的StrVec中的内存。
 * 在接管内存之后，它将给定对象中的指针都置为nullptr。这样就完成了从给定对象的移动操作，此对象将继续存在。
 * 最终，移后源对象会被销毁，意味着将在其上运行析构函数。
 * StrVec的析构函数在first_free上调用deallocate，如果我们忘记了改变s.first_free，则销毁移后源对象就会释放掉我们刚刚移动的内存。
 */
StrVec::StrVec(StrVec &&s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr; // s对象的析构函数在first_free上调用deallocate，如果我们忘记了改变s.first_free，则销毁移后源对象就会释放掉我们刚刚移动的内存
}

StrVec &StrVec::operator=(const StrVec &s) {
    if (this == &s) {
        return *this;
    }

    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&s) noexcept {
    if (this == &s) {
        return *this;
    }

    free();
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;

    // s对象的析构函数在first_free上调用deallocate，如果我们忘记了改变s.first_free，则销毁移后源对象就会释放掉我们刚刚移动的内存
    s.elements = s.first_free = s.cap = nullptr;
    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string &s) {
    check_n_alloc();
    /*
     * 为了使用此原始内存，我们必须调用construct，在此内存中构造一个对象。
     * 传递给construct的第一个参数必须是一个指针，指向调用allocate所分配的未构造的内存空间。剩余参数确定用哪个构造函数来构造对象。
     * 在本例中，只有一个额外参数，类型为string，因此会使用string的拷贝构造函数。
     */
    alloc.construct(first_free++, s);
}

/*
 * 当我们拷贝或赋值StrVec时，必须分配独立的内存，并从原StrVec对象拷贝元素至新对象。
 * alloc_n_copy成员会分配足够的内存来保存给定范围的元素，并将这些元素拷贝到新分配的内存中。返回指针的pair，两个指针分别指向新空间的开始位置和拷贝的尾后的位置；
 * alloc_n_copy用尾后指针减去首元素指针，来计算需要多少空间。在分配内存之后，它必须在此空间中构造给定元素的副本。
 */
std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

/*
 * 首先destroy元素，然后释放StrVec自己分配的内存空间。
 * for循环调用allocator的destroy成员，从构造的尾元素开始，到首元素为止，逆序销毁所有元素：
 */
void StrVec::free() {
    if (!elements) return;

    // destroy函数会运行string的析构函数。string的析构函数会释放string自己分配的内存空间。
    for (auto p = first_free; p != elements;) {
        alloc.destroy(--p);
    }
    // 传递给deallocate的指针必须是之前某次allocate调用所返回的指针。因此，在调用deallocate之前我们首先检查elements是否为空。
    alloc.deallocate(elements, cap - elements);
}

// 使用移动而非拷贝来保留原先的元素而去扩容
void StrVec::reallocate() {
    size_t newCapacity = 2 * size() + 1;
    auto newData = alloc.allocate(newCapacity);
    // 移动原元素到扩容后容器
    auto dest = newData;
    auto elem = elements;
    for (int i = 0; i < size(); ++i) {
        // construct的第二个参数，是move返回的值。
        // 调用move返回的结果会令construct使用string的移动构造函数。由于我们使用了移动构造函数，这些string管理的内存将不会被拷贝。
        // 相反，我们构造的每个string都会从elem指向的string那里接管内存的所有权。
        alloc.construct(dest++, std::move(*elem++));
    }
    // 释放原容器
    free();

    // 重新赋值
    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
}




