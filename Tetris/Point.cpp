#include "gotoxy.h"
#include "Point.h"
#include "Tetris.h"

void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch << endl;
}

void Point::move(int dir) {
	switch (dir) {
	
	case 0: // DOWN
		++y;
		if (y == maxHeight) {
			//--y;
		//	return;
		}
		setY(y);
		break;
	case 1: // LEFT
		--x;
		if (x == 1) {
			
		}
		setX(x);
		break;
	case 2: // RIGHT
		++x;
		if (x ==18) {
			
		}
		setX(x);
		break;
	}
}