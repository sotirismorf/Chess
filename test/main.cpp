#include <iostream>

#include "piece.h"

using namespace std;

int main()
{
	Piece p = Piece();
	cout << p.isAlive() << endl;
	p.dies();
	cout << p.isAlive() << endl;
	return 0;
}
