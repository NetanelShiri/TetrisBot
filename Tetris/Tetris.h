#pragma once
#include"Player.h"

#include "Tetrominos.h"

class Tetris
{
	enum { Player1,Player2, ESC = 27 };
	Player player[2];
	int playersAmount = 2;
		
public:
	
	void init();
	void run();
	void pause();
	void gameOver();

};
