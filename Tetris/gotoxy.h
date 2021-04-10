#pragma once
#include<iostream>
#include <windows.h>
#include <conio.h>
#include <random>
#include "Colormod.h"


//game mode ( normal , color , epilepsy )
extern int mode;

void gotoxy(int x, int y);
void color(char ch,int colorNum);
void clearKeyboardBuffer();
int randomizer(double max);

