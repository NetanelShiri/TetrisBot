#pragma once
#include "Point.h"
#include <vector>

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
	virtual void RotateCW(int playerBoard[12][18],int distancing) = 0;
	virtual void RotateCCW(int playerBoard[12][18],int distancing) = 0;

	Point* getPoints();
	int getTetrinomSize();
	bool checkLegal(vector<Point> &save,int playerBoard[12][18], int distancing);

};