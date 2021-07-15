#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>

enum PieceType {KING,QUEEN,ROOK,KNIGHT,BISHOP,PAWN};

class Piece
{
	private:
		int rankNum;
		int fileNum;
		bool alive;
		bool hovering;
		sf::Texture texture;
		sf::Sprite sprite;

	protected:
		PieceType pieceType;
		bool isWhite;

	public:
		//constructor
		Piece(PieceType pieceType, const std::string name);

		//getters
		bool isAlive();
		int getRank();
		int getFile();
		bool getHover();
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
		King(bool isWhite);
		bool canMove(int x, int y);
};

class Queen : public Piece
{
	public:
		Queen(bool isWhite);
		bool canMove(int x, int y);
};

class Rook : public Piece
{
	public:
		Rook(bool isWhite);
		bool canMove(int x, int y);

};

class Knight : public Piece
{
	public:
		Knight(bool isWhite);
		bool canMove(int x, int y);

};

class Bishop : public Piece
{
	public:
		Bishop(bool isWhite);
		bool canMove(int x, int y);

};

class Pawn : public Piece
{
	public:
		Pawn(bool isWhite);
		bool canMove(int x, int y);
		
};


#endif // PIECE_H
