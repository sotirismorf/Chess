#include "square.h"

Square::Square(int f, int r){
	fileNum = f;
	rankNum = r;
	if ( (r+f)%2 == 0 ) color = 1;
}

bool Square::getColor() {return color;}
