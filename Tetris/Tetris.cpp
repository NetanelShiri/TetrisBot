#include<iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "Board.h"
#include "Tetris.h"

using std::cout;
using std::endl;
using std::cin;


void Tetris::init()
{	
	//creating board
	Boardinit();
    
	//player settings (char, player start width , distancing , player Number , game keys)
	player[0].playerInit('#', playerWidth +(middleWidth*0),(middleWidth*0) , 1, "adxsw");
	player[1].playerInit('@', playerWidth+(middleWidth*1), (middleWidth*1), 2 , "jlmki");

	//creating shapes according to player settings.
	

	/*switch (gameType)
	{
	case 0: // normal settings
		
		break;

	default:
		return;
	}
	*/
	//s[0].setColor(Color::YELLOW);
	//s[1].setColor(Color::LIGHTGREEN);
	
}

void Tetris::run()
{
	char key = 0;
	int figure = 1;
	bool gameIsOver = false;
	int playerLost = 0;
	Direction direction;

	player[0].tetrominoCreator();
	player[1].tetrominoCreator();

	do {
		player[Player1].PrintScore();
		player[Player2].PrintScore();

		
		player[Player1].setDirection(Direction::Down);
		if (player[Player1].playerMovement()) { 
			player[Player1].checkFullLines(); 
		
		}
		if (player[Player1].getPlayerState()) { 
			playerLost = player[Player1].getPlayerNumber();
			break;
		}
		
		player[Player2].setDirection(Direction::Down);
		if(player[Player2].playerMovement()) { 
			player[Player2].checkFullLines(); 
		}
		if (player[Player2].getPlayerState()) { 
			playerLost = player[Player2].getPlayerNumber();
			break;
		}
		

		while (_kbhit())
		{
			key = _getch();

			if ((direction = player[Player1].getDirection(key)) != Direction::None) {
				player[Player1].setDirection(direction);
				player[Player1].playerMovement();
			}
			else if ((direction = player[Player2].getDirection(key)) != Direction::None) {
				player[Player2].setDirection(direction);
				player[Player2].playerMovement();
			}

			
		}
		//	clearKeyboardBuffer();
		if (key == ESC) { key = ' ';  pause(); }
		
		Sleep(GameSpeed);

	} while (!gameIsOver);

	gameOver(playerLost);
}

void Tetris::pause()
{
	char key;
	system("cls");
	printPause();
	do {
		key = _getch();
		while (_kbhit())
		{
			Sleep(200);
		}
	} while (key != '2');


	cout << "Starting in 3...";
	Sleep(1000);
	cout << "2...";
	Sleep(1000);
	cout << "1...";
	Sleep(1000);

	Boardinit();
	for (int i = 0; i < playersAmount; i++)
	{
		player[i].drawFromPlayerBoard();
	}
}

void Tetris::gameOver(int Loser)
{
	char key;
	system("cls");
	
	printGameOver();
	cout << endl;
	cout << "Player " << Loser << " lost!" << endl;

	scoreBoard();
	_flushall();
	cout << "Press (9) to exit game." << endl;
	cout << "Press (0) to return to main-menu.";
	do {
		key = _getch();
		while (_kbhit())
		{
			Sleep(200);
		}
	} while ((key != '9') && (key != '0'));
	
	if (key == '0') { mainMenu(); }
}


void Tetris::scoreBoard()
{
	vector<pair<int, int>> scores;
	int i = 0;

	cout << endl << "~~~~~~Scoreboard~~~~~" << endl;
	for (int i = 0; i < playersAmount; i++)
	{
		scores.push_back(make_pair(player[i].getScore(),player[i].getPlayerNumber()));
	}
	sort(scores.rbegin(), scores.rend());

	for (auto it : scores) {
		cout << ++i << ".Player " << it.second << " score is : " << it.first<< endl;
	}
	cout << endl;
}


void Tetris::instructions()
{

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
	mainMenu();
	
}

void Tetris::mainMenu()
{
	char key;
	system("cls");
	cout << "Main Menu:  (Press Number) " << endl;
	cout << "(1) Start a new game" << endl;
	cout << "(8) Instructions" << endl;
	cout << "(9) Exit game" << endl;

	do {
		key = _getch();
		while (_kbhit())
		{
			Sleep(200);
		}
	} while ((key != '1') && (key != '8') && (key != '9'));

	switch (key)
	{
	case '1':
		init();
		run();
		break;
	case '8':
		instructions();
		break;
	case '9':
		return;
	default:
		return;

	}


}
	