#pragma once
#include"Player.h"

#include "Tetrominos.h"

class Tetris
{
	enum { GameSpeed = 300 };
	enum { Player1,Player2, ESC = 27 };
	Player player[2];
	int playersAmount = 2;
		
public:
	
	void init();
	void mainMenu();
	void run();
	void pause();
	void gameOver(int Loser);

};
