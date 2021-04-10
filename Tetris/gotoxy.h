#pragma once
#include<iostream>
#include <windows.h>
#include <conio.h>
#include <random>



//game mode ( normal , color , epilepsy )
extern int mode;

void gotoxy(int x, int y);
void color(char ch,int colorNum);
void consoleColor();
void resetConsoleColor();
void clearKeyboardBuffer();
int randomizer(double min , double max);
void hideCursor();

