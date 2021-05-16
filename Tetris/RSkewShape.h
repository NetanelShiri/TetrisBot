#pragma once
#include "Tetrominos.h"

class RSkewShape : public Tetrominos
{
	RotateDirection rotateDirection = RotateDirection::Right;

public:

	RSkewShape();
	RSkewShape(int _width, char _char);


	virtual void initTetromino();
	virtual void drawTetromino();
	virtual void RotateCW(int playerBoard[12][18],int distancing);//Rotate the shape clockwise
	virtual void RotateCCW(int playerBoard[12][18],int distancing);//Rotate the shape counterclockwise
	virtual void initTemporary(int _rotation);

};


