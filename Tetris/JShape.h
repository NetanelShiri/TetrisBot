#pragma once

#pragma once
#include "Point.h"
#include "gotoxy.h"
#include "Square.h"
#include "Tetris.h"
#include <process.h>
#include <conio.h>
using std::cout;
using std::endl;
using std::cin;


class JShape {
	enum { SIZE = 4 };
	Point body[SIZE];


	int direction = 0;
	int playerWidth;
	char playerChar;

	//Color color;
	//char figure;

public:

	JShape();
	JShape(int _width, char _char);

	void move();
	void init();
	void draw();

	void setDirection(int _direction)
	{
		this->direction = _direction;
	}
	//void setColor(Color c) {
	//	color = c;
	//}
	//void setFigure(const char c) {
	//	figure = c;
	//}

};


