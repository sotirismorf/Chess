#include "piece.h"

Piece::Piece()
{
	rankNum = fileNum = 0;
	alive = true;
}

Piece::~Piece()
{
}

int Piece::getRank() {return rankNum;}

int Piece::getFile() {return fileNum;}

bool Piece::isAlive() {return alive;}

void Piece::movePiece(int rankNum, int fileNum)
{
	this->rankNum = rankNum;
	this->fileNum = fileNum;
}

void Piece::dies() {alive = false;}
