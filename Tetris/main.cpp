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
	Tetris* game;
	int restarted = 0;
	char key = ' ';
	while (true)
	{
		game = new Tetris();
		if (game->mainMenu(restarted , key)) { delete game; break; }
		if (game->getGameState()) { restarted = 0; }
		else { restarted = 1; }
		delete game;
	}
	
}