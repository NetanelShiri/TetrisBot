#pragma once
#include"Player.h"

#include "Tetrominos.h"

class Tetris
{
	enum { GameSpeed = 225 };
	enum { Player1,Player2, ESC = 27 };
	Player player[2];
	int playersAmount = 2;
	int paused = 0;
		
public:
	
	void init();
	bool mainMenu();
	void modeMenu();
	void instructions();
	void scoreBoard();
	void run();
	void pause();
	void gameOver(int Loser);

};
