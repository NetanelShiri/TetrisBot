#pragma once

class Player {


	int direction = 0;
	char arrowKeys[5];
	int playerNumber = 0;
	int widthDefault = 0;
	char playerChar = ' ';


	
public:


	void playerInit(char _playerChar,int _width,int _playerNumber,const char _keys[5]);
	//void setArrowKeys(const char* keys); 
	char getPlayerChar();
	int getWidthDefault();



	int getDirection(char key);
	void setDirection(int dir);
	//int getFigure();//
	//int checkeEndOfBoard(Player player);/////
	//void setFigure();//////
	//int checkLocation();//
	//bool checkFigureLocation();//
};