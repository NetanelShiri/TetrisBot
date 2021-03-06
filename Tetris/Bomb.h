#pragma once
#pragma warning( push )
#pragma warning( disable : 6385 )
#pragma warning( disable : 6386 )
#include "Tetrominos.h"

class Bomb : public Tetrominos
{
	enum {   north ,northEast , east ,southEast ,south , southWest ,west , northWest , dirSize};

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
	virtual void initTemporary(int _rotation);

	int suicide(int playerBoard[12][18], int distancing);
	void fixBombedLine(int playerBoard[12][18], int distancing);
};
