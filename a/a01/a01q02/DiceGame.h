// DiceGame.h

#ifndef DICEGAME_H
#define DICEGAME_H

#include <cstdlib> // For rand()

class Die {
private:
    int faceValue;
public:
    Die() : faceValue(1) {}
    int getFaceValue() const { return faceValue; }
    void roll() { faceValue = rand() % 6 + 1; }
};

class DiceGame {
private:
    Die die1;
    Die die2;
public:
    Die& getDie1() { return die1; }
    Die& getDie2() { return die2; }
};

#endif
