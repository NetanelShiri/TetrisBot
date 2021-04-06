#include "JShape.h"
#include "Tetrominos.h"
using std::cout;
using std::endl;
using std::cin;

//default ctor
JShape::JShape() { playerWidth = 0;  playerChar = '#'; }


//square constructor for specific player
JShape::JShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	initTetromino();
}

//drawing the square
void JShape::drawTetromino()
{
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
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
	bool value = true;
	vector<Point> save;

	switch (rotateDirection)
	{
	case RotateDirection::Up:
		clearBody();
		save.resize(2);

		save[0].setX(body[2].getX() + 1);
		save[0].setY(body[2].getY() + 1);
		save[1].setX(body[3].getX() + 3);
		save[1].setY(body[3].getY() + 1);

		if (checkLegal(save, playerBoard, distancing))
		{
			cout << "hey1";
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
		save.resize(2);

		save[0].setX(body[0].getX() - 1);
		save[0].setY(body[0].getY() + 2);
		save[1].setX(body[1].getX() - 1);
		save[1].setY(body[1].getY() + 2);

		if (checkLegal(save, playerBoard, distancing))
		{
			cout << "hey2";
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

		save.resize(2);

		save[0].setX(body[2].getX() - 1);
		save[0].setY(body[2].getY() + 2);
		save[1].setX(body[3].getX() - 3);
		save[1].setY(body[3].getY());

		if (checkLegal(save, playerBoard, distancing))
		{
			cout << "hey3";
			body[2].setX(body[2].getX() - 1);
			body[2].setY(body[2].getY() + 2);
			body[3].setX(body[3].getX() - 3);
			rotateDirection = RotateDirection::Left;
		}

		this->drawTetromino();

	
		break;
	case RotateDirection::Left:
		clearBody();

		save.resize(2);

		save[0].setX(body[2].getX() - 1);
		save[0].setY(body[2].getY() - 1);
		save[1].setX(body[3].getX() - 1);
		save[1].setY(body[3].getY() + 1);

		if (checkLegal(save, playerBoard, distancing))
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

		body[2].setX(body[2].getX() + 1);
		body[2].setY(body[2].getY() + 1);
		body[3].setX(body[3].getX() + 1);
		body[3].setY(body[3].getY() - 1);

		this->drawTetromino();

		rotateDirection = RotateDirection::Left;
		break;

	case RotateDirection::Left:
		clearBody();

		body[2].setX(body[2].getX() + 1);
		body[2].setY(body[2].getY() - 2);
		body[3].setX(body[3].getX() + 3);


		this->drawTetromino();

		rotateDirection = RotateDirection::Down;
		break;
	case RotateDirection::Down:
		clearBody();

		body[2].setX(body[2].getX() - 1);
		body[2].setY(body[2].getY() + 2);
		body[3].setX(body[3].getX() - 1);
		body[3].setY(body[3].getY() + 2);


		this->drawTetromino();

		rotateDirection = RotateDirection::Right;
		break;
	case RotateDirection::Right:
		clearBody();

		body[2].setX(body[2].getX() - 1);
		body[2].setY(body[2].getY() - 1);
		body[3].setX(body[3].getX() - 3);
		body[3].setY(body[3].getY() - 1);


		this->drawTetromino();

		rotateDirection = RotateDirection::Up;
		break;
		

	}


}
void JShape::clearBody() {/////

	body[0].draw(' ');
	body[1].draw(' ');
	body[2].draw(' ');
	body[3].draw(' ');
 }

