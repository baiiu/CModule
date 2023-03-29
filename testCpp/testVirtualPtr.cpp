//
// Created by ByteDance on 2023/3/29.
//

#include "testVirtualPtr.h"

#pragma pack(4)

typedef void (*Fun)();

class Base {
public:
    virtual void f() {
        cout << "Base::f()" << endl;
    }

    virtual void g() {
        cout << "Base::g()" << endl;
    }

    virtual void h() {
        cout << "Base::h()" << endl;
    }

    void display() {
        cout << "x=" << x << endl;
    }

    int x = 0;
};

void testVirtualPtr() {
    // 如果对象的地址和x的地址相同，那么就意味着编译器把虚函数表放在了末尾
    // 如果两个地址不同，那么就意味着虚函数表是放在最前面的。
    Base *p = new Base;
    cout << "p=" << p << endl;
    cout << "&p->data=" << &p->x << endl; // 相差size_t个字节，一个指针的长度，说明编译期把虚函数表是放在了最前面

    Base a;
    cout << "sizeof(a): " << sizeof(a) << endl;
    cout << "sizeof(void*): " << sizeof(void *) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(long): " << sizeof(long) << endl;
    cout << "sizeof(size_t): " << sizeof(size_t) << endl;
    cout << "==========================================" << endl;

    /*
     32 位系统下，指针也是 32 位的，4个字节。
     64 位系统下，指针也是 64 位的，8个字节。

     如果是在32位系统下，没事。
     倘若在 64 位系统下，将指针强制转换成 unsigned int 类型，会导致精度丢失，进行编译时编译器会报错。
     （因此如果要进行这样的强转操作，应该改成 long 或者unsigned long）

     在32位系统中size_t是4字节的，在64位系统中，size_t是8字节的，这样利用该类型可以增加程序移植性。
     */

    // 先取得a的地址，并强转为指针类型
    size_t *a_intp = (size_t *) &a;
    cout << "a_intp: " << a_intp << ", IsValidPtr=" << IsValidPtr(a_intp) << endl;

    // 即从首地址开始的4个字节数据，存到一个int里
    size_t vptr_int = *(a_intp);
    cout << "vptr_int: " << vptr_int << ", IsValidPtr=" << IsValidPtr(&vptr_int) << endl;
    // 把这个int转化为指针，再取值，才能得到vtable。
    size_t *vptr = (size_t *) (vptr_int);
    cout << "vptr: " << vptr << ", IsValidPtr=" << IsValidPtr(vptr) << endl;

    // 由于vptr是int*类型，取值只能取得int类型，所以我们得到的函数指针被存进了一个int:
    size_t funcF_int = *(vptr);
    Fun funcF = (Fun) (funcF_int);
    cout << "funcF_int: " << funcF_int << ", IsValidPtr=" << IsValidPtr(&funcF) << endl;
    funcF();

    size_t funcG_int = *(vptr + 1);
    Fun funcG = (Fun) (funcG_int);
    cout << "funcG_int: " << funcG_int << ", IsValidPtr=" << IsValidPtr(&funcG)<< endl;
    funcG();

    size_t funcH_int = *(vptr + 2);
    Fun funcH = (Fun) (funcH_int);
    cout << "funcH_int: " << funcH_int << ", IsValidPtr=" << IsValidPtr(&funcH)<< endl;
    funcH();

    cout << "==========================================" << endl;

    Fun pf = (Fun) *((size_t *) *((size_t *) (&a)));
    Fun pg = (Fun) *((size_t *) *((size_t *) (&a)) + 1);
    Fun ph = (Fun) *((size_t *) *((size_t *) (&a)) + 2);
    pf();
    pg();
    ph();

    cout << "==========================================" << endl;
}