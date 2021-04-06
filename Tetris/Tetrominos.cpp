#include "Tetrominos.h"



Point* Tetrominos::getPoints()
{
	return body;
}

int Tetrominos::getTetrinomSize()
{
	return int(SIZE);
}

bool Tetrominos::checkLegal(vector<Point> &save, int playerBoard[12][18], int distancing)
{
	int x, y , trueSizeArr;
	for (int i = 0; i < save.size(); i++)
	{
		x = save[i].getX();
		y = save[i].getY();
		trueSizeArr = x - distancing - 1;
		if((trueSizeArr == 0) || (trueSizeArr == 12)	
		||(y == 19)|| (playerBoard[trueSizeArr][y - 1]) != 0)
		{
			return false;
		}
	}

	return true;
}