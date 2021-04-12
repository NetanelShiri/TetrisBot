#include "LShape.h"
#include "Tetrominos.h"

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

void LShape::RotateCW(int playerBoard[12][18],int distancing)
{

	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();

		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() - 1);
		saveParts[0].setY(body[2].getY() + 1);
		saveParts[1].setX(body[3].getX() - 1);
		saveParts[1].setY(body[3].getY() - 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{

			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() + 1);
			body[3].setX(body[3].getX() - 1);
			body[3].setY(body[3].getY() - 1);
		    rotateDirection = RotateDirection::Right;

		}
		this->drawTetromino();

		break;

	case RotateDirection::Right:
		clearBody();

		saveParts.resize(2);

		saveParts[0].setX(body[1].getX() - 1);
		saveParts[0].setY(body[1].getY() - 1);
		saveParts[1].setX(body[2].getX() + 1);
		saveParts[1].setY(body[2].getY() - 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{

			body[1].setX(body[1].getX() - 1);
			body[1].setY(body[1].getY() - 1);
			body[2].setX(body[2].getX() + 1);
			body[2].setY(body[2].getY() - 1);
			rotateDirection = RotateDirection::Down;

		}
		this->drawTetromino();

		break;
	case RotateDirection::Down:
		clearBody();

		saveParts.resize(3);

		saveParts[0].setX(body[1].getX() + 1);
		saveParts[0].setY(body[1].getY() + 1);
		saveParts[1].setX(body[2].getX() - 1);
		saveParts[1].setY(body[2].getY() + 1);
		saveParts[2].setX(body[3].getX() - 2);
		saveParts[2].setY(body[3].getY() + 2);

		if (checkLegal(saveParts, playerBoard, distancing))
		{

			body[1].setX(body[1].getX() + 1);
			body[1].setY(body[1].getY() + 1);
			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() + 1);
			body[3].setX(body[3].getX() - 2);
			body[3].setY(body[3].getY() + 2);
			rotateDirection = RotateDirection::Left;

		}
		this->drawTetromino();

		break;
	case RotateDirection::Left:
		clearBody();

		
		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() + 1);
		saveParts[0].setY(body[2].getY() - 1);
		saveParts[1].setX(body[3].getX() + 3);
		saveParts[1].setY(body[3].getY() - 1);
		

		if (checkLegal(saveParts, playerBoard, distancing))
		{

			body[2].setX(body[2].getX() + 1);
			body[2].setY(body[2].getY() - 1);
			body[3].setX(body[3].getX() + 3);
			body[3].setY(body[3].getY() - 1);
			rotateDirection = RotateDirection::Up;


		}
		this->drawTetromino();

		break;

	}
	
	

}

void LShape::RotateCCW(int playerBoard[12][18],int distancing) {


	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();

		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() - 1);
		saveParts[0].setY(body[2].getY() + 1);
		saveParts[1].setX(body[3].getX() - 3);
		saveParts[1].setY(body[3].getY() + 1);
		

		if (checkLegal(saveParts, playerBoard, distancing))
		{

			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() + 1);
			body[3].setX(body[3].getX() - 3);
			body[3].setY(body[3].getY() + 1);
			rotateDirection = RotateDirection::Left;

		}
		this->drawTetromino();

		break;

	case RotateDirection::Left:
		clearBody();

		saveParts.resize(3);

		saveParts[0].setX(body[1].getX() - 1);
		saveParts[0].setY(body[1].getY() - 1);
		saveParts[1].setX(body[2].getX() + 1);
		saveParts[1].setY(body[2].getY() - 1);
		saveParts[2].setX(body[3].getX() + 2);
		saveParts[2].setY(body[3].getY() - 2);

		if (checkLegal(saveParts, playerBoard, distancing))
		{

			body[1].setX(body[1].getX() - 1);
			body[1].setY(body[1].getY() - 1);
			body[2].setX(body[2].getX() + 1);
			body[2].setY(body[2].getY() - 1);
			body[3].setX(body[3].getX() + 2);
			body[3].setY(body[3].getY() - 2);
			rotateDirection = RotateDirection::Down;

		}
		this->drawTetromino();

		break;
	case RotateDirection::Down:
		clearBody();

		
		saveParts.resize(2);

		saveParts[0].setX(body[1].getX() + 1);
		saveParts[0].setY(body[1].getY() + 1);
		saveParts[1].setX(body[2].getX() - 1);
		saveParts[1].setY(body[2].getY() + 1);
		

		if (checkLegal(saveParts, playerBoard, distancing))
		{

			body[1].setX(body[1].getX() + 1);
			body[1].setY(body[1].getY() + 1);
			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() + 1);
			rotateDirection = RotateDirection::Right;
		}
		this->drawTetromino();

		break;
	case RotateDirection::Right:
		clearBody();

		
		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() + 1);
		saveParts[0].setY(body[2].getY() - 1);
		saveParts[1].setX(body[3].getX() + 1);
		saveParts[1].setY(body[3].getY() + 1);
		
		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[2].setX(body[2].getX() + 1);
			body[2].setY(body[2].getY() - 1);
			body[3].setX(body[3].getX() + 1);
			body[3].setY(body[3].getY() + 1);
			rotateDirection = RotateDirection::Up;
		}

		this->drawTetromino();

		break;

	}

}
