#include "board.h"
#include <iostream>

Board::Board()
{
	//Initialising the window
	squareWidth = 100;
	boardWidth = squareWidth*8;
	window.create(sf::VideoMode(boardWidth, boardWidth), "Chess");
	window.setFramerateLimit(60);

	//Loading all the textures
	boardTexture.loadFromFile("assets/board1.png");

	//Setting up the board sprite
	boardSprite.setTexture(boardTexture);
	boardSprite.scale((float)boardWidth/1200,(float)boardWidth/1200);

	pieces = new Piece*[32];

	hoveringPieceIndex = -1;
}

void Board::setPieces()
{
	pieces[0] = new King(this,true);
	pieces[1] = new Queen(this,true);
	pieces[2] = new Rook(this,true);
	pieces[3] = new Rook(this,true);
	pieces[4] = new Knight(this,true);
	pieces[5] = new Knight(this,true);
	pieces[6] = new Bishop(this,true);
	pieces[7] = new Bishop(this,true);
	for (int i=8;i<16;i++) pieces[i] = new Pawn(this,true);

	pieces[16] = new King(this,false);
	pieces[17] = new Queen(this,false);
	pieces[18] = new Rook(this,false);
	pieces[19] = new Rook(this,false);
	pieces[20] = new Knight(this,false);
	pieces[21] = new Knight(this,false);
	pieces[22] = new Bishop(this,false);
	pieces[23] = new Bishop(this,false);
	for (int i=24;i<32;i++) pieces[i] = new Pawn(this,false);
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
		if (pieces[i]->isAlive())
			window.draw(pieces[i]->getSprite());
		if (hoveringPieceIndex>=0)
			window.draw(pieces[hoveringPieceIndex]->getSprite());
	}
}

int Board::getPieceOnSquare(int file, int rank)
{
	for (int i=0;i<32;i++){
		if (pieces[i]->posEquals(file,rank)) return i;
	}
	return -1;
}

void Board::takes(int taken)
{
	int x = pieces[taken]->getFile();
	int y = pieces[taken]->getRank();
	pieces[hoveringPieceIndex]->move(x,y);
	pieces[hoveringPieceIndex]->setHover(false);

	pieces[taken]->move(-1,-1);

	pieces[taken]->setStatus(false);
}

void Board::handleClick(int x, int y)
{
	int rank, file, index;
	file = x/squareWidth;
	rank = y/squareWidth;

	index = getPieceOnSquare(file,rank);
	if (index>=0){
		pieces[index]->setHover(true);
		hoveringPieceIndex = index;
	}
}

void Board::handleClickRelease(int x, int y)
{
	int rank, file, i;
	file = x/squareWidth;
	rank = y/squareWidth;
	i = getPieceOnSquare(file,rank);

	if (hoveringPieceIndex>=0){
		if (pieces[hoveringPieceIndex]->canMove(file,rank)){
			if (i<0){
				pieces[hoveringPieceIndex]->move(file,rank);
				pieces[hoveringPieceIndex]->setHover(false);
			}
			else if (i>=0){
				if (pieces[i]->isWhite() != pieces[hoveringPieceIndex]->isWhite()){
					takes(i);
				}
				else{
					int i = hoveringPieceIndex;
					pieces[i]->move(pieces[i]->getFile(),pieces[i]->getRank());
				}
			}
		}
		else{
			int i = hoveringPieceIndex;
			pieces[i]->move(pieces[i]->getFile(),pieces[i]->getRank());
		}
	}
	hoveringPieceIndex = -1;
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
			pieces[hoveringPieceIndex]->setSpritePos(pos.x-squareWidth/2,pos.y-squareWidth/2);
		}

        window.clear();
		drawBoard();
        window.display();
    }
}
