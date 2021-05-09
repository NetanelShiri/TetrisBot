#include "JShape.h"
#include "Tetrominos.h"

//default ctor
JShape::JShape() { playerWidth = 0;  playerChar = '#'; }


//square constructor for specific player
JShape::JShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	rotations = 4;
	initTetromino();
}

//drawing the square
void JShape::drawTetromino()
{
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
	}

}

//setting location in bottom right.	
void JShape::initTemporary(int _rotation)
{
	saveParts.resize(4);

	if (_rotation == 1)
	{
		//[11][16]
		saveParts[0].setX(middleWidth - 2);
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

	}else if (_rotation == 2) {
		//[10][15]
		saveParts[0].setX(middleWidth - 3);
		saveParts[0].setY(maxHeight - 4);
		//[10][16]
		saveParts[1].setX(middleWidth - 3);
		saveParts[1].setY(maxHeight - 3);
		//[10][17]
		saveParts[2].setX(middleWidth - 3);
		saveParts[2].setY(maxHeight - 2);
		//[11][17]
		saveParts[3].setX(middleWidth - 2);
		saveParts[3].setY(maxHeight - 2);

	}else if (_rotation == 3) {

		//[9][16]
		saveParts[0].setX(middleWidth - 4);
		saveParts[0].setY(maxHeight - 3);
		//[10][16]
		saveParts[1].setX(middleWidth - 3);
		saveParts[1].setY(maxHeight - 3);
		//[11][16]
		saveParts[2].setX(middleWidth - 2);
		saveParts[2].setY(maxHeight - 3);
		//[9][17]
		saveParts[3].setX(middleWidth - 4);
		saveParts[3].setY(maxHeight - 2);
	}else if (_rotation == 4) {
		//[10][15]
		saveParts[0].setX(middleWidth - 3);
		saveParts[0].setY(maxHeight - 4);
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

//initialize the square by player location
void JShape::initTetromino() 
{

	//line
	body[0].setX(this->playerWidth + 1);
	body[0].setY(1);

	body[1].setX(this->playerWidth + 1);
	body[1].setY(2);

	body[2].setX(this->playerWidth);
	body[2].setY(2);

	body[3].setX(this->playerWidth - 1);
	body[3].setY(2);
}

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void JShape::moveTetromino(Direction direction) {

	clearBody();
	
	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
}

void JShape::RotateCW(int playerBoard[12][18],int distancing)
{

	
	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() + 1);
		saveParts[0].setY(body[2].getY() + 1);
		saveParts[1].setX(body[3].getX() + 3);
		saveParts[1].setY(body[3].getY() + 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[2].setX(body[2].getX() + 1);
			body[2].setY(body[2].getY() + 1);
			body[3].setX(body[3].getX() + 3);
			body[3].setY(body[3].getY() + 1);
			rotateDirection = RotateDirection::Right;
		}
		this->drawTetromino();

		
		break;

	case RotateDirection::Right:
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[0].getX() - 1);
		saveParts[0].setY(body[0].getY() + 2);
		saveParts[1].setX(body[1].getX() - 1);
		saveParts[1].setY(body[1].getY() + 2);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[0].setX(body[0].getX() - 1);
			body[0].setY(body[0].getY() + 2);
			body[1].setX(body[1].getX() - 1);
			body[1].setY(body[1].getY() + 2);
			rotateDirection = RotateDirection::Down;
		}
		this->drawTetromino();

		break;
	case RotateDirection::Down:
		clearBody();

		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() - 1);
		saveParts[0].setY(body[2].getY() + 2);
		saveParts[1].setX(body[3].getX() - 3);
		saveParts[1].setY(body[3].getY());

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() + 2);
			body[3].setX(body[3].getX() - 3);
			rotateDirection = RotateDirection::Left;
		}

		this->drawTetromino();

	
		break;
	case RotateDirection::Left:
		clearBody();

		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() - 1);
		saveParts[0].setY(body[2].getY() - 1);
		saveParts[1].setX(body[3].getX() - 1);
		saveParts[1].setY(body[3].getY() + 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() - 1);
			body[3].setX(body[3].getX() - 1);
			body[3].setY(body[3].getY() + 1);
			rotateDirection = RotateDirection::Up;
		}

		this->drawTetromino();

		rotateDirection = RotateDirection::Up;
		break;

	}

}

void JShape::RotateCCW(int playerBoard[12][18],int distancing)
{
	
	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() + 1);
		saveParts[0].setY(body[2].getY() + 1);
		saveParts[1].setX(body[3].getX() + 1);
		saveParts[1].setY(body[3].getY() - 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[2].setX(body[2].getX() + 1);
			body[2].setY(body[2].getY() + 1);
			body[3].setX(body[3].getX() + 1);
			body[3].setY(body[3].getY() - 1);
			rotateDirection = RotateDirection::Left;
		}

		this->drawTetromino();
		break;

	case RotateDirection::Left:
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() + 1);
		saveParts[0].setY(body[2].getY() - 2);
		saveParts[1].setX(body[3].getX() + 3);
		saveParts[1].setY(body[3].getY());

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[2].setX(body[2].getX() + 1);
			body[2].setY(body[2].getY() - 2);
			body[3].setX(body[3].getX() + 3);
			rotateDirection = RotateDirection::Down;
		}

		this->drawTetromino();
		break;

	case RotateDirection::Down:
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[2].getX() - 1);
		saveParts[0].setY(body[2].getY() + 2);
		saveParts[1].setX(body[3].getX() - 1);
		saveParts[1].setY(body[3].getY() + 2);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() + 2);
			body[3].setX(body[3].getX() - 1);
			body[3].setY(body[3].getY() + 2);
		}

		this->drawTetromino();

		rotateDirection = RotateDirection::Right;
		break;
	case RotateDirection::Right:
		clearBody();

		saveParts[0].setX(body[2].getX() - 1);
		saveParts[0].setY(body[2].getY() - 1);
		saveParts[1].setX(body[3].getX() - 3);
		saveParts[1].setY(body[3].getY() - 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() - 1);
			body[3].setX(body[3].getX() - 3);
			body[3].setY(body[3].getY() - 1);
			rotateDirection = RotateDirection::Up;
		}

		this->drawTetromino();
		break;
		

	}


}


