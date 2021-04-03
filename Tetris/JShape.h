#pragma once
#include "gotoxy.h"
#include "Point.h"
#include "Tetrominos.h"

class JShape : public Tetrominos
{
	RotateDirection rotateDirection = RotateDirection::Up;

public:

	JShape();
	JShape(int _width, char _char);

	virtual void moveTetromino(Direction direction);
	virtual void initTetromino();
	virtual void drawTetromino();
	virtual void RotateCW();//Rotate the shape clockwise
	virtual void RotateCCW();//Rotate the shape counterclockwise
	virtual void clearBody();////


};

