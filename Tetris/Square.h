#pragma once
#include "Point.h"


class Square {
	enum { SIZE = 4 };
	Point body[SIZE];


	int direction = 0;
	int playerWidth;
	char playerChar;
	
	//Color color;
	//char figure;

public:

	Square();
	Square(int _width, char _char);

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



