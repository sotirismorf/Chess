#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "square.h"
#include "piece.h"

class Board
{
	private:
		int hoveringPieceIndex;
		Square ***squares;
		Piece **pieces;

		sf::RenderWindow window;
		sf::Texture boardTexture;
		sf::Texture pieceTextures[12];
		sf::Sprite boardSprite;

	public:
		Board();

		//Getters
		int getPieceOnSquare(int file, int rank);

		//Setters
		void setPieces();
		void setStartingPosition();

		//
		void handleClick(int x, int y);
		void handleClickRelease(int x, int y);
		void drawBoard();
		void gameLoop();
};

#endif // BOARD_H
