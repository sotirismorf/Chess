#include "piece.h"
#include <iostream>

Piece::Piece(Board *board, bool white, const std::string name)
{
	texture.loadFromFile(name);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.5,0.5);

	this->board = board;

	this->white = white;
	hovering = false;
	rankNum = fileNum = 0;
	alive = true;
}

//Getters
int Piece::getRank() {return rankNum;}
int Piece::getFile() {return fileNum;}
Board *Piece::getBoard(){return board;}
bool Piece::isAlive() {return alive;}
bool Piece::isWhite() {return white;}
bool Piece::getHover() {return hovering;}
sf::Sprite Piece::getSprite(){return sprite;}
bool Piece::posEquals(int file, int rank)
{
	return (file == fileNum) && (rank == rankNum);
}
bool Piece::isPieceBetween(int x, int y)
{
	int minX,maxX,minY,maxY;

	minX = x < getFile() ? x : getFile();
	maxX = x > getFile() ? x : getFile();
	minY = y < getRank() ? y : getRank();
	maxY = y > getRank() ? y : getRank();

	if (minY==maxY){
		for (int i = minX+1; i<maxX; i++)
			if (getBoard()->getPieceOnSquare(i,y)>=0)
				return true;
	}
	else if (minX==maxX){
		for (int i = minY+1; i<maxY; i++)
			if (getBoard()->getPieceOnSquare(x,i)>=0)
				return true;
	}
	else{
		int j=minY+1; int i;
		for (i=minX+1; i<maxX; i++){
			if (getBoard()->getPieceOnSquare(i,j)>=0)
				return true;
			j++;
			}
	}
	return false;
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

King::King(Board *board, bool isWhite) : Piece(board, isWhite, isWhite ? "assets/white_king.png" : "assets/black_king.png"){}
Queen::Queen(Board *board, bool isWhite) : Piece(board, isWhite, isWhite ? "assets/white_queen.png" : "assets/black_queen.png"){}
Rook::Rook(Board *board, bool isWhite) : Piece(board, isWhite, isWhite ? "assets/white_rook.png" : "assets/black_rook.png"){}
Knight::Knight(Board *board, bool isWhite) : Piece(board, isWhite, isWhite ? "assets/white_knight.png" : "assets/black_knight.png"){}
Bishop::Bishop(Board *board, bool isWhite) : Piece(board, isWhite, isWhite ? "assets/white_bishop.png" : "assets/black_bishop.png"){}
Pawn::Pawn(Board *board, bool isWhite) : Piece(board, isWhite, isWhite ? "assets/white_pawn.png" : "assets/black_pawn.png"){}

bool King::canMove(int x, int y)
{
	int posx = this->getFile(), posy = this->getRank();

	if (x==posx && y==posy) return false;

	if (y>=posy-1 && y<=posy+1){
		if (x>=posx-1 && x<=posx+1) return true;
	}
	else return false;
	return false;
}

bool Queen::canMove(int x, int y)
{
	if (x==getFile() || y==getRank() || x-getFile()==y-getRank() || x-getFile()==getRank()-y){
		if (isPieceBetween(x,y)) return false;
		else return true;
	}
	return false;
}

bool Rook::canMove(int x, int y)
{
	if (x == getFile() || y == getRank()){
		if (isPieceBetween(x,y)) return false;
		else return true;
	}
	return false;

}
bool Knight::canMove(int x, int y){
	int rankDiff,fileDiff;
	fileDiff = x-getFile();
	rankDiff = y-getRank();
	if (fileDiff==-2 || fileDiff==2){
		if (rankDiff == -1 || rankDiff == 1)
			return true;
	}
	else if (fileDiff==-1 || fileDiff==1){
		if (rankDiff == -2 || rankDiff == 2)
			return true;
	}
	return false;
}
bool Bishop::canMove(int x, int y)
{
	if (x-getFile()==y-getRank() || x-getFile()==getRank()-y){
		if (isPieceBetween(x,y)) return false;
		else return true;
	}
	return false;
}

bool Pawn::canMove(int x, int y)
{
	int i = getBoard()->getPieceOnSquare(x,y);

	int rankDiff = y - getRank();
	int fileDiff = x - getFile();
	if (fileDiff>1 || fileDiff<-1){
		return false;
	}
	else if (white){
		if (rankDiff>=0) return false;
		else{
			if (fileDiff==0){
				if (rankDiff == -1 && i==-1) return true;
				if (rankDiff == -2 && getRank() == 6 && i==-1) return true;
				else return false;
			}
			else if (fileDiff==1 || fileDiff== -1){
				if (rankDiff==-1 && i>=0) return true;
				else return false;
			}
			else return false;
		}
	}
	else if (!white){
		if (rankDiff<=0) return false;
		else{
			if (fileDiff==0){
				if (rankDiff == 1 && i==-1) return true;
				if (rankDiff == 2 && getRank() == 1 && i==-1) return true;
				else return false;
			}
			else if (fileDiff==1 || fileDiff== -1){
				if (rankDiff==1 && i>=0) return true;
				else return false;
			}
			else return false;
		}
	}
	return true;
}
