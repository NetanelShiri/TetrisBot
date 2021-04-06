#pragma once
#include "Point.h"


class Tetrominos
{

protected:

	enum { SIZE = 4 };
	enum class RotateDirection { Up, Down, Left, Right };////

	Point body[SIZE];

	int playerWidth = 0;
	char playerChar = ' ';


public:

	enum Tetromino { SquareS, LineS, TS, LS, JS, SkewS, RSkewS };

	virtual void moveTetromino(Direction direction) = 0;
	virtual void initTetromino() = 0;
	virtual void drawTetromino() = 0;
	virtual void clearBody() = 0;
	virtual void RotateCW() = 0;
	virtual void RotateCCW() = 0;

	Point* getPoints();
	int getTetrinomSize();

};