#pragma once
#include"Player.h"

#include "Tetrominos.h"

class Tetris
{
	enum LEVEL { Easy , Normal , Hard , EXTREME};
	enum { Player1,Player2, ESC = 27 };
	Player player[2];
	int playersAmount = 2;

	int gameSpeed = 225;
	int level = 0;
	int paused = 0;
	int gameIsOver = 0;

		
public:
	
	void init();
	bool mainMenu(int restarted);
	bool modeMenu();
	void instructions();
	void scoreBoard();
	void run();
	void pause();
	void gameOver(int Loser);
	int getGameState() { return gameIsOver; }
	string setGameSpeed();
	

};
