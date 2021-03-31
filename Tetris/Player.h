#pragma once
#include "Point.h"

class Player {


	Direction direction = Down;
	char arrowKeys[5];
	int playerNumber = 0;
	int widthDefault = 0;
	char playerChar = ' ';


	
public:


	void playerInit(char _playerChar,int _width,int _playerNumber,const char _keys[5]);
	//void setArrowKeys(const char* keys); 
	char getPlayerChar();
	int getWidthDefault();



	Direction getDirection(char key);
	void setDirection(Direction direction);
	//int getFigure();//
	//int checkeEndOfBoard(Player player);/////
	//void setFigure();//////
	//int checkLocation();//
	//bool checkFigureLocation();//
};