#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "board.h"
#include "player.h"

class Game
{
	private:
		int currMove;
		int playerTurn; //0 for white, 1 for black
		pos moves[100][5];

		Player players[2];

		Board *board;
	public:
		Game();
		void takes(int taken);
		void handleClick(int x, int y);
		void handleClickRelease(int x, int y);
};

#endif //GAME_H
