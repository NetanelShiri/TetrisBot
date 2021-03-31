#include "gotoxy.h"
#include "Point.h"
#include "Tetris.h"

void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch << endl;
}

void Point::move(Direction direction) {
	switch(direction) {
	
	case Left:

		if (y == maxHeight) {
			//--y;
		//	return;
		}
		setX(--x);
		break;
	case Right: 

		if (x == 1) {
			
		}
		setX(++x);
		break;
	case Down:

		if (x ==18) {
			
		}
		setY(++y);
		break;
	}
}