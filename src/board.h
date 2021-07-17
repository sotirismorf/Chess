#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "piece.h"

class Piece;

class Board
{
	private:
		int squareWidth;
		int boardWidth;
		int hoveringPieceIndex;

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
		void takes(int taken);
		void handleClick(int x, int y);
		void handleClickRelease(int x, int y);
		void drawBoard();
		void gameLoop();
};

#endif // BOARD_H
