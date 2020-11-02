//
// Created by baiiu on 2020/11/2.
//

#include "animal.h"


void Animal(struct Animal *animal, const char *name, void (*fun)()) {
    strcpy(animal->name, name);
    animal->speak = fun;
}

void catSpeak() {
    printf("miao miao miao miao miao");
}

void Cat(struct Cat *cat) {
    Animal((struct Animal *) cat, "cat", catSpeak);
}


void dogSpeak() {
    printf("wang wang wang wang wang");
}

void Dog(struct Dog *dog) {
    Animal((struct Animal *) dog, "dog", dogSpeak);
}

void introduce(struct Animal *animal) {
    printf("this animal is: %s; speak is: ", animal->name);

    if (animal->speak) {
        animal->speak();
    } else {
        printf("no speak");
    }

}


void test() {
    struct Animal animal;
    strcpy(animal.name, "123");
    animal.speak = NULL;
    introduce(&animal);
}

void testExtend() {
    struct Cat white_cat;
    struct Animal *p = (struct Animal *) &white_cat;
    p->speak = NULL;
    introduce(p);
}

void testFunc() {
    struct Cat whiteCat;
    Cat(&whiteCat);
    introduce((struct Animal *) &whiteCat);

    printf("\n");

    struct Dog dog;
    Dog(&dog);
    introduce((struct Animal *) &dog);
}


/*
 * https://zhuanlan.zhihu.com/p/25127633
 */
void testAnimal() {

//    test();
//    testExtend();
    testFunc();
}