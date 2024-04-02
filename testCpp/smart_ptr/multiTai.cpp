//
// Created by baiiu on 2022/2/24.
//

#include "multiTai.h"

enum class shape_type {
    type_circle,
    type_triangle,
    type_rectangle
};

class Shape {
public:
    virtual void print() = 0;

    virtual ~Shape() {
        cout << "~Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void print() override {
        cout << "圆形" << endl;
    }

    ~Circle() override {
        cout << "~Circle" << endl;
    }
};

class Triangle : public Shape {
public:
    void print() override {
        cout << "三角形" << endl;
    }

    ~Triangle() override {
        cout << "~Triangle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void print() override {
        cout << "矩形" << endl;
    }

    ~Rectangle() override {
        cout << "~Rectangle" << endl;
    }
};

Shape *create_shape(shape_type type) {
    Shape *p;

    switch (type) {
        case shape_type::type_circle:
            p = new Circle();
            break;
        case shape_type::type_rectangle:
            p = new Rectangle();
            break;
        case shape_type::type_triangle:
            p = new Triangle();
            break;
    }

    return p;
}

static void test01() {
    Shape *p = create_shape(shape_type::type_circle);
    p->print();
    delete p;
    p = nullptr;
}

void testMultiTai() {
//    test01();
    smart_shared_ptr<Circle> p1(new Circle());
    smart_shared_ptr<Circle> p2 = p1;
    smart_shared_ptr<Circle> p3 = p1;
    p2 = p1;
    p1->print();
    p2->print();
    p3->print();
    cout << "p2: " << p2.use_count() << ", " << p3.use_count() << endl;

    
}