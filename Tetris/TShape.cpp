#include "TShape.h"
#include "Tetrominos.h"

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



void TShape::RotateCW(int playerBoard[12][18],int distancing)
{
	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();
		saveParts.resize(1);

		saveParts[0].setX(body[1].getX() + 1);
		saveParts[0].setY(body[1].getY() + 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[1].setX(body[1].getX() + 1);
			body[1].setY(body[1].getY() + 1);
			rotateDirection = RotateDirection::Right;
		}
		this->drawTetromino();
		break;

	case RotateDirection::Right:
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[0].getX());
		saveParts[0].setY(body[0].getY() + 2);
		saveParts[1].setX(body[1].getX() - 1);
		saveParts[1].setY(body[1].getY() - 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[0].setY(body[0].getY() + 2);
			body[1].setX(body[1].getX() - 1);
			body[1].setY(body[1].getY() - 1);
			rotateDirection = RotateDirection::Down;
		}
		this->drawTetromino();
		
		break;

	case RotateDirection::Down:
		clearBody();
		saveParts.resize(1);

		saveParts[0].setX(body[3].getX() - 1);
		saveParts[0].setY(body[3].getY() - 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[3].setX(body[3].getX() - 1);
			body[3].setY(body[3].getY() - 1);
			rotateDirection = RotateDirection::Left;
		}
		this->drawTetromino();
	
		break;


	case RotateDirection::Left:
		clearBody();

		saveParts.resize(2);
		saveParts[0].setX(body[0].getX());
		saveParts[0].setY(body[0].getY() - 2);
		saveParts[1].setX(body[3].getX() + 1);
		saveParts[1].setY(body[3].getY() + 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[0].setY(body[0].getY() - 2);
			body[3].setX(body[3].getX() + 1);
			body[3].setY(body[3].getY() + 1);
			rotateDirection = RotateDirection::Up;
		}

		this->drawTetromino();
		break;
	}

}


void TShape::RotateCCW(int playerBoard[12][18],int distancing)
{
	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();
		saveParts.resize(3);

		saveParts[0].setX(body[1].getX());
		saveParts[0].setY(body[1].getY() - 2);
		saveParts[1].setX(body[2].getX());
		saveParts[1].setY(body[2].getY() - 2);
		saveParts[2].setX(body[3].getX() - 1);
		saveParts[2].setY(body[3].getY() - 3);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[1].setY(body[1].getY() - 2);
			body[2].setY(body[2].getY() - 2);
			body[3].setX(body[3].getX() - 1);
			body[3].setY(body[3].getY() - 3);
			rotateDirection = RotateDirection::Left;
		}
		this->drawTetromino();
		break;

	case RotateDirection::Left:
		clearBody();
		saveParts.resize(1);

		saveParts[0].setX(body[3].getX() + 1);
		saveParts[0].setY(body[3].getY() + 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[3].setX(body[3].getX() + 1);
			body[3].setY(body[3].getY() + 1);
			rotateDirection = RotateDirection::Down;
		}
		this->drawTetromino();
		break;

	case RotateDirection::Down:
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[0].getX());
		saveParts[0].setY(body[0].getY() - 2);
		saveParts[0].setX(body[1].getX() + 1);
		saveParts[0].setY(body[1].getY() + 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[0].setY(body[0].getY() - 2);
			body[1].setX(body[1].getX() + 1);
			body[1].setY(body[1].getY() + 1);
			rotateDirection = RotateDirection::Right;
		}
		this->drawTetromino();
		break;


	case RotateDirection:: Right:
		clearBody();
		saveParts.resize(1);

		saveParts[0].setX(body[1].getX() - 1);
		saveParts[0].setY(body[1].getY() - 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[1].setX(body[1].getX() - 1);
			body[1].setY(body[1].getY() - 1);
			rotateDirection = RotateDirection::Up;
		}
		this->drawTetromino();
		break;
	}

}