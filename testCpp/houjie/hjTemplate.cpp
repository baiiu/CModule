//
// Created by zhezhu on 2022/2/14.
//

#include <iostream>
#include "hjTemplate.h"

void testTemplate() {
    complex<double> a(1.5, 1.5);
    complex<int> b(1, 1);

    int c = 1, d = 2;
    std::cout << min(c, d) << std::endl;
    std::cout << min(1.0, 2.0) << std::endl;
}