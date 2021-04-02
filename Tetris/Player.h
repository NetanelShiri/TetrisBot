#pragma once

#include <random>
#include "Point.h"

#include "Tetrominos.h"
#include "SquareShape.h"
#include "LineShape.h"



class Player {

	enum Tetromino { SquareS, LineS, TS, LS, JS, SkewS, RSkewS };

	//default
	Direction direction = Direction::Down;
	char arrowKeys[5];
	int playerNumber = 0;
	int widthDefault = 0;
	char playerChar = ' ';

	Tetrominos* tetromino = nullptr;
	
public:

	void playerMovement();
	void playerDraw();
	void playerInit(char _playerChar,int _width,int _playerNumber,const char _keys[5]);

	int randomizer();
	void tetrominoCreator();
	//void setArrowKeys(const char* keys); 
	
	char getPlayerChar();
	int getWidthDefault();



	Direction getDirection(char key);
	Tetrominos* getTetromino()
	{
		return tetromino;
	}
	void setDirection(Direction direction);
	//int getFigure();//
	//int checkeEndOfBoard(Player player);/////
	//void setFigure();//////
	//int checkLocation();//
	//bool checkFigureLocation();//
};