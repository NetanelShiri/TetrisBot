#include "TShape.h"
#include "Tetrominos.h"
using std::cout;
using std::endl;
using std::cin;

//default ctor
TShape::TShape() { playerWidth = 0;  playerChar = '#'; }

//square constructor for specific player
TShape::TShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	initTetromino();
}

//drawing the square
void TShape::drawTetromino() {
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
	}
}

//initialize the square by player location
void TShape::initTetromino() {

	//line
	body[0].setX(this->playerWidth);
	body[0].setY(1);

	body[1].setX(this->playerWidth-1);
	body[1].setY(2);

	body[2].setX(this->playerWidth);
	body[2].setY(2);

	body[3].setX(this->playerWidth+1);
	body[3].setY(2);
}

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void TShape::moveTetromino(Direction direction) {

	clearBody();

	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
}



void TShape::RotateCW()
{
	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();
		
		body[1].setX(body[1].getX()+1);
		body[1].setY(body[1].getY()+1);
	
		this->drawTetromino();

		rotateDirection = RotateDirection::Right;

		break;
	case RotateDirection::Right:
		clearBody();
		body[0].setY(body[0].getY() +2);

		body[1].setX(body[1].getX() - 1);
		body[1].setY(body[1].getY() - 1);

		this->drawTetromino();
		rotateDirection = RotateDirection::Down;
		break;

	case RotateDirection::Down:
		clearBody();

		body[3].setX(body[3].getX() - 1);
		body[3].setY(body[3].getY() - 1);

		this->drawTetromino();
		rotateDirection = RotateDirection::Left;
		break;


	case RotateDirection::Left:
		clearBody();

		body[0].setY(body[0].getY() - 2);
		body[3].setX(body[3].getX() + 1);
		body[3].setY(body[3].getY() + 1);

		this->drawTetromino();
		rotateDirection = RotateDirection::Up;
		break;
	}

}

void TShape::clearBody()
{
	body[0].draw(' ');
	body[1].draw(' ');
	body[2].draw(' ');
	body[3].draw(' ');
}

void TShape::RotateCCW()
{
	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();
		
		body[1].setY(body[1].getY() - 2);
		body[2].setY(body[2].getY() - 2);
		body[3].setX(body[3].getX() - 1);
		body[3].setY(body[3].getY() - 3);

		this->drawTetromino();

		rotateDirection = RotateDirection::Left;

		break;
	case RotateDirection::Left:
		clearBody();
		body[3].setX(body[3].getX() + 1);
		body[3].setY(body[3].getY() + 1);

		this->drawTetromino();
		rotateDirection = RotateDirection::Down;
		break;

	case RotateDirection::Down:
		clearBody();

		body[0].setY(body[0].getY() - 2);
		body[1].setX(body[1].getX() + 1);
		body[1].setY(body[1].getY() + 1);

		this->drawTetromino();
		rotateDirection = RotateDirection::Right;
		break;


	case RotateDirection:: Right:
		clearBody();

		body[1].setX(body[1].getX() - 1);
		body[1].setY(body[1].getY() - 1);

		this->drawTetromino();
		rotateDirection = RotateDirection::Up;
		break;
	}

}