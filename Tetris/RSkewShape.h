#pragma once
#include "Point.h"

class RSkewShape {
	enum { SIZE = 4 };
	Point body[SIZE];


	int direction = 0;
	int playerWidth;
	char playerChar;

	//Color color;
	//char figure;

public:

	RSkewShape();
	RSkewShape(int _width, char _char);

	void move(Direction direction);
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


