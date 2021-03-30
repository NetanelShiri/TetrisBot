#pragma once

#include"Player.h"
#include "Square.h"

//board
constexpr size_t minHeight = 0;
constexpr size_t maxHeight = 19;
constexpr size_t minWidth = 0;
constexpr size_t maxWidth = 26;
constexpr size_t middleWidth = 13;

//player
constexpr size_t playerWidth = 6;


class Tetris
{
	enum { ESC = 27 };
	enum Tetromino { SquareS, LineS , TS , LS , JS , SkewS , RSkewS };
	Player player[2];
	Square* square[2];


public:
	
	
	void init();
	void run();
	void tetrominoInit();
	void moveTetromino(Tetromino shape, int player);

};
