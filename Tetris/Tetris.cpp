#include<iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "Board.h"
#include "Figure.h"
#include "Tetris.h"
#include "Square.h"



using std::cout;
using std::endl;
using std::cin;


void Tetris::init(int gameType = 0)
{	
	Board();

	player[0].playerInit('#', playerWidth, 0, "adswx");
	
	player[1].playerInit('@', playerWidth+10, 1 , "jlkim");

	switch (gameType)
	{
	case 0: // normal settings
		
		break;

	default:
		return;
	}
	
	//s[0].setColor(Color::YELLOW);
	//s[1].setColor(Color::LIGHTGREEN);
	
}

void Tetris::run()
{
	char key = 0;
	int dir;
	int figure=1;

	auto object = player[0].getSquare();
	object.init()
	
	//do {
	//	if (_kbhit())
	//	{
	//		key = _getch();

	//		///using getDirection to find out who is the player? or creat a spacific function for it ?? /////////
	//
	//		if ((dir = player[0].getDirection(key)) != -1) {
	//			/*if (checkEndOfBoard(player[0]) != true)/////didnt reach the end of the board
	//				player[0].setDirection(dir);
	//			//player[0].move();
	//			else//reach end of board 
	//			
	//				///rand figure+change figure +change dir+move//////

	//				//newFigure=player[0].chooseFigure();
	//				//player[0].setFigure(newFigure);// set the figure in the player+ 
	//				                                 //creat new interface (new figure)--with switch+draw it 
	//			                                 	//according to the right x in the player(default)
	//	*/

	//		}

	//		else if ((dir = player[1].getDirection(key)) != -1) {
	//			//if (checkFigure(player[1]) != -1)/////same as in player 0
	//			player[1].setDirection(dir);
	//			//player[1].move();

	//		}
	//		//player[0].move(); JUST THAT

	//		Sleep(200);
	//	} 
	//		Square s;
	//		//s.init(6);
	//		//s.draw('#');
	//		Sleep(400);
	//	//setTextColor(Color::WHITE);
	//	//clear_screen();

	//} while (key != ESC);
}
