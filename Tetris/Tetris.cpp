#include<iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "Board.h"
#include "Tetris.h"
#include "Square.h"



using std::cout;
using std::endl;
using std::cin;


void Tetris::init()
{	
	Board();

	player[0].playerInit('#', playerWidth, 0, "adswx");
	player[0].tetrinomInit();
	player[1].playerInit('@', playerWidth+middleWidth, 1 , "jlkim");
	player[1].tetrinomInit();
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
	int dir = 0;

	auto object = player[0].getSquare();
	object.draw();
	auto object2 = player[1].getSquare();
	object2.draw();

	Sleep(400);
	object.move();
	object.draw();
	
	
	
	do {
		if (_kbhit())
		{
			key = _getch();

			
	
			if ((dir = player[0].getDirection(key)) != -1) {
	
		

			}

			else if ((dir = player[1].getDirection(key)) != -1) {
				//if (checkFigure(player[1]) != -1)/////same as in player 0
				player[1].setDirection(dir);
				//player[1].move();

			}
			//player[0].move(); JUST THAT

			Sleep(200);
		} 
			
		object.move();
		object2.move();
		object.draw();
		object2.draw();
			
			Sleep(400);
		
		//clear_screen();

	} while (key != ESC);
}
