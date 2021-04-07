#pragma once
#pragma warning( push )
#pragma warning( disable : 26451 )

#include <random>
#include "Point.h"


#include "Tetrominos.h"
#include "SquareShape.h"
#include "LineShape.h"
#include "JShape.h"
#include "LShape.h"
#include "TShape.h"
#include "SkewShape.h"
#include "RSkewShape.h"
using std::vector;

//player board
constexpr size_t minHeight = 0;
constexpr size_t maxHeight = 19;
constexpr size_t minWidth = 0;
constexpr size_t maxWidth = 26;
constexpr size_t middleWidth = 13;
constexpr size_t playerWidth = 6;

class Player {

	enum Tetromino { SquareS, LineS, TS, LS, JS, SkewS, RSkewS };

	//default player settings
	Direction direction = Direction::Down;
	char arrowKeys[5];
	int playerNumber = 0;
	int widthDefault = 0;
	int distancing = 0;
	char playerChar = ' ';
	
	//player score monitor
	int score = 0;


	//player shape control
	Tetrominos* tetromino = nullptr;

	//player board control
	int playerBoard[12][18] = { 0 };
	int shapeNumber = 0;
	int trueWidthToArr = ((playerNumber - 1) * distancing);

public:
	
	bool playerMovement();
	void playerDraw();
	void playerRotateCW();
	void playerRotateCCW();
	void playerInit(char _playerChar,int _width,int _distancing,int _playerNumber,const char _keys[5]);
	

	int randomizer();
	void tetrominoCreator();
	void replaceTetromino();
	//void setArrowKeys(const char* keys); 
	
	char getPlayerChar();
	int getWidthDefault();


	void checkFullLines();
	Direction getDirection(char key);
	Tetrominos* getTetromino()	{return tetromino;}
	void setDirection(Direction direction);

	void PlayerBoardTetroUpdate(int number);
	void drawFromPlayerBoard();
	int getXYFromBoard(int x, int y) { return playerBoard[x][y]; }
	int isLegalMove();
	//int getFigure();//
	//int checkeEndOfBoard(Player player);/////
	//void setFigure();//////
	//int checkLocation();//
	//bool checkFigureLocation();//
};