#include "gotoxy.h"
#include "Square.h"
#include "Tetris.h"
#include <process.h>
#include <conio.h>
using std::cout;
using std::endl;
using std::cin;


//square constructor for specific player
Square::Square(int _width, char _ch):playerWidth(_width),playerChar(_ch)
{
	init(_width);
}

//drawing the square
void Square::draw(char ch) {
	for (int i = 0; i < SIZE; i++) {
		 body[i].draw(ch);
	}

}

//initialize the square by player location
void Square::init(int width){
	body[0].setX(width);
	body[0].setY(1); 

	body[1].setX(width+1);
	body[1].setY(1);

	body[2].setX(width);
	body[2].setY(2);

	body[3].setX(width+1);
	body[3].setY(2);
}
/*
void Square::move() {
	body[0].draw(' ');
	body[1].draw(' ');

	body[0].move(direction);
	body[1].move(direction);

	body[2].move(direction);
	body[3].move(direction);
	Sleep(400);
	body[0].draw('#');
	body[1].draw('#');

}
*/
//body[SIZE - 1].draw(' ');
//	for (int i = SIZE - 1; i > 0; i--)
//	{
//		body[i] = body[i - 1];
//	}
//	body[0].move(direction);
//	setTextColor(color);
//	body[0].draw(figure);






//void draw() {
		
//int x = 1;
//int y = 1;

//	while (!_kbhit() || _getch() != 27)
//	{
//		gotoxy(x, y);
//		cout << "#";

//		gotoxy(x+1, y);
//		cout << "#";

//		gotoxy(x, y+1);
//		cout << "#";

//		gotoxy(x+1, y+1);
//		cout << "#";

//		if (y == maxHeight - 1)
//			break;
//		Sleep(400);

//		gotoxy(x, y);
//		cout << " ";

//		gotoxy(x+1, y);
//		cout << " ";

//		gotoxy(x, y+1);
//		cout << " ";

//		gotoxy(x+1, y+1);
//		cout << " ";

//		y++;

//	}

//}