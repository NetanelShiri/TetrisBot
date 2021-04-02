#include "gotoxy.h"
#include "Point.h"
#include "Tetris.h"

void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch << endl;
}

void Point::move(Direction direction) {
	switch(direction) {
	
	case Direction::Left:

		if (y == maxHeight) {
			//--y;
		//	return;
		}
		setX(x-2);
		break;
	case Direction::Right: 

		if (x == 1) {
			
		}
		setX(x+2);
		break;
	case Direction::Down:

		if (x ==18) {
			
		}
		setY(++y);
		break;
	}
}