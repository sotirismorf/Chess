#include "piece.h"

Piece::Piece(PieceType pieceType, const std::string name)
{
	texture.loadFromFile(name);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.75,0.75);
	this->pieceType = pieceType;

	hovering = false;
	rankNum = fileNum = 0;
	alive = true;
}

//Getters
int Piece::getRank() {return rankNum;}
int Piece::getFile() {return fileNum;}
bool Piece::isAlive() {return alive;}
bool Piece::getHover() {return hovering;}
sf::Sprite Piece::getSprite(){return sprite;}
bool Piece::posEquals(int file, int rank)
{
	return (file == fileNum) && (rank == rankNum);
}

//Setters
void Piece::move(int fileNum, int rankNum)
{
	this->rankNum = rankNum;
	this->fileNum = fileNum;

	sprite.setPosition(fileNum*150,rankNum*150);
}

void Piece::setSpritePos(int x, int y)
{
	sprite.setPosition(x,y);
}

void Piece::setHover(bool h){this->hovering = h;}
void Piece::setStatus(bool alive) {this->alive = alive;}

///==================================

King::King(bool isWhite) : Piece(KING, isWhite ? "assets/white_king.png" : "assets/black_king.png"){}
Queen::Queen(bool isWhite) : Piece(QUEEN, isWhite ? "assets/white_queen.png" : "assets/black_queen.png"){}
Rook::Rook(bool isWhite) : Piece(ROOK, isWhite ? "assets/white_rook.png" : "assets/black_rook.png"){}
Knight::Knight(bool isWhite) : Piece(KNIGHT, isWhite ? "assets/white_knight.png" : "assets/black_knight.png"){}
Bishop::Bishop(bool isWhite) : Piece(BISHOP, isWhite ? "assets/white_bishop.png" : "assets/black_bishop.png"){}
Pawn::Pawn(bool isWhite) : Piece(PAWN, isWhite ? "assets/white_pawn.png" : "assets/black_pawn.png"){}

bool King::canMove(int x, int y){return false;}
bool Queen::canMove(int x, int y){return true;}
bool Rook::canMove(int x, int y){return true;}
bool Knight::canMove(int x, int y){return true;}
bool Bishop::canMove(int x, int y){return true;}
bool Pawn::canMove(int x, int y){return true;}
