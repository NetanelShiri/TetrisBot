#pragma once
#include "Point.h"
#include <vector>

class Tetrominos
{

protected:

	enum { SIZE = 4 };
	enum class RotateDirection { Up, Down, Left, Right };////

	Point body[SIZE];
	vector<Point> saveParts;

	int playerWidth = 0;
	char playerChar = ' ';
	COLOR color = COLOR::White;


public:

	virtual ~Tetrominos();

	enum Tetromino { SquareS, LineS, TS, LS, JS, SkewS, RSkewS };

	virtual void moveTetromino(Direction direction) = 0;
	virtual void initTetromino() = 0;
	virtual void drawTetromino() = 0;
	virtual void RotateCW(int playerBoard[12][18],int distancing) = 0;
	virtual void RotateCCW(int playerBoard[12][18],int distancing) = 0;
	
	void clearBody();
	Point* getPoints();
	vector<Point> &getSaveParts() { return saveParts; }
	int getTetrinomSize();
	COLOR getColor() { return color; }
	void setColor(COLOR _color) { color = _color; }
	bool checkLegal(vector<Point> &saveParts,int playerBoard[12][18], int distancing);

};