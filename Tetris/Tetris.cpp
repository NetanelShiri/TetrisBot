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
	player[0].playerInit('#', playerWidth, 0, "adswx");
	player[1].playerInit('@', playerWidth+middleWidth, 1 , "jlkim");

	//creating shapes according to player settings.
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
	
	Direction direction = Down;
	Tetromino shape = SquareS;	
	
	drawTetromino(shape, Player1);


	Sleep(400);
	
	
	
	do {
		
		if (_kbhit())
		{
			key = _getch();

			
	
			if ((direction = player[0].getDirection(key)) != None) {
				
				moveTetromino(shape, Player1, direction);
			}

			else if ((direction = player[1].getDirection(key)) != None) {
			

			}
			
			direction = Down;
			clearKeyboardBuffer();
		
			
		} 
		
		    moveTetromino(shape, Player1, direction);
			Sleep(1000);
		
	} while (key != ESC);
}



//All functions below can be way more efficient via inheritence and polymorphism!
//and will be able to be changed easily.
void Tetris::drawTetromino(Tetromino shape, int player)
{
	switch (shape)
	{
	case SquareS:
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
	    drawTetromino(SquareS, player);
	
	}
}

void Tetris::moveTetromino(Tetromino shape, int player, Direction direction)
{
	switch (shape)
	{
	case SquareS:
		square[player]->move(direction);
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
		moveTetromino(SquareS, player, direction);

	}
		
}

//initialize the tetrinoms, the way we want it (colored/white/char/size...etc).
void Tetris::tetrominoInit()
{

	//Player1 initialization
	int player1Width = player[Player1].getWidthDefault();
	int player1Char = player[Player1].getPlayerChar();
	square[Player1] = new SquareShape(player1Width, player1Char);
	line[Player1] = new LineShape(player1Width, player1Char);
	
	//Player2 initialization
	int player2Width = player[Player2].getWidthDefault();
	int player2Char = player[Player2].getPlayerChar();
	square[Player2] = new SquareShape(player2Width, player2Char);
	line[Player2] = new LineShape(player2Width, player2Char);

}