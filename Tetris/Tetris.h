#pragma once
#include"Player.h"

#include "SquareShape.h"
#include "LineShape.h"
#include "TShape.h"
#include "LShape.h"
#include "JShape.h"
#include "SkewShape.h"
#include "RSkewShape.h"

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
	enum { Player1,Player2, ESC = 27 };
	enum Tetromino { SquareS, LineS , TS , LS , JS , SkewS , RSkewS };

	Player player[2];

	SquareShape* square[2];
	LineShape* line[2];

public:
	
	
	void init();
	void run();
	void tetrominoInit();
	void drawTetromino(Tetromino shape, int player);
	void moveTetromino(Tetromino shape, int player, Direction direction);

};
