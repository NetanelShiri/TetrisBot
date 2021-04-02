#include "LineShape.h"
#include "Tetrominos.h"
using std::cout;
using std::endl;
using std::cin;

//default ctor
LineShape::LineShape() { playerWidth = 0;  playerChar = '#'; }

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

	body[0].draw(' ');
	body[1].draw(' ');
	body[2].draw(' ');
	body[3].draw(' ');

	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
}

void LineShape::RotateCW()
{
	body[0].draw(' ');
	body[1].draw(' ');
	body[2].draw(' ');
	body[3].draw(' ');

	body[0].setX(body[0].getX() + 1);
	body[0].setY(body[0].getY() - 2);
	body[2].setX(body[2].getX() - 1);
	body[2].setY(body[2].getY() - 1);
	body[3].setX(body[3].getX() - 2);
	body[3].setY(body[3].getY() + 1);

	this->drawTetromino();

}





