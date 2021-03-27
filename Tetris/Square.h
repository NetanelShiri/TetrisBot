#pragma once
#include "Point.h"

class Square {
	enum { SIZE = 4 };
	Point body[SIZE];

	//Color color;
	//char figure;

public:
	void move();
	void init(int width);
	void draw(char ch);


	//void setColor(Color c) {
	//	color = c;
	//}
	//void setFigure(const char c) {
	//	figure = c;
	//}

};



