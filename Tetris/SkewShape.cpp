#include "SkewShape.h"
#include "Tetrominos.h"

//default ctor
SkewShape::SkewShape() { playerWidth = 0;  playerChar = '#';  }

//square constructor for specific player
SkewShape::SkewShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	rotations = 2;
	initTetromino();
}

//drawing the square
void SkewShape::drawTetromino() {
	
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
	}
}

//setting location in bottom right.	
void SkewShape::initTemporary(int _rotation)
{
	saveParts.resize(4);

	if (_rotation == 1) {
		//[9][16]
		saveParts[0].setX(middleWidth - 4);
		saveParts[0].setY(maxHeight - 3);
		//[10][16]
		saveParts[1].setX(middleWidth - 3);
		saveParts[1].setY(maxHeight - 3);
		//[10][17]
		saveParts[2].setX(middleWidth - 3);
		saveParts[2].setY(maxHeight - 2);
		//[11][17]
		saveParts[3].setX(middleWidth - 2);
		saveParts[3].setY(maxHeight - 2);
	}
	else if (_rotation == 2)
	{
		//[11][15]
		saveParts[0].setX(middleWidth - 2);
		saveParts[0].setY(maxHeight - 4);
		//[11][16]
		saveParts[1].setX(middleWidth - 2);
		saveParts[1].setY(maxHeight - 3);
		//[10][16]
		saveParts[2].setX(middleWidth - 3);
		saveParts[2].setY(maxHeight - 3);
		//[10][17]
		saveParts[3].setX(middleWidth - 3);
		saveParts[3].setY(maxHeight - 2);
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


void SkewShape::RotateCW(int playerBoard[12][18],int distancing)
{
	if (rotateDirection == RotateDirection::Left) {
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[0].getX() + 2);
		saveParts[0].setY(body[0].getY() - 1);
		saveParts[1].setX(body[3].getX());
		saveParts[1].setY(body[3].getY() - 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[0].setX(body[0].getX() + 2);
			body[0].setY(body[0].getY() - 1);
			body[3].setY(body[3].getY() - 1);
			rotateDirection = RotateDirection::Up;
		}
		this->drawTetromino();
	}
	else if(rotateDirection == RotateDirection::Up)
	{
		clearBody();
		saveParts.resize(2);

		saveParts[0].setX(body[0].getX() - 2);
		saveParts[0].setY(body[0].getY() + 1);
		saveParts[1].setX(body[3].getX());
		saveParts[1].setY(body[3].getY() + 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[0].setX(body[0].getX() - 2);
			body[0].setY(body[0].getY() + 1);
			body[3].setY(body[3].getY() + 1);
			rotateDirection = RotateDirection::Left;
		}
		this->drawTetromino();
	}

}

void SkewShape::RotateCCW(int playerBoard[12][18],int distancing) {
	RotateCW(playerBoard,distancing);
}