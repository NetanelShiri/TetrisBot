#pragma once
#include "Player.h"
#include "Human.h"
#include <chrono>
#include <thread>
#include "Bot.h"
#include "Tetrominos.h"
using namespace std::literals;
using namespace std::chrono;

class Tetris
{
	enum LEVEL { Easy , Normal , Hard , EXTREME};
	enum TYPE { HvH , HvC , CvC};
	enum { Player1,Player2, ESC = 27 };
	Player* player[2];
	int playersAmount = 2;

	int gameSpeed = 225;
	int level = 1;
	int paused = 0;
	int gameIsOver = 0;
	TYPE type = HvH;

		
public:
	
	void init();
	bool mainMenu(int restarted , char &key);
	bool botMenu();
	bool modeMenu();
	void instructions();
	void scoreBoard();
	void run();
	void pause();
	void gameOver(int Loser);
	void checkPlayerKBHIT(char& key, vector<Player*> players);
	int getGameState() { return gameIsOver; }
	string setGameSpeed();
	

};
