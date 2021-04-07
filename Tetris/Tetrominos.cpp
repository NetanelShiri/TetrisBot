#include "Tetrominos.h"

Tetrominos::~Tetrominos()
{
	saveParts.clear();
}

Point* Tetrominos::getPoints()
{
	return body;
}

int Tetrominos::getTetrinomSize()
{
	return int(SIZE);
}

bool Tetrominos::checkLegal(vector<Point> &saveParts, int playerBoard[12][18], int distancing)
{
	int x, y , trueSizeArr;
	for (int i = 0; i < saveParts.size(); i++)
	{
		x = saveParts[i].getX();
		y = saveParts[i].getY();
		trueSizeArr = x - distancing - 1;
		if((trueSizeArr == 0) || (trueSizeArr == 12)	
		||(y == 19)|| (playerBoard[trueSizeArr][y - 1]) != 0)
		{
			return false;
		}
	}

	return true;
}