#include "gotoxy.h"
#include "Point.h"

void Point::draw() {
	gotoxy(x, y);
	cout << "#" << endl;
}

void Point::move(int dir) {
	switch (dir) {
	
	case 1: // DOWN
		++y;
		if (y == 24) {
			draw();
		}
		break;
	case 2: // LEFT
		--x;
		if (x == 1) {
			draw;
		}
		break;
	case 3: // RIGHT
		++x;
		if (x ==18) {
			draw;
		}
		break;
	}
}