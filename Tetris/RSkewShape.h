#pragma once
#include "gotoxy.h"
#include "Point.h"
#include "Tetrominos.h"

class RSkewShape : public Tetrominos
{
	RotateDirection rotateDirection = RotateDirection::Right;

public:

	RSkewShape();
	RSkewShape(int _width, char _char);

	virtual void moveTetromino(Direction direction);
	virtual void initTetromino();
	virtual void drawTetromino();
	virtual void RotateCW();//Rotate the shape clockwise
	virtual void RotateCCW();//Rotate the shape counterclockwise
	virtual void clearBody();

};


