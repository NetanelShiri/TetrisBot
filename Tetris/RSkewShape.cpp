#include "RSkewShape.h"
#include "Tetrominos.h"
using std::cout;
using std::endl;
using std::cin;

//default ctor
RSkewShape::RSkewShape() { playerWidth = 0;  playerChar = '#'; }

//square constructor for specific player
RSkewShape::RSkewShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	initTetromino();
}

//drawing the square
void RSkewShape::drawTetromino() {
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
	}

}

//initialize the square by player location
void RSkewShape::initTetromino() {

	//line
	body[0].setX(this->playerWidth);
	body[0].setY(1);

	body[1].setX(this->playerWidth + 1);
	body[1].setY(1);

	body[2].setX(this->playerWidth);
	body[2].setY(2);

	body[3].setX(this->playerWidth - 1);
	body[3].setY(2);
}

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void RSkewShape::moveTetromino(Direction direction) {
	clearBody();
	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
}

void RSkewShape::RotateCW(int playerBoard[12][18],int distancing)/////////
{
	if (rotateDirection == RotateDirection::Right) {
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[0].getX() - 1);
		saveParts[0].setY(body[0].getY());
		saveParts[1].setX(body[3].getX());
		saveParts[1].setY(body[3].getY() - 2);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[1].setX(body[0].getX() - 1);
			body[3].setY(body[3].getY() - 2);
			rotateDirection = RotateDirection::Up;
		}
		this->drawTetromino();

		
	}
	else if (rotateDirection == RotateDirection::Up)
	{
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[0].getX() + 1);
		saveParts[0].setY(body[0].getY());
		saveParts[1].setX(body[3].getX());
		saveParts[1].setY(body[3].getY() + 2);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[1].setX(body[0].getX() + 1);
			body[3].setY(body[3].getY() + 2);
			rotateDirection = RotateDirection::Right;
		}
		this->drawTetromino();

	}

}



void RSkewShape::clearBody()
{
	body[0].draw(' ');
	body[1].draw(' ');
	body[2].draw(' ');
	body[3].draw(' ');

}

void RSkewShape:: RotateCCW(int playerBoard[12][18],int distancing) {
	RotateCW(playerBoard,distancing);
}