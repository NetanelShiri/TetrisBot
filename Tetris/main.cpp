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
	Tetris *game = new Tetris();
	
	while (true)
	{
		delete game;
		game = new Tetris();
		if (game->mainMenu()) { delete game; break; }
	}
}