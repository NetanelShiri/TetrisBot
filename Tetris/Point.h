#pragma once

#include <iostream>

using namespace std;

class Point {
	int x = 1, y = 1;
public:
	void draw(char ch);
	void move(int direction);
	//void move(int direction);
	void setX(int X) {
		x = X;
	}
	void setY(int Y) {
		y = Y;
	}

};

