#pragma once
#include "gotoxy.h"
#include "Square.h"
#include "Tetris.h"
#include <process.h>
#include <conio.h>
using std::cout;
using std::endl;
using std::cin;

class LineShape {
	enum { SIZE = 4 };
	Point body[SIZE];


	int direction = 0;
	int playerWidth;
	char playerChar;

	//Color color;
	//char figure;

public:

	LineShape();
	LineShape(int _width, char _char);

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


