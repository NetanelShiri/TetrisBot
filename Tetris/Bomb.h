#pragma once
#include "Tetrominos.h"

class Bomb : public Tetrominos
{
	RotateDirection rotateDirection = RotateDirection::Up;
	char bombChar = char(233);

public:

	Bomb();
	Bomb(int _width,int _ch);

	virtual void moveTetromino(Direction direction);
	virtual void initTetromino();
	virtual void drawTetromino();
	virtual void RotateCW(int playerBoard[12][18], int distancing);//Rotate the shape clockwise
	virtual void RotateCCW(int playerBoard[12][18], int distancing);//Rotate the shape counterclockwise

};
