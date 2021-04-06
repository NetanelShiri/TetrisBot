#include "SquareShape.h"
#include "Tetrominos.h"
using std::cout;
using std::endl;
using std::cin;

//default ctor
SquareShape::SquareShape() { playerWidth = 0;  playerChar = '#'; }

//square constructor for specific player
SquareShape::SquareShape(int _width, char _ch)
{
	playerWidth = _width;
	playerChar = _ch;
	initTetromino();
}

//drawing the square
void SquareShape::drawTetromino() {
	for (int i = 0; i < SIZE; i++) {
		 body[i].draw(this->playerChar);
	}

}

//initialize the square by player location
void SquareShape::initTetromino(){

	//top
	body[0].setX(this->playerWidth);
	body[0].setY(1); 

	body[1].setX(this->playerWidth+1);
	body[1].setY(1);

	//bottom
	body[2].setX(this->playerWidth);
	body[2].setY(2);

	body[3].setX(this->playerWidth+1);
	body[3].setY(2);
}

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void SquareShape::moveTetromino(Direction direction) {
  
	clearBody();

	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);		

	this->drawTetromino();
}


void SquareShape::RotateCW(int playerBoard[12][18],int distancing)
{
	return;

}





void SquareShape::clearBody()
{
	body[0].draw(' ');
	body[1].draw(' ');
	body[2].draw(' ');
	body[3].draw(' ');
}


void SquareShape::RotateCCW(int playerBoard[12][18],int distancing)
{
	return;
}