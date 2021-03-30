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
	player[1].playerInit('@', playerWidth+middleWidth, 1 , "jlkim");

	tetrominoInit();

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
	
	Tetromino shape = SquareS;
	
	moveTetromino(shape, 0);

	Sleep(400);
	//check(dir);
	
	
	
	do {
		if (_kbhit())
		{
			key = _getch();

			
	
			if ((dir = player[0].getDirection(key)) != -1) {
	
		

			}

			else if ((dir = player[1].getDirection(key)) != -1) {
				//if (checkFigure(player[1]) != -1)/////same as in player 0
				//player[1].setDirection(dir);
				//player[1].move();

			}
			

			Sleep(200);
		} 
	
			Sleep(400);
		
		//clear_screen();

	} while (key != ESC);
}


void Tetris::moveTetromino(Tetromino shape, int player)
{
	switch (shape)
	{
	case SquareS:
		square[player]->move();
		square[player]->draw();
		break;
	case LineS:
		break;
	case TS:
		break;
	case LS:
		break;
	case JS:
		break;
	case SkewS:
		break;
	case RSkewS:
		break;
	default:
		moveTetromino(SquareS, player);

	}
		
}

//initialize the tetrinoms, the way we want it (colored/white).
void Tetris::tetrominoInit()
{
	
	square[0] = new Square(player[0].getWidthDefault() , player[0].getPlayerChar());
	square[1] = new Square(player[1].getWidthDefault(), player[1].getPlayerChar());


}