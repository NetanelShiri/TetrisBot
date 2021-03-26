#include "gotoxy.h"
#include "Board.h"
#include "Tetris.h"
#include <process.h>
#include <conio.h>
#include "Square.h"
using namespace std;

int main()
{
	Board();
	Tetris game;
	game.init();
	game.run();
	
	//while (!_kbhit() || _getch() != 27)
	//{
	//	gotoxy(x, y);
	//	cout << "#";
	//	if (y == maxheight - 1)
	//		break;;
	//	Sleep(400);
	//	gotoxy(x, y);
	//	cout << " ";

	//	y++;

	//}
	
	//cout << "\n\n";
	//return 0;
}