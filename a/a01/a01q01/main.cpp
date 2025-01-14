// main.cpp

#include <cstdlib>
#include <ctime>
#include "DiceGame.h"
#include "View.h"

int main() {
    srand((unsigned int)time(NULL));

    DiceGame aDiceGame;
    View aView;
    aDiceGame.play();
    aView.update(aDiceGame);

    return 0;
}
