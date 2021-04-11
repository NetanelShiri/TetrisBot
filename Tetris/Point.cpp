#include "gotoxy.h"
#include "Point.h"
#include "Tetris.h"




void Point::draw(char ch) {
	gotoxy(x, y);
	if (mode == 1) { color(ch, colorNum); }
	else if (mode == 2) { color(ch, -1); }
	else { cout << ch << endl; }

}

void Point::move(Direction direction) {
	switch(direction) {
	
	case Direction::Left:
		setX(--x);
		break;
	case Direction::Right: 
		setX(++x);
		break;
	case Direction::Down:
		setY(++y);
		break;
		
	}
}
