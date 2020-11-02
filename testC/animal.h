//
// Created by baiiu on 2020/11/2.
//

#ifndef TESTC_ANIMAL_H
#define TESTC_ANIMAL_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


struct Animal {
    char name[20];

    void (*speak)();
};


struct Cat {
//    struct Animal base;
};

struct Dog {
//    struct Animal base;
};


void testAnimal();

#endif //TESTC_ANIMAL_H
