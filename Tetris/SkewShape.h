#pragma once
#include "gotoxy.h"
#include "Point.h"
#include "Tetrominos.h"

class SkewShape : public Tetrominos
{

public:

	SkewShape();
	SkewShape(int _width, char _char);

	virtual void moveTetromino(Direction direction);
	virtual void initTetromino();
	virtual void drawTetromino();
	virtual void RotateCW();

};


