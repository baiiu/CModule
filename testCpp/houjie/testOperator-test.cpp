//
// Created by baiiu on 2022/2/9.
//

#include "testOperator.h"

void testOperator() {
    complex a(1, 1);
    complex b(2, 2);

    complex c = a + b;
    c.display();

    a = a + b;
    a.display();

    cout << a << endl;
    cout << a << ", " << b << endl;
}