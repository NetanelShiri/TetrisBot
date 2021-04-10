#include "gotoxy.h"



int mode = 0;

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	std::cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void color(char ch,int colorNum)
{
	if (colorNum == -1) { colorNum = randomizer(0.0,7.0); }
	switch (colorNum)
	{
	case 0: //RED
		std::cout << "\033[1;31m" << ch << "\033[0m\n";
		break;
	case 1: //GREEN
		std::cout << "\033[1;32m" << ch << "\033[0m\n";
		break;
	case 2: //YELLOW
		std::cout << "\033[1;33m" << ch << "\033[0m\n";
		break;
	case 3: //BLUE
		std::cout << "\033[1;34m" << ch << "\033[0m\n";
		break;
	case 4: //MAGNETA
		std::cout << "\033[1;35m" << ch << "\033[0m\n";
		break;
	case 5: //CYAN
		std::cout << "\033[1;36m" << ch << "\033[0m\n";
		break;
	case 6: //WHITE
		std::cout << "\033[1;37m" << ch << "\033[0m\n";
		break;
	default:
		std::cout << "\x1B[31m" << ch << "\033[0m\n";
	}
		
}

void clearKeyboardBuffer()
{
	char junk;
	while (_kbhit())
	{
		junk = _getch();
	}
}

void consoleColor()
{
	int color = randomizer(9.0, 15.0);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, color);	
}

void resetConsoleColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 7);
}

void hideCursor()
{
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);
}

int randomizer(double min , double max)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(min , max);

	return (int)dist(mt);
}