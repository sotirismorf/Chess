#ifndef SQUARE_H
#define SQUARE_H

class Square
{
	private:
		int rankNum;
		int fileNum;
		bool color; //0 for white 1 for black

	public:
		Square(int f, int r);

		bool getColor();
};

#endif // SQUARE_H
