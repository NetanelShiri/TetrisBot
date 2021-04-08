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
	int gameIsOver = 0;
	Direction direction;

	player[0].tetrominoCreator();
	player[1].tetrominoCreator();


	Sleep(400);


	do {
		player[Player1].PrintScore();
		player[Player2].PrintScore();
		player[Player1].setDirection(Direction::Down);
		if (player[Player1].playerMovement()) { player[Player1].checkFullLines(); }
		player[Player2].setDirection(Direction::Down);
		if(player[Player2].playerMovement()) { player[Player2].checkFullLines(); }

		while (_kbhit())
		{
			key = _getch();

			if ((direction = player[Player1].getDirection(key)) != Direction::None) {

				player[Player1].setDirection(direction);
				if (player[Player1].playerMovement())
				{
					player[Player1].checkFullLines();
				}
			}
			else if ((direction = player[Player2].getDirection(key)) != Direction::None) {

				player[Player2].setDirection(direction);
				
				if (player[Player2].playerMovement())
				{
					player[Player2].checkFullLines();
				}
			}

			
		}
		//	clearKeyboardBuffer();
		if (key == ESC) { key = ' ';  pause(); }
		Sleep(300);

	} while (gameIsOver != 1);

	pause();
	
	//player[0].drawFromPlayerBoard();
	//player[1].drawFromPlayerBoard();
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
