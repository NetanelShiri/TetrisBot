#pragma once

#include <iostream>

using namespace std;

enum Direction {None = -1 , Left , Right , Down};

class Point {
	int x = 1, y = 1;
public:
	void draw(char ch);
	void move(Direction direction);
	
	void setX(int X) {
		x = X;
	}
	void setY(int Y) {
		y = Y;
	}

};

