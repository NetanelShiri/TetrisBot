#pragma once
#include "Figure.h"

class Player {

	int _direction = 3;
	char arrowKeys[4];
	int _playerNumber;
	int _widthDefault;
	Figure tetrinom[7];
public:
	/*Player(char* arrowKeys,int playerNumber,int widthDefault) {//ctor

	}*/
	//void setArrowKeys(const char* keys); 

	int getDirection(char key);
	void setDirection(int dir);
	//int getFigure();//
	//int checkeEndOfBoard(Player player);/////
	//void setFigure();//////
	//int checkLocation();//
	//bool checkFigureLocation();//

};