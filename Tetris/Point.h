#pragma once

#include <iostream>

using namespace std;

class Point {
	int x = 1, y = 1;
public:
	void draw();

	void move(int direction);
};

