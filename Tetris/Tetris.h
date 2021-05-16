#pragma once
#include "Player.h"
#include "Human.h"
#include <chrono>
#include <thread>
#include "Bot.h"
#include "Tetrominos.h"
#include "Menu.h"

using namespace std::literals;
using namespace std::chrono;

class Menu;
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
	Menu* menu = new Menu();
		
public:
	
	Tetris() {};
	~Tetris();
	
	void init();
	bool mainMenu(int restarted , char &key);
	void run();
	void pause();
	void checkPlayerKBHIT(char& key, vector<Player*> players);
	void gameOver(int Loser);
	const int getGameState() { return gameIsOver; }
	const int getPlayersAmount() { return playersAmount; }
	const int getLevel() { return level; }
	string setGameSpeed();
	Player** getPlayers() { return player; }
	TYPE getType() { return type; }
	
};
