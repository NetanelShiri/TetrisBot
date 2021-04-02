#include "gotoxy.h"
#include "Board.h"
#include "Tetris.h"
#include <process.h>
#include <conio.h>

/*
Tetris built using oop, easy to manage , add players , functionality and more ..
*/

using namespace std;

int main()
{
	Tetris game;
	game.init();
	game.run();
	
	gotoxy(0, 20);
	cout << "";
	


}