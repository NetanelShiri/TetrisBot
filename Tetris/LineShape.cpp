#include "LineShape.h"
#include "Tetrominos.h"

//default ctor
LineShape::LineShape() { playerWidth = 0;  playerChar = '#'; rotateDirection = RotateDirection::Up; }/////// 

//square constructor for specific player
LineShape::LineShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	initTetromino();
}

//drawing the square
void LineShape::drawTetromino() {
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
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

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void LineShape::moveTetromino(Direction direction) {

	clearBody();

	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
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





