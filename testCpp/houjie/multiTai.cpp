//
// Created by baiiu on 2022/2/24.
//

#include "multiTai.h"

enum class shape_type {
    type_circle,
    type_triangle,
    type_rectangle
};

class shape {
public:
    virtual void print() = 0;

    virtual ~shape() {
        cout << "~shape" << endl;
    }
};

class circle : public shape {
    void print() override {
        cout << "圆形" << endl;
    }

    ~circle() override {
        cout << "~circle" << endl;
    }
};

class triangle : public shape {
    void print() override {
        cout << "三角形" << endl;
    }

    ~triangle() override {
        cout << "~triangle" << endl;
    }
};

class rectangle : public shape {
    void print() override {
        cout << "矩形" << endl;
    }

    ~rectangle() override {
        cout << "~rectangle" << endl;
    }
};

shape *create_shape(shape_type type) {
    shape *p;

    switch (type) {
        case shape_type::type_circle:
            p = new circle();
            break;
        case shape_type::type_rectangle:
            p = new rectangle();
            break;
        case shape_type::type_triangle:
            p = new triangle();
            break;
    }

    return p;
}


void testMultiTai() {
    shape *p = create_shape(shape_type::type_circle);
    p->print();
    delete p;
}