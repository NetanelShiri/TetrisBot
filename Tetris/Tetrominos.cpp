#include "Tetrominos.h"

Tetrominos::~Tetrominos()
{
	saveParts.clear();
}

void Tetrominos::clearBody()
{
	body[0].draw(' ');
	body[1].draw(' ');
	body[2].draw(' ');
	body[3].draw(' ');
}

void Tetrominos::rainbowBody()
{
	body[0].setColor(0);
	body[1].setColor(1);
	body[2].setColor(2);
	body[3].setColor(3);
}


bool Tetrominos::checkLegal(vector<Point> &saveParts, int playerBoard[12][18], int distancing)
{
	
	int x, y , trueSizeArr;
	for (int i = 0; i < saveParts.size(); i++)
	{
		x = saveParts[i].getX();
		y = saveParts[i].getY();
		trueSizeArr = x - distancing - 1;
		if((trueSizeArr <= 0) || (trueSizeArr >= 12)	
		||(y == 19)|| (y == 0)|| (playerBoard[trueSizeArr][y - 1]) != 0)
		{
			return false;
		}
	}
	return true;
}

void Tetrominos::moveTetromino(Direction direction) {

	clearBody();

	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
}

bool Tetrominos::checkInBorders(vector<Point>& saveParts, int distancing)
{
	int x, y;
	for (int i = 0; i < saveParts.size(); i++)
	{
		x = saveParts[i].getX() - distancing;
		y = saveParts[i].getY();
		

		if ((x <= 0) || ( x >= 13)
			|| (y >= 19) || (y <= 0))
		{
			return false;
		}
	}
	return true;

}
