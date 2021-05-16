#include "LineShape.h"
#include "Tetrominos.h"

//default ctor
LineShape::LineShape() { playerWidth = 0;  playerChar = '#'; rotateDirection = RotateDirection::Up; }/////// 

//square constructor for specific player
LineShape::LineShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	rotations = 2;
	initTetromino();
}


//drawing the square
void LineShape::drawTetromino() {
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
	}
}

//setting location in bottom right.	
void LineShape::initTemporary(int _rotation)
{
	saveParts.resize(4);

	if (_rotation == 1){
		
		//[8][17]
		saveParts[0].setX(middleWidth - 5);
		saveParts[0].setY(maxHeight - 2);
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
	else if (_rotation == 2){

		//[11][14]
		saveParts[0].setX(middleWidth - 2);
		saveParts[0].setY(maxHeight - 5);
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
void LineShape::initTetromino() {

	//line
	body[0].setX(this->playerWidth - 1);
	body[0].setY(1);

	body[1].setX(this->playerWidth);
	body[1].setY(1);

	body[2].setX(this->playerWidth + 1);
	body[2].setY(1);

	body[3].setX(this->playerWidth + 2);
	body[3].setY(1);
}


void LineShape::RotateCW(int playerBoard[12][18],int distancing)////////
{

	if (rotateDirection == RotateDirection::Left|| rotateDirection == RotateDirection::Right ) {

       clearBody();

	   saveParts.resize(4);

		saveParts[0].setX(body[0].getX() + 1);
		saveParts[0].setY(body[0].getY() - 2);
		saveParts[1].setX(body[2].getX() - 1);
		saveParts[1].setY(body[2].getY());
		saveParts[2].setX(body[2].getX() - 1);
		saveParts[2].setY(body[2].getY() - 1);
		saveParts[3].setX(body[3].getX() - 2);
		saveParts[3].setY(body[3].getY() + 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{


			body[0].setX(body[0].getX() + 1);
			body[0].setY(body[0].getY() - 2);
			body[1].setX(body[2].getX() - 1);
			body[1].setY(body[2].getY());
			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() - 1);
			body[3].setX(body[3].getX() - 2);
			body[3].setY(body[3].getY() + 1);
			rotateDirection = RotateDirection::Down;

		}
		this->drawTetromino();

	}
	else if(rotateDirection== RotateDirection::Up|| rotateDirection == RotateDirection::Down){

		clearBody();
		saveParts.resize(4);

		saveParts[0].setX(body[0].getX() - 1);
		saveParts[0].setY(body[0].getY() + 2);
		saveParts[1].setX(body[0].getX() + 1);
		saveParts[1].setY(body[0].getY());
		saveParts[2].setX(body[2].getX() + 1);
		saveParts[2].setY(body[2].getY() + 1);
		saveParts[3].setX(body[3].getX() + 2);
		saveParts[3].setY(body[3].getY() - 1);

		if (checkLegal(saveParts, playerBoard, distancing))
		{
			body[0].setX(body[0].getX() - 1);
			body[0].setY(body[0].getY() + 2);
			body[1].setX(body[0].getX() + 1);
			body[1].setY(body[0].getY());
			body[2].setX(body[2].getX() + 1);
			body[2].setY(body[2].getY() + 1);
			body[3].setX(body[3].getX() + 2);
			body[3].setY(body[3].getY() - 1);
			rotateDirection = RotateDirection::Right;
		}
		this->drawTetromino();

		

	}

}
void LineShape::RotateCCW(int playerBoard[12][18], int distancing) {
	RotateCW(playerBoard,distancing);
}




