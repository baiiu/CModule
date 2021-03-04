//
// Created by baiiu on 2021/3/4.
//

#include <iostream>
#include "testVector.h"

#include "vector"

using namespace std;

void testVector() {
//    vector<int> vec(2); // 将从第二个位置开始填充，即默认为{0，0}
    vector<int> vec;


    vec.reserve(2); // 从第0个位置开始填充，
//    vec.resize(2); // size = 2, capacity = 2, 从第2个位置开始填充，默认为{0,0}

    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;

    vec.push_back(1);
    vec.push_back(2);

    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    for (int i = 0; i < vec.size(); ++i) {
        cout << "vec[" << i << "]: " << vec[i] << endl;
    }

    vec.push_back(3);
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    for (int i = 0; i < vec.size(); ++i) {
        cout << "vec[" << i << "]: " << vec[i] << endl;
    }

}