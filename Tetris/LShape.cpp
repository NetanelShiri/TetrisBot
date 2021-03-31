#include "LShape.h"


//default ctor
LShape::LShape() :playerWidth(0), playerChar('#') {}


//square constructor for specific player
LShape::LShape(int _width, char _ch) : playerWidth(_width), playerChar(_ch)
{
	init();
}

//drawing the square
void LShape::draw() {
	for (int i = 0; i < SIZE; i++) {
		body[i].draw(this->playerChar);
	}

}

//initialize the square by player location
void LShape::init() {
	////top
	//body[0].setX(this->playerWidth);
	//body[0].setY(1);

	//body[1].setX(this->playerWidth + 1);
	//body[1].setY(1);

	////bottom
	//body[2].setX(this->playerWidth);
	//body[2].setY(2);

	//body[3].setX(this->playerWidth + 1);
	//body[3].setY(2);
}

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void LShape::move(Direction direction) {
	body[0].draw(' ');
	body[1].draw(' ');

	body[0].move(direction);
	body[1].move(direction);

	body[2].move(direction);
	body[3].move(direction);

}

//body[SIZE - 1].draw(' ');
//	for (int i = SIZE - 1; i > 0; i--)
//	{
//		body[i] = body[i - 1];
//	}
//	body[0].move(direction);
//	setTextColor(color);
//	body[0].draw(figure);


