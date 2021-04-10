#pragma once
#include "gotoxy.h"
#include <iostream>

using namespace std;

enum class Direction {None = -1 , Left , Right , Down , RotateC , RotateCC };

class Point {
	int x = 1, y = 1;
	int colorNum = randomizer(7.0);
public:

	void draw(char ch);
	void move(Direction direction);
	
	void setX(int X) {
		x = X;
	}
	void setY(int Y) {
		y = Y;
	}
	
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}


};

