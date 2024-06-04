//
// Created by baiiu on 2022/2/13.
//

#include "hjString.h"
#include "common.h"

void testString() {
//    String s1;
//    String s2("hello");
//
//    String s3(s2);
//    cout << s3 << endl;
//
//    s1 = s3;
//    cout << s1 << endl;

    vector<String> vec;
    vec.push_back("1"); // String构造函数,String移动构造,String析构函数,String析构函数
    vec.emplace_back("12"); // String构造函数, String析构函数
    vec.emplace_back(String("123")); // String构造函数,String移动构造,String析构函数,String析构函数

    cout << "--------------------" << endl;

    // 添加引用效率高，避免拷贝构造
    for (const String &str : vec) {
        cout << str << endl;
    }

//    int *p = new int(1);
//    delete p;
//    delete p;

}