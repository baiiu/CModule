//
// Created by ByteDance on 2023/3/29.
//

#include <unistd.h>
#include <fcntl.h>
#include <mach/arm/vm_param.h>
#include "testSize.h"

void testSizeOf() {

    cout << "test:" << sizeof(bool) << endl;
    cout << "test:" << sizeof(void *) << endl;
    cout << "test:" << sizeof(string) << endl;

    std::string str = "123";
    cout << "test:" << sizeof(str) << ", " << str.size() << endl;
}

class InnerA {
public:
    InnerA() {}
};


class Test {
public:
    Test() {}

    InnerA *innerA;
};

void testSize() {
//    std::string str = "123";
//    void *strPtr = *reinterpret_cast<void **>(&str);
//    cout << "strPtrIsValid:" << IsValidPtr(strPtr) << endl;

    Test test;
    test.innerA = new InnerA();

    void *testPtr = *reinterpret_cast<void **>(&test);
    cout << "&test: " << &test << ", \n";
    cout << "testPtr: " << testPtr << ", \n";
    cout << "&testPtr: " << &testPtr << ", \n";
    cout << "testPtrIsValid:" << IsValidPtr(&test) << endl;
    cout << "testPtrIsValid:" << IsValidPtr(testPtr) << endl;
    cout << "testPtrIsValid:" << IsValidPtr(&testPtr) << endl;

//    void *innerAPtr = *reinterpret_cast<void **>(&test.innerA);
//    cout << "testPtrIsValid:" << IsValidPtr(innerAPtr) << endl;

//    testSizeOf();
}




bool isValidAddress(void* ptr) {
    int fd = open("/proc/self/maps", O_RDONLY);
    if (fd < 0) {
        return false;
    }

    char buf[PATH_MAX];
    sprintf(buf, "/proc/self/mem");

    FILE* fp = fopen(buf, "r");
    if (fp == nullptr) {
        close(fd);
        return false;
    }

    uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
    uintptr_t pageStart = addr & ~(PAGE_SIZE - 1);
    uintptr_t pageOffset = addr - pageStart;

    bool result = false;
    char line[PATH_MAX];
    while (fgets(line, PATH_MAX, fp)) {
        uintptr_t start, end;
        if (sscanf(line, "%lx-%lx", &start, &end) == 2) {
            if (pageStart >= start && pageStart < end) {
                // 找到了所在的内存区域，将文件指针定位到该区域的起始地址
                off_t offset = lseek(fd, start, SEEK_SET);
                if (offset == -1) {
                    break;
                }

                // 读取内存区域的数据
                char* data = new char[PAGE_SIZE];
                ssize_t size = read(fd, data, PAGE_SIZE);
                if (size != PAGE_SIZE) {
                    delete[] data;
                    break;
                }

                // 判断指针是否有效
                uintptr_t* p = reinterpret_cast<uintptr_t*>(data + pageOffset);
                result = (*p != 0);
                delete[] data;

                break;
            }
        }
    }

    fclose(fp);
    close(fd);

    return result;
}
bool isAndroidValidPtr(void* ptr) {
    if (ptr == nullptr) {
        return false;
    }

    // 获取指针所在的内存页的起始地址
    uintptr_t pageStart = reinterpret_cast<uintptr_t>(ptr) & ~(PAGE_SIZE - 1);

    // 计算指针所在的内存页的结束地址
    uintptr_t pageEnd = pageStart + PAGE_SIZE;

    // 获取指针所在的对象的虚拟表指针
    uintptr_t* vtablePtr = *reinterpret_cast<uintptr_t**>(ptr);

    // 判断虚拟表指针是否在内存页范围内
    if (vtablePtr < reinterpret_cast<uintptr_t*>(pageStart) ||
        vtablePtr >= reinterpret_cast<uintptr_t*>(pageEnd)) {
        return false;
    }

    // 判断虚拟表指针是否为有效地址
    if (!isValidAddress(reinterpret_cast<void*>(vtablePtr))) {
        return false;
    }

    return true;
}
