#pragma once
#include<iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "Board.h"

class Tetris;

class Menu
{

public:
	
	bool botMenu(Tetris &tet);
	bool modeMenu(Tetris &tet);
	void instructions();
	void scoreBoard(Tetris &tet);
};