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
    void play() {
        die1.roll();
        die2.roll();
    }
    const Die& getDie1() const { return die1; }
    const Die& getDie2() const { return die2; }
};

#endif
