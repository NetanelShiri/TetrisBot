#include <iostream>
#include "Board.h"
#include "gotoxy.h"
#include "Tetris.h"
using std::cout;
using std::endl;

void Board::Boardinit() {

	
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
/*
int Board::gameOver()
{
	using namespace std;

	char a;
	cout << " #####     #    #     # ####### ####### #     # ####### ######\n";
	cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
	cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
	cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
	cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
	cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
	cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
	cout << "\n\nPress any key and enter\n";
	cin >> a;
	return 0;
}
*/
/*
void Board::gamePause()
{
	using namespace std;

	char a;
	cout << "#######     #    #     # ####### #######   \n";
	cout << "#     #    # #   #     # #       #         \n";
	cout << "#     #   #   #  #     # #       #         \n";
	cout << "# # # #  #     # #     # ####### #######   \n";
	cout << "#        ####### #     #       # #         \n";
	cout << "#        #     # #     #       # #         \n";
	cout << "#        #     # ####### ####### #######   \n";
	cout << "\n\nPress any key and enter\n";
	cin >> a;

}
*/