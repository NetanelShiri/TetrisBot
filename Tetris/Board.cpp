#include <iostream>
#include "Board.h"
#include "gotoxy.h"
#include "Tetris.h"
using std::cout;
using std::endl;

void Boardinit() {

	
	system("cls");

	_flushall();


	//borders
	gotoxy(minWidth, minHeight);
	cout << char(201);

	gotoxy(maxWidth, minHeight);
	cout << char(187);

	gotoxy(minWidth,maxHeight);
	cout << char(200);
	
	gotoxy(maxWidth, maxHeight);
	cout << char(188);

	// width
	for (int x = minWidth+1; x < maxWidth; x++) {// Board Boundary
		if (x == middleWidth)
		{
			gotoxy(x, minHeight);
			cout << char(203);
			gotoxy(x, maxHeight);
			cout << char(202);
			continue;
		}
		gotoxy(x, minHeight);
		cout << char(205);
		gotoxy(x, maxHeight);
		cout << char(205);
	}


	//height
	for (int y = minHeight+1; y < maxHeight; y++)
	{
		gotoxy(minWidth, y);
		cout << char(186);
		gotoxy(maxWidth, y);
		cout << char(186);
		gotoxy(middleWidth, y);
		cout << char(186);
	}

	cout << "\n\n";


}

void printGameOver()
{
	if (mode != 0) { consoleColor(); }
	cout << " #####     #    #     # ####### ####### #     # ####### ######\n";
	cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
	if (mode != 0) { consoleColor(); }
	cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
	cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
	if (mode != 0) { consoleColor(); }
	cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
	cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
	cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";	
	if (mode != 0) { resetConsoleColor(); }
}

void printPause()
{
	if (mode != 0) { consoleColor(); }
	cout << "#######     #    #     # ####### #######   \n";
	cout << "#     #    # #   #     # #       #         \n";
	if (mode != 0) { consoleColor(); }
	cout << "#     #   #   #  #     # #       #         \n";
	cout << "# # # #  #     # #     # ####### #######   \n";
	if (mode != 0) { consoleColor(); }
	cout << "#        ####### #     #       # #         \n";
	cout << "#        #     # #     #       # #         \n";
	cout << "#        #     # ####### ####### #######   \n";
	if (mode != 0) { consoleColor(); }
	cout << "\n\nPress '2' key to continue\n";
	if(mode != 0) { resetConsoleColor(); }

}
