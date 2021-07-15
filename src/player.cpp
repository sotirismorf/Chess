#include "player.h"
#include "piece.h"

Player::Player(bool color)
{
	this->color = color;
}

void Player::movePiece(int f, int r, Piece* piece)
{
	piece->move(f,r);

}
