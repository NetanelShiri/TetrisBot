#pragma once
#include "gotoxy.h"
#include "Point.h"
#include "Tetrominos.h"

class LineShape : public Tetrominos
{

public:

	LineShape();
	LineShape(int _width, char _char);

	virtual void moveTetromino(Direction direction);
	virtual void initTetromino();
	virtual void drawTetromino();
	virtual void RotateCW();

};


