// Player.h

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    void play(DiceGame& diceGame) {
				diceGame.getDie1().roll();
				diceGame.getDie2().roll();
		}
};

#endif
