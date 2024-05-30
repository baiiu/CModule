//
// Created by ByteDance on 2024/5/30.
//

#include "effective35.h"

#include <utility>

class GameCharacter;

int defaultHealthCalc(const GameCharacter &character) { return -1; };

class GameCharacter {
public:
    typedef std::function<int(const GameCharacter &)> HealthCalcFunc;

    explicit GameCharacter(HealthCalcFunc function = defaultHealthCalc) : healthFunc(std::move(function)) {}

    int healthValue() const {
        return healthFunc(*this);
    }

private:
    HealthCalcFunc healthFunc;
};

short calcHealth(const GameCharacter &) { return 1; }

class HealthCalculator {
    int operator()(const GameCharacter &) const {
        return 2;
    }
};

class GameLevel {
public:
    float health(const GameCharacter &) const { return 3; }
};

class EvilBadGuy : public GameCharacter {
};

class EyeCandyCharacter : public GameCharacter {
};


void test35() {
//    EvilBadGuy evilBadGuy(calcHealth);
}