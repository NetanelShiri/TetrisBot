#pragma once
#include "gotoxy.h"
#include <iostream>
using namespace std;

constexpr size_t minHeight = 0;
constexpr size_t maxHeight = 19;
constexpr size_t minWidth = 0;
constexpr size_t maxWidth = 26;
constexpr size_t middleWidth = 13;
constexpr size_t playerWidth = 6;

enum class Direction {None = -1 , Left , Right , Down , RotateC , RotateCC };

class Point {
	int x = 1, y = 1;
	int colorNum = 0;
public:

	void draw(char ch);
	void move(Direction direction);
	
	void setX(int X) { x = X; }
	void setY(int Y) { y = Y; }
	
	int getX() { return x; }
	int getY() { return y; }

	int getColor() { colorNum; }
	void setColor(int _colorNum) { colorNum = _colorNum; }

};

