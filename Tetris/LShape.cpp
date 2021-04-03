#include "LShape.h"
#include "Tetrominos.h"
using std::cout;
using std::endl;
using std::cin;

//default ctor
LShape::LShape() { playerWidth = 0;  playerChar = '#'; }

//square constructor for specific player
LShape::LShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	initTetromino();
}

//drawing the square
void LShape::drawTetromino() {
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
	}

}

//initialize the square by player location
void LShape::initTetromino() {

	//line
	body[0].setX(this->playerWidth);
	body[0].setY(1);

	body[1].setX(this->playerWidth);
	body[1].setY(2);

	body[2].setX(this->playerWidth+1);
	body[2].setY(2);

	body[3].setX(this->playerWidth + 2);
	body[3].setY(2);

}

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void LShape::moveTetromino(Direction direction) {

	clearBody();

	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
}

void LShape::RotateCW()
{

	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();

		body[2].setX(body[2].getX() - 1);
		body[2].setY(body[2].getY() + 1);
		body[3].setX(body[3].getX() - 1);
		body[3].setY(body[3].getY() - 1);

		this->drawTetromino();

		rotateDirection = RotateDirection::Right;
		break;

	case RotateDirection::Right:
		clearBody();

		body[1].setX(body[1].getX() - 1);
		body[1].setY(body[1].getY() - 1);
		body[2].setX(body[2].getX() + 1);
		body[2].setY(body[2].getY() - 1);

		this->drawTetromino();

		rotateDirection = RotateDirection::Down;
		break;
	case RotateDirection::Down:
		clearBody();

		
		body[1].setX(body[1].getX() + 1);
		body[1].setY(body[1].getY() + 1);
		body[2].setX(body[2].getX() - 1);
		body[2].setY(body[2].getY() + 1);
		body[3].setX(body[3].getX() - 2);
		body[3].setY(body[3].getY() + 2);

		this->drawTetromino();

		rotateDirection = RotateDirection::Left;
		break;
	case RotateDirection::Left:
		clearBody();

		body[2].setX(body[2].getX() + 1);
		body[2].setY(body[2].getY() - 1);
		body[3].setX(body[3].getX() + 3);
		body[3].setY(body[3].getY() - 1);


		this->drawTetromino();

		rotateDirection = RotateDirection::Up;
		break;

	}
	
	

}


void  LShape::clearBody()
{
	body[0].draw(' ');
	body[1].draw(' ');
	body[2].draw(' ');
	body[3].draw(' ');
 }

void LShape:: RotateCCW() {


	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();

		body[2].setX(body[2].getX() - 1);
		body[2].setY(body[2].getY() + 1);
		body[3].setX(body[3].getX() - 3);
		body[3].setY(body[3].getY() + 1);

		this->drawTetromino();

		rotateDirection = RotateDirection::Left;
		break;

	case RotateDirection::Left:
		clearBody();

		body[1].setX(body[1].getX() - 1);
		body[1].setY(body[1].getY() - 1);
		body[2].setX(body[2].getX() + 1);
		body[2].setY(body[2].getY() - 1);
		body[3].setX(body[3].getX() + 2);
		body[3].setY(body[3].getY() - 2);

		this->drawTetromino();

		rotateDirection = RotateDirection::Down;
		break;
	case RotateDirection::Down:
		clearBody();

		body[1].setX(body[1].getX() + 1);
		body[1].setY(body[1].getY() + 1);
		body[2].setX(body[2].getX() - 1);
		body[2].setY(body[2].getY() + 1);

		this->drawTetromino();

		rotateDirection = RotateDirection::Right;
		break;
	case RotateDirection::Right:
		clearBody();

		body[2].setX(body[2].getX() + 1);
		body[2].setY(body[2].getY() - 1);
		body[3].setX(body[3].getX() + 1);
		body[3].setY(body[3].getY() + 1);


		this->drawTetromino();

		rotateDirection = RotateDirection::Up;
		break;

	}

}