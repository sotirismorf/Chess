#ifndef PIECE_H
#define PIECE_H

enum PieceType {PAWN,BISHOP,KNIGHT,ROOK,QUEEN,KING};

class Piece
{
	private:
		int rankNum;
		int fileNum;
		bool alive;

	protected:
		int pieceType;

	public:
		Piece();
		virtual ~Piece();
		bool isAlive();
		int getRank();
		int getFile();
		void movePiece(int rankNum, int fileNum);
		void dies();
};


#endif // PIECE_H
