//
// Created by baiiu on 2021/8/11.
//

#include "testPerson.h"


class Person {
private:
    int mAge;
    mutable int mNumber;
public:
    Person() = default;

    Person(int age, int number) : mAge(age), mNumber(number) {}

    inline // inline，规模较小的函数适合被声明为inline，
    int getAge() const {
//        age = 1;
        return mAge;
    }

    inline
    int getNumber() const {
        return mNumber;
    }

    inline
    Person &age(int age) { // 返回引用，即本身的对象； 不加引用即返回拷贝
        this->mAge = age;
        return *this;
    }

    inline
    Person &number(int number) {
        this->mNumber = number;
        return *this;
    }

    inline
    Person numberCopy(int number) {
        this->mNumber = number;
        return *this;
    }

    inline
    Person *agePointer(int age) { // 返回指针
        this->mAge = age;
        return this;
    }

    inline
    Person *numberPointer(int number) {
        this->mNumber = number;
        return this;
    }

    friend ostream &operator<<(ostream &output, const Person &person) {
        output << "age:" << person.getAge() << ", person: " << person.getNumber();
        return output;
    }
};

void testPerson() {
    Person person{1, 1};
    cout << "person0: " << person << endl;

    person.number(10).age(10);
    cout << "person1: " << person << endl;

//    person.agePointer(20)->numberPointer(20);
//    cout << "person2: " << person << endl;

    Person p = person.numberCopy(30); // 返回拷贝值，对p的修改不会影响person
    p.age(40).number(40);
    cout << "person3: " << person << endl;
    cout << "person_copy3: " << p << endl;
}