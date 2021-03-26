#include<iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "Board.h"


using std::cout;
using std::endl;
using std::cin;


void init()
{
	Board();

	//[0].setArrowKeys("sad");
	//[1].setArrowKeys("kjl");
	//s[0].setColor(Color::YELLOW);
	//s[1].setColor(Color::LIGHTGREEN);
	//s[0].setFigure('o');
	//s[1].setFigure('x');
}

void run()
{
	char key = 0;
	int dir;
	do {
		if (_kbhit())
		{
			key = _getch();
			if ((dir = game[0].getDirection(key)) != -1)
				game[0].setDirection(dir);
			else if ((dir = game[1].getDirection(key)) != -1)
				game[1].setDirection(dir);
			
		game[0].move();
		game[1].move();
		
		Sleep(200);
	} while (key != ESC);

	//setTextColor(Color::WHITE);
	//clear_screen();


}