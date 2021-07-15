#include <SFML/Graphics.hpp>
#include <iostream>

#include "board.h"
#include "piece.h"
#include "player.h"

int main()
{
	//Setting up the board;
	Board board;
	board.setPieces();
	board.setStartingPosition();
	board.gameLoop();
    return 0;
}
