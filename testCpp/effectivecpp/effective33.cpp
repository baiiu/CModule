//
// Created by ByteDance on 2024/5/29.
//

#include "effective33.h"

class Base {
private:
    int x;
public:
    virtual void mf1() = 0;

    virtual void mf1(int) {};

    virtual void mf2() {};

    void mf3() { cout << "Base mf3" << endl; };

    void mf3(double) { cout << "Base mf3 double" << endl; };;
};

class Derived : public Base {
public:
    virtual void mf1() {};

    void mf3() { cout << "Derived mf3" << endl; };

    void mf4() { cout << "Derived mf4" << endl; };
};

void test33() {
    Derived d;
    d.mf1();
    // d.mf1(1); // Too many arguments to function call, expected 0, have 1; did you mean 'Base::mf1'?
    d.Base::mf1(1);

    d.mf2();
    d.mf3();
    // d.mf3(1); // Too many arguments to function call, expected 0, have 1; did you mean 'Base::mf3'?
    d.Base::mf3(1);

    Base *pb = &d;
    pb->mf3();

    Derived *pd = &d;
    pd->mf3();
}