#pragma once
#include "gotoxy.h"
#include "Point.h"
#include <vector>
using std::cout;
using std::endl;
using std::cin;

class Tetrominos
{

protected:

	enum { SIZE = 4 };
	enum class RotateDirection { Up, Down, Left, Right }; //current state of the rotation

	Point body[SIZE];
	vector<Point> saveParts;

	int playerWidth = 0;
	char playerChar = ' ';


public:

	virtual ~Tetrominos();

	enum Tetromino { SquareS, LineS, TS, LS, JS, SkewS, RSkewS , BombS};

	virtual void moveTetromino(Direction direction) = 0; //moving shape by direction
	virtual void initTetromino() = 0; //initiallize shape by player starting location
	virtual void drawTetromino() = 0; //drawing the Point* body[4] of the shape
	virtual void RotateCW(int playerBoard[12][18],int distancing) = 0; //rotating Clock-wise
	virtual void RotateCCW(int playerBoard[12][18],int distancing) = 0; //rotating Counter Clock-wise
	
	//check if rotation is legal
	bool checkLegal(vector<Point>& saveParts, int playerBoard[12][18], int distancing);

	void clearBody(); //clear body
	void rainbowBody(); //coloring body
	
	Point* getPoints() { return body; }
	vector<Point> &getSaveParts() { return saveParts; } //used in rotating functions
	int getTetrinomSize() { return int(SIZE); }
;

};