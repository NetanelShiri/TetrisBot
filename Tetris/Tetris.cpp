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
	Board();

	//player settings
	player[0].playerInit('#', playerWidth, 0, "adxsw");
	player[1].playerInit('@', playerWidth+middleWidth, 1 , "jlmki");

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
	int figure=1;
	
	
	Direction direction;

	player[0].tetrominoCreator();
	player[1].tetrominoCreator();

		
	Sleep(400);
	
	
	do {
		
		player[Player1].setDirection(Direction::Down);
		player[Player1].playerMovement();
		player[Player2].setDirection(Direction::Down);
		player[Player2].playerMovement();

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

		
		Sleep(800);
		
	} while (key != ESC);
	
}

