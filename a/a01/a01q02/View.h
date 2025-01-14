// View.h

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "DiceGame.h"

class View {
public:
    void update(DiceGame& diceGame) {
        int die1 = diceGame.getDie1().getFaceValue(); 
        int die2 = diceGame.getDie2().getFaceValue();

        int sum = die1 + die2;

				std::cout <<  "Dice  : " << die1 << ", " << die2 << std::endl;
				std::cout << "Sum   : " << sum << std::endl;
				std::cout  << "Result: " << ((sum == 7) ? "won" : "lost") << std::endl;
    }
};

#endif
