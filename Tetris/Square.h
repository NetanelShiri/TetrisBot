#pragma once
#include "Point.h"

class Square {
	enum { SIZE = 4 };
	Point body[SIZE];
	int direction = 3;
	//char arrowKeys[3];
	//int playerNumber;
	//Color color;
	//char figure;

public:
	//void setArrowKeys(const char* keys); 
	void move();
	//int getDirection(char key);
	//void setDirection(int dir);
	
	//void setColor(Color c) {
	//	color = c;
	//}
	//void setFigure(const char c) {
	//	figure = c;
	//}

	

};

