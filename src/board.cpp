#include "board.h"
#include "square.h"
#include <iostream>

Board::Board()
{
	//Initialising the window
	window.create(sf::VideoMode(1200, 1200), "Chess");

	//Loading all the textures
	boardTexture.loadFromFile("assets/board1.png");

	//Setting up the board sprite
	boardSprite.setTexture(boardTexture);

	pieces = new Piece*[32];

	hoveringPieceIndex = -1;
}

void Board::setPieces()
{
	pieces[0] = new King(true);
	pieces[1] = new Queen(true);
	pieces[2] = new Rook(true);
	pieces[3] = new Rook(true);
	pieces[4] = new Knight(true);
	pieces[5] = new Knight(true);
	pieces[6] = new Bishop(true);
	pieces[7] = new Bishop(true);
	for (int i=8;i<16;i++) pieces[i] = new Pawn(true);

	pieces[16] = new King(false);
	pieces[17] = new Queen(false);
	pieces[18] = new Rook(false);
	pieces[19] = new Rook(false);
	pieces[20] = new Knight(false);
	pieces[21] = new Knight(false);
	pieces[22] = new Bishop(false);
	pieces[23] = new Bishop(false);
	for (int i=24;i<32;i++) pieces[i] = new Pawn(false);
}

void Board::setStartingPosition()
{
	pieces[0]->move(4,7);
	pieces[1]->move(3,7);
	pieces[2]->move(0,7);
	pieces[3]->move(7,7);
	pieces[4]->move(1,7);
	pieces[5]->move(6,7);
	pieces[6]->move(2,7);
	pieces[7]->move(5,7);
	for (int i=0;i<8;i++) pieces[8+i]->move(i,6);

	pieces[16]->move(4,0);
	pieces[17]->move(3,0);
	pieces[18]->move(0,0);
	pieces[19]->move(7,0);
	pieces[20]->move(1,0);
	pieces[21]->move(6,0);
	pieces[22]->move(2,0);
	pieces[23]->move(5,0);
	for (int i=0;i<8;i++) pieces[24+i]->move(i,1);
}

void Board::drawBoard()
{
	window.draw(boardSprite);
	for (int i=0;i<32;i++){
		window.draw(pieces[i]->getSprite());
		if (hoveringPieceIndex>=0)
			window.draw(pieces[hoveringPieceIndex]->getSprite());
	}
}

int Board::getPieceOnSquare(int file, int rank)
{
	for (int i=0;i<32;i++)
		if (pieces[i]->posEquals(file,rank)) return i;
	return -1;
}


void Board::handleClick(int x, int y)
{
	int rank, file, index;
	file = x/150;
	rank = y/150;

	index = getPieceOnSquare(file,rank);
	if (index>=0){
		pieces[index]->setHover(true);
		hoveringPieceIndex = index;
	}
}

void Board::handleClickRelease(int x, int y)
{
	int rank, file;
	file = x/150;
	rank = y/150;

	if (hoveringPieceIndex>=0){
		if (pieces[hoveringPieceIndex]->canMove(file,rank)){
			pieces[hoveringPieceIndex]->move(file,rank);
			pieces[hoveringPieceIndex]->setHover(false);
			hoveringPieceIndex = -1;
		}
		else {
			int i = hoveringPieceIndex;
			pieces[i]->move(pieces[i]->getFile(),pieces[i]->getRank());
			hoveringPieceIndex = -1;
		}
	}


}

void Board::gameLoop()
{
	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::MouseButtonPressed){
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				handleClick(pos.x, pos.y);
			}
			if (event.type == sf::Event::MouseButtonReleased){
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				handleClickRelease(pos.x, pos.y);
			}
        }

		if (hoveringPieceIndex>=0){
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			pieces[hoveringPieceIndex]->setSpritePos(pos.x-75,pos.y-75);
		}

        window.clear();
		drawBoard();
        window.display();
    }
}
