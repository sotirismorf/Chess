#include "piece.h"

#include <iostream>

Piece::Piece(PieceType pieceType, bool white, const std::string name)
{
	texture.loadFromFile(name);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.5,0.5);
	this->pieceType = pieceType;

	this->white = white;
	hovering = false;
	rankNum = fileNum = 0;
	alive = true;
}

//Getters
int Piece::getRank() {return rankNum;}
int Piece::getFile() {return fileNum;}
bool Piece::isAlive() {return alive;}
bool Piece::isWhite() {return white;}
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

	sprite.setPosition(fileNum*100,rankNum*100);
}

void Piece::setSpritePos(int x, int y)
{
	sprite.setPosition(x,y);
}

void Piece::setHover(bool h){this->hovering = h;}
void Piece::setStatus(bool alive) {this->alive = alive;}

///==================================

King::King(bool isWhite) : Piece(KING, isWhite, isWhite ? "assets/white_king.png" : "assets/black_king.png"){}
Queen::Queen(bool isWhite) : Piece(QUEEN, isWhite, isWhite ? "assets/white_queen.png" : "assets/black_queen.png"){}
Rook::Rook(bool isWhite) : Piece(ROOK, isWhite, isWhite ? "assets/white_rook.png" : "assets/black_rook.png"){}
Knight::Knight(bool isWhite) : Piece(KNIGHT, isWhite, isWhite ? "assets/white_knight.png" : "assets/black_knight.png"){}
Bishop::Bishop(bool isWhite) : Piece(BISHOP, isWhite, isWhite ? "assets/white_bishop.png" : "assets/black_bishop.png"){}
Pawn::Pawn(bool isWhite) : Piece(PAWN, isWhite, isWhite ? "assets/white_pawn.png" : "assets/black_pawn.png"){}

bool King::canMove(int x, int y, Piece **pieces)
{
	int posx = this->getFile(), posy = this->getRank();
	std::cout << x << " " << y << " " << std::endl;
	std::cout << this->getFile() << " " << y << " " << std::endl;

	if (x==posx && y==posy) return false;

	if (y>=posy-1 && y<=posy+1){
		std::cout << "rank ok" << std::endl;
		if (x>=posx-1 && x<=posx+1) return true;
	}
	else return false;
	return false;
}
bool Queen::canMove(int x, int y, Piece **pieces){return true;}
bool Rook::canMove(int x, int y, Piece **pieces)
{
	if (x == getFile() || y == getRank()) return true;
	else return false;
}
bool Knight::canMove(int x, int y, Piece **pieces){
	return true;
}
bool Bishop::canMove(int x, int y, Piece **pieces){return true;}

bool Pawn::canMove(int x, int y, Piece **pieces)
{
	int rankDiff = y - getRank();
	int fileDiff = x - getFile();
	if (fileDiff>1 || fileDiff<-1){
		return false;
	}
	else if (white){
		if (rankDiff>=0) return false;
		else{
			if (fileDiff==0){
				if (rankDiff == -1) return true;
				if (rankDiff == -2 && getRank() == 6) return true;
				else return false;
			}
			else if (fileDiff==1 || fileDiff== -1){
				if (rankDiff==-1) return true;
				else return false;
			}
			else return false;
		}
	}
	else if (!white){
		if (rankDiff<=0) return false;
		else{
			if (fileDiff==0){
				if (rankDiff == 1) return true;
				if (rankDiff == 2 && getRank() == 1) return true;
				else return false;
			}
			else if (fileDiff==1 || fileDiff== -1){
				if (rankDiff==1) return true;
				else return false;
			}
			else return false;
		}
	}
	return true;
}
