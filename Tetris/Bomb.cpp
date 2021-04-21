#include "Bomb.h"
#include "Tetrominos.h"

//default ctor
Bomb::Bomb() { playerWidth = 0; playerChar = '#'; }

//square constructor for specific player
Bomb::Bomb(int _width , int _ch)
{
	playerWidth = _width;
	playerChar = bombChar;
	initTetromino();
}

//drawing the square
void Bomb::drawTetromino() {

	body[0].draw(this->playerChar);
}

//initialize the square by player location
void Bomb::initTetromino() {

	body[0].setX(this->playerWidth);
	body[0].setY(1);
	body[1].setX(this->playerWidth);
	body[1].setY(1);
	body[2].setX(this->playerWidth);
	body[2].setY(1);
	body[3].setX(this->playerWidth);
	body[3].setY(1);
}

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void Bomb::moveTetromino(Direction direction)
{

	clearBody();

	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
}

void Bomb::RotateCW(int playerBoard[12][18], int distancing)
{
	return;
}

void Bomb::RotateCCW(int playerBoard[12][18], int distancing) {
	return;
}
