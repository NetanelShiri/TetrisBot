#pragma once
#include "Point.h"
#include "Tetrominos.h"


class SquareShape : public Tetrominos {


public:

	SquareShape();
	SquareShape(int _width, char _char);

	virtual void moveTetromino(Direction direction);
	virtual void initTetromino();
	virtual void drawTetromino();

};