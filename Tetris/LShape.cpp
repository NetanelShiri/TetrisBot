#include "LShape.h"
#include "Tetrominos.h"

//default ctor
LShape::LShape() { playerWidth = 0;  playerChar = '#'; }

//square constructor for specific player
LShape::LShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	rotations = 4;
	initTetromino();
}

//setting location in bottom right.	
void LShape::initTemporary(int _rotation)
{
	saveParts.resize(4);

	if (_rotation == 1) {
		//[9][16]
		saveParts[0].setX(middleWidth - 4);
		saveParts[0].setY(maxHeight - 3);
		//[9][17]
		saveParts[1].setX(middleWidth - 4);
		saveParts[1].setY(maxHeight - 2);
		//[10][17]
		saveParts[2].setX(middleWidth - 3);
		saveParts[2].setY(maxHeight - 2);
		//[11][17]
		saveParts[3].setX(middleWidth - 2);
		saveParts[3].setY(maxHeight - 2);
	}
	else if (_rotation == 2) {
		//[11][15]
		saveParts[0].setX(middleWidth - 2);
		saveParts[0].setY(maxHeight - 4);
		//[10][15]
		saveParts[1].setX(middleWidth - 3);
		saveParts[1].setY(maxHeight - 4);
		//[10][16]
		saveParts[2].setX(middleWidth - 3);
		saveParts[2].setY(maxHeight - 3);
		//[10][17]
		saveParts[3].setX(middleWidth - 3);
		saveParts[3].setY(maxHeight - 2);

	}
	else if (_rotation == 3) {
		
		//[9][16]
		saveParts[0].setX(middleWidth - 4);
		saveParts[0].setY(maxHeight - 3);
		//[10][16]
		saveParts[1].setX(middleWidth - 3);
		saveParts[1].setY(maxHeight - 3);
		//[11][16]
		saveParts[2].setX(middleWidth - 2);
		saveParts[2].setY(maxHeight - 3);
		//[11][17]
		saveParts[3].setX(middleWidth - 2);
		saveParts[3].setY(maxHeight - 2);
	}
	else if (_rotation == 4) {

		//[10][17]
		saveParts[0].setX(middleWidth - 3);
		saveParts[0].setY(maxHeight - 2);
		//[11][15]
		saveParts[1].setX(middleWidth - 2);
		saveParts[1].setY(maxHeight - 4);
		//[11][16]
		saveParts[2].setX(middleWidth - 2);
		saveParts[2].setY(maxHeight - 3);
		//[11][17]
		saveParts[3].setX(middleWidth - 2);
		saveParts[3].setY(maxHeight - 2);
	}

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
