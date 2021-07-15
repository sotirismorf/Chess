#ifndef PLAYER_H
#define PLAYER_H

#include "piece.h"

class Player
{
private:
	bool color;

public:
	Player(bool color);

	void movePiece(int f, int r, Piece* piece);
};

#endif // PLAYER_H
