//
// Created by baiiu on 2021/8/10.
//

#include "testConstructor.h"

int Person::count3 = 10;

void testPerson(Person person) {
    cout << "testPerson: " << person.getMember() << endl;
}

Person getPerson2() {
    return 10; // 拷贝初始化
}

void testConstructor() {
//    Person a = Person(10);
//    Person a1 = a;
//
//    Person a2 = Person(a);


    const int length = 2;
    Person arr[length];
    for (int i = 0; i < length; ++i) {
        // 无
        cout << arr[i].getMember() << endl;
    }

    for (Person p : arr) {
        // 调用拷贝构造函数
    }

    for (const Person &p : arr) {
        // 无
    }



//    Person person(10); // 调用构造函数a
//    Person person2(); // Empty parentheses interpreted as a function declaration
//
//    Person person1 = 10; // 调用构造函数a
//    testPerson(person1); // 调用拷贝构造函数
//
//    testPerson(10); // 调用构造函数a
//    getPerson2(); // 调用构造函数a
//
//    person = person1; // 调用拷贝运算符
//
//    cout << person.getMember() << endl;
//
//    ConstRef ref(10);
//    ConstRef ref2(2);


//    ref = ref2;
//
//    string dots(10, ','); // 直接初始化
//    string s(dots);            // 直接初始化
//    string s2 = dots;          // 直接初始化
//    string null_book = "123";  // 拷贝初始化
//    string null_book2 = string(10, ','); // 拷贝初始化
//
//    testPerson(Person(10)); // 拷贝初始化
//
//    std::vector<Person> vec;
//    vec.push_back(Person(1, 2));
//    cout << "----" << endl;
//    vec.emplace_back(Person(1, 2));
//    cout << "----" << endl;
//    vec.emplace_back(1, 2);


}