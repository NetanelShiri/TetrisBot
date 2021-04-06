#include "SkewShape.h"
#include "Tetrominos.h"
using std::cout;
using std::endl;
using std::cin;

//default ctor
SkewShape::SkewShape() { playerWidth = 0;  playerChar = '#';  }

//square constructor for specific player
SkewShape::SkewShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	initTetromino();
}

//drawing the square
void SkewShape::drawTetromino() {
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
	}

}

//initialize the square by player location
void SkewShape::initTetromino() {

	//line
	body[0].setX(this->playerWidth - 1);
	body[0].setY(1);

	body[1].setX(this->playerWidth );
	body[1].setY(1);

	body[2].setX(this->playerWidth);
	body[2].setY(2);

	body[3].setX(this->playerWidth+1);
	body[3].setY(2);
}

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void SkewShape::moveTetromino(Direction direction) {

	clearBody();

	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
}


void SkewShape::RotateCW(int playerBoard[12][18],int distancing)
{
	if (rotateDirection == RotateDirection::Left) {
		clearBody();

		body[0].setX(body[0].getX() + 2);
		body[0].setY(body[0].getY() - 1);
		body[3].setY(body[3].getY() - 1);
		this->drawTetromino();

		rotateDirection = RotateDirection::Up;
	}
	else if(rotateDirection == RotateDirection::Up)
	{
		clearBody();

		body[0].setX(body[0].getX() - 2);
		body[0].setY(body[0].getY() + 1);
		body[3].setY(body[3].getY() + 1);
		this->drawTetromino();
		rotateDirection = RotateDirection::Left;

	}

}

void  SkewShape::clearBody()
{
	body[0].draw(' ');
	body[1].draw(' ');
	body[2].draw(' ');
	body[3].draw(' ');
}


void SkewShape::RotateCCW(int playerBoard[12][18],int distancing) {
	RotateCW(playerBoard,distancing);
}