//
// Created by ByteDance on 2024/5/28.
//

#include "passByReferenceConst.h"

#include <utility>

class Person {
public:
    Person() = default;
    Person(std::string _name, std::string _address) : name(std::move(_name)), address(std::move(_address)) {};

    Person(std::string _name) : name(std::move(_name)) {};

    virtual ~Person() = default;

    std::string name;
    std::string address;
};

class Student : public Person {
public:
    Student() = default;
    Student(std::string name, std::string schoolName, std::string address) : Person(std::move(name)),
                                                                             schoolName(std::move(schoolName)),
                                                                             schoolAddress(
                                                                                     std::move(address)) {
    };

    ~Student() {};
    std::string schoolName{};
    std::string schoolAddress{};
};

ostream &operator<<(ostream &os, const Student &student) {
    os << &student << ", " << student.name << ", " << student.schoolName << ", " << student.schoolAddress;
    return os;
}

ostream &operator<<(ostream &os, const Person &person) {
    os << &person << ", " << person.name << ", " << person.address;
    return os;
}

void test111(Student student) {
    cout << "test111: " << student << endl;
};

void test222(Person person) {
    cout << "test222: " << person << endl;
};

void test333(const Student &student) {
    cout << "test333: " << student << endl;
};

void test444(const Person &person) {
    cout << "test444: " << person << endl;
};

void testPassByReferenceConst() {
    Student s("xiaoming", "yixiao", "wangfujing");
    cout << "origin student: " << s << endl;

    Person *p = &s; // 对象切割
    cout << "origin person: " << *p << endl;

    Student s1;
    Person p1 = s1;



    test111(s);
    test222(s);
    test333(s);
    test444(s);
}