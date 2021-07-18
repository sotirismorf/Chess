#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include "board.h"

enum PieceType {KING,QUEEN,ROOK,KNIGHT,BISHOP,PAWN};

class Board;

class Piece
{
	private:
		//Piece **pieces;
		int rankNum;
		int fileNum;
		bool alive;
		bool hovering;
		Board *board;

		sf::Texture texture;
		sf::Sprite sprite;

	protected:
		PieceType pieceType;
		bool white;

	public:
		//constructor
		Piece(Board *board, bool white, const std::string name);

		//getters
		bool isAlive();
		int getRank();
		int getFile();
		bool getHover();
		Board *getBoard();
		bool isWhite();
		sf::Sprite getSprite();
		bool posEquals(int file, int rank);

		//setters
		void move(int fileNum, int rankNum);
		void setHover(bool h);
		void setSpritePos(int x, int y);
		void setTexture();
		void setStatus(bool alive);

		virtual bool canMove(int x, int y) = 0;
		//Returns 0 if the piece cannot move to the entered position
		//and 1 if it can;
		//virtual bool canMove(int rankNum, int fileNum) = 0;
};

class King : public Piece
{
	public:
		King(Board *board, bool isWhite);
		bool canMove(int x, int y);
};

class Queen : public Piece
{
	public:
		Queen(Board *board, bool isWhite);
		bool canMove(int x, int y);
};

class Rook : public Piece
{
	public:
		Rook(Board *board, bool isWhite);
		bool canMove(int x, int y);

};

class Knight : public Piece
{
	public:
		Knight(Board *board, bool isWhite);
		bool canMove(int x, int y);

};

class Bishop : public Piece
{
	public:
		Bishop(Board *board, bool isWhite);
		bool canMove(int x, int y);

};

class Pawn : public Piece
{
	public:
		Pawn(Board *board, bool isWhite);
		bool canMove(int x, int y);

};


#endif // PIECE_H
