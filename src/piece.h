#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>

enum PieceType {KING,QUEEN,ROOK,KNIGHT,BISHOP,PAWN};

class Piece
{
	private:
		//Piece **pieces;
		int rankNum;
		int fileNum;
		bool alive;
		bool hovering;

		sf::Texture texture;
		sf::Sprite sprite;

	protected:
		PieceType pieceType;
		bool white;

	public:
		//constructor
		Piece(PieceType pieceType, bool white, const std::string name);

		//getters
		bool isAlive();
		int getRank();
		int getFile();
		bool getHover();
		bool isWhite();
		sf::Sprite getSprite();
		bool posEquals(int file, int rank);

		//setters
		void move(int fileNum, int rankNum);
		void setHover(bool h);
		void setSpritePos(int x, int y);
		void setTexture();
		void setStatus(bool alive);

		virtual bool canMove(int x, int y, Piece **pieces) = 0;
		//Returns 0 if the piece cannot move to the entered position
		//and 1 if it can;
		//virtual bool canMove(int rankNum, int fileNum) = 0;
};

class King : public Piece
{
	public:
		King(bool isWhite);
		bool canMove(int x, int y, Piece **pieces);
};

class Queen : public Piece
{
	public:
		Queen(bool isWhite);
		bool canMove(int x, int y, Piece **pieces);
};

class Rook : public Piece
{
	public:
		Rook(bool isWhite);
		bool canMove(int x, int y, Piece **pieces);

};

class Knight : public Piece
{
	public:
		Knight(bool isWhite);
		bool canMove(int x, int y, Piece **pieces);

};

class Bishop : public Piece
{
	public:
		Bishop(bool isWhite);
		bool canMove(int x, int y, Piece **pieces);

};

class Pawn : public Piece
{
	public:
		Pawn(bool isWhite);
		bool canMove(int x, int y, Piece **pieces);

};


#endif // PIECE_H
