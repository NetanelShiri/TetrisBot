#pragma once
#include "Point.h"


class SquareShape {
	enum { SIZE = 4 };
	Point body[SIZE];

	int playerWidth;
	char playerChar;
	
	//Color color;
	//char figure;

public:

	SquareShape();
	SquareShape(int _width, char _char);

	void move(Direction direction);
	void init();
	void draw();


	//void setColor(Color c) {
	//	color = c;
	//}
	//void setFigure(const char c) {
	//	figure = c;
	//}

};



