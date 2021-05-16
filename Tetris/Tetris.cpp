#include<iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "Board.h"
#include "Tetris.h"

//initilize the game
void Tetris::init()
{	
	system("cls");
	_flushall();

	switch (type)
	{
	case HvH:
		player[0] = new Human();
		player[1] = new Human();
		break;
	case HvC:
		player[0] = new Human();
		player[1] = new Bot();
		break;
	case CvC:
		player[0] = new Bot();
		player[1] = new Bot();
		break;
	default:
		player[0] = new Human();
		player[1] = new Human();
	}

	
	//player settings (char, player start width , distancing , player Number , game keys)
    player[0]->playerInit('#', playerWidth +(middleWidth*0),(middleWidth*0) , 1, "adxsw");
	player[1]->playerInit('@', playerWidth+(middleWidth*1), (middleWidth*1), 2 , "jlmki");
}

//running the game (main game loop)
void Tetris::run()
{
	
	char key = ' ';
	int figure = 1;
	bool keyHit = false;
	bool gameIsOver = false;
	int playerLost = 0;

	vector<Player*> players;

	for (int i = 0; i < playersAmount; i++)
	{
		players.push_back(player[i]);
		if (!paused) { players[i]->tetrominoCreator(); }
	}
	
	do {

		for (int i = 0; i < players.size(); i++)
		{
			if (mode != 0) { consoleColor(); }
		    
			players[i]->PrintScore();
			players[i]->setDirection(Direction::Down);
			if (players[i]->playerTurn())
			{
				players[i]->checkFullLines();
			}
			if (gameIsOver = players[i]->getPlayerState())
			{
				playerLost = players[i]->getPlayerNumber();
				break;
			}
		}
		if (gameIsOver) { break; } //break out of nested loop

		auto start = high_resolution_clock::now();
		long long dur = 0;
	
		while(dur < gameSpeed)
		{
			checkPlayerKBHIT(key, players);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			dur = duration.count();
		}

		if (key == ESC) { key = ' '; system("cls"); paused = 1; return; }
		
		
		if (mode == 2) { consoleColor(); Boardinit(); }
	} while (!gameIsOver);

	gameOver(playerLost);
}

//un-pausing the game(continue after pausing)
void Tetris::pause()
{

	cout << "Starting in 3...";
	Sleep(1000);
	cout << "2...";
	Sleep(1000);
	cout << "1...";
	Sleep(1000);

	if (mode != 0) { consoleColor(); }
	system("cls");
	Boardinit();
	for (int i = 0; i < playersAmount; i++)
	{
		player[i]->drawFromPlayerBoard();
	}
}

void Tetris::checkPlayerKBHIT(char &key , vector<Player*> players)
{
	while (_kbhit())
	{
		key = _getch();

		for (int i = 0; i < players.size(); i++)
		{
			if (typeid(*players[i]) != typeid(Bot)) {
				if ((players[i]->getDirection(key)) != Direction::None) {
					players[i]->setDirection(players[i]->getDirection(key));
					players[i]->playerTurn();
				}
			}
		}
	}
}

//set the game as over and find the lost player
void Tetris::gameOver(int Loser)
{
	gameIsOver = 1;

	system("cls");
	
	printGameOver();
	cout << endl;
	cout << "Player " << Loser << " lost!" << endl;

	scoreBoard();
	clearKeyboardBuffer();
	cout << "Press any key to return to main-menu.";
	while (!_kbhit())
	{
		Sleep(200);
	}
	mode = 0;
}

//calculate the players scores
void Tetris::scoreBoard()
{
	vector<pair<int, int>> scores;
	int i = 0;

	cout << endl << "~~~~~~Scoreboard~~~~~" << endl;
	for (int i = 0; i < playersAmount; i++)
	{
		scores.push_back(make_pair(player[i]->getScore(),player[i]->getPlayerNumber()));
	}
	sort(scores.rbegin(), scores.rend());

	for (auto it : scores) {
		cout << ++i << ".Player " << it.second << " score is : " << it.first<< endl;
	}
	cout << endl;
}

//printing the game's instructions
void Tetris::instructions()
{
	clearKeyboardBuffer();
	system("cls");
	cout << "          Player 1 keys            Player 2 keys" << endl;
	cout << "Left         A or a                    j or J     " << endl;
	cout << "Right        D or d                    l or L     " << endl;
	cout << "Rotate       S or s                    k or K     " << endl;
	cout << "cRotate      W or w                    i or I     " << endl;
	cout << "Accelerate   X or x                    m or M     " << endl << endl;

	cout << "Press any key to return";
	
	while (!_kbhit())
	{
		Sleep(200);
	}
	system("cls");
	return;
	
}

bool Tetris::botMenu()
{
	clearKeyboardBuffer();
	char key;
	int numberKey;

	system("cls");
	cout << "Pick Level:  (Press Number) " << endl;
	cout << "(1) Novice" << endl;
	cout << "(2) Good" << endl;
	cout << "(3) Best" << endl;

	cout << "(0) Return to main menu " << endl;
	do {
		key = _getch();
		while (_kbhit())
		{
			Sleep(200);
		}
	} while ((key != '1') && (key != '2') && (key != '3') && (key != '0'));

	numberKey = key - '0';
	switch (key)
	{
	case '1':
	case '2':
	case '3':
		if (type == HvC) { dynamic_cast<Bot*>(player[1])->setLevel(numberKey); }
		else if (type == CvC) {
			dynamic_cast<Bot*>(player[0])->setLevel(numberKey);
			dynamic_cast<Bot*>(player[1])->setLevel(numberKey);
		}
		break;
	case '0':
		return false;
		break;
	default:
		break;
	}
	return true;
}

//introducing the game modes and speed , player picks one.
bool Tetris::modeMenu()
{
	clearKeyboardBuffer();
	char key;
	string gameSpeedPhrase = "(4) Set game speed : ";
	string gameSpeedLevel = setGameSpeed();

	system("cls");
	cout << "Pick Mode:  (Press Number) " << endl;
	cout << "(1) Normal Mode" << endl;
	cout << "(2) Rainbow Mode" << endl;
	cout << "(3) Epilepsy Mode | WARNING: This mode contains flashing lights which\n "
		"	          | May not be suitable for photosensitive epilepsy." << endl << endl;
	
	cout << gameSpeedPhrase << level << ' ' << gameSpeedLevel << endl << endl;
	

	cout << "(0) Return to main menu " << endl;

	do {
		key = _getch();
		while (_kbhit())
		{
			Sleep(200);
		}
		if (key == '4') {
			gotoxy(0, 6);
			for (int i = 0; i < gameSpeedPhrase.length() + gameSpeedLevel.length() + 5; i++) { cout << ' '; }
			gameSpeedLevel = setGameSpeed();
			gotoxy(0, 6);
			cout << gameSpeedPhrase << level << ' ' << gameSpeedLevel;
		}
	} while ((key != '1') && (key != '2') && (key != '3') && (key != '0'));
	
	system("cls");
	switch (key)
	{
	case '1':
		mode = 0;
		break;
	case '2':
		mode = 1;
		break;
	case '3':
		mode = 2;
		break;
	case '0':
		return false;
		break;
	default:
		break;
	}
	return true;
}
	
//main menu 
bool Tetris::mainMenu(int restarted , char &key)
{
	bool modeLevel = true;
	mode = 0;
	hideCursor();
	while (true) {
		
		    
			clearKeyboardBuffer();
			system("cls");
			if (!restarted)
			{
				if (!paused) { system("cls"); }
				else { printPause(); }
				cout << "Main Menu:  (Press Number) " << endl;
				cout << "(1) Start a new game - Human vs Human" << endl;
				cout << "(2) Start a new game - Human vs Computer" << endl;
				cout << "(3) Start a new game - Computer vs Computer" << endl;
				if (paused) { cout << "(4) Continue a paused game" << endl; }
				cout << "(8) Instructions" << endl;
				cout << "(9) Exit game" << endl;

				do {
					key = _getch();
					while (_kbhit())
					{
						Sleep(200);
					}
					if (paused && key == '4') { pause(); run(); break; }
				} while ((key != '1') && (key != '8') && (key != '9') && (key != '2') && (key != '3'));
			}
			else { restarted = 0; }
		
			

		switch (key)
		{
		case '1':
			if (key == '1') { type = HvH; }
		case '2':
			if (key == '2') { type = HvC; }
		case '3':
			if (key == '3') { type = CvC; }
			if (paused) { return false; }
			init();
			
			if (key != '1') { modeLevel = botMenu(); }
			if (modeLevel) {
				if (modeMenu()) {
					if (mode != 0) { consoleColor(); }
					Boardinit();
					run();
				}
			}
			break;
		case '8':
			instructions();
			break;
		case '9':
			return true;
			break;

		}
		if (gameIsOver) { return false; }
	}
	
}
	
//set the game's speed
string Tetris::setGameSpeed()
{
	
	if (level == 4) { level = 0; }
	switch (++level)
	{
	case 1:
		gameSpeed = 300;
		return "(Easy) NOT RECOMMENDED";
		break;
	case 2:
		gameSpeed = 225;
		return "(Normal)";
		break;
	case 3:
		gameSpeed = 150;
		return "(Hard)";
		break;
	case 4:
		gameSpeed = 100;
		return "(EXTREME)";
		break;
	default:
		gameSpeed = 225;
		return "Normal";
		
	}
	return "Normal";
	
}