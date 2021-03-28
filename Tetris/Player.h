#pragma once
#include "Figure.h"

class Player {


	int direction = 3;
	char arrowKeys[5];
	int playerNumber = 0;
	int widthDefault = 0;
	char playerChar = ' ';

	Square* square;

	
public:

	void playerInit(char _playerChar,int _width,int _playerNumber,const char _keys[5]);
	//void setArrowKeys(const char* keys); 

	Square& getSquare()
	{
		return *this->square;
	}

	int getDirection(char key);
	void setDirection(int dir);
	//int getFigure();//
	//int checkeEndOfBoard(Player player);/////
	//void setFigure();//////
	//int checkLocation();//
	//bool checkFigureLocation();//
};