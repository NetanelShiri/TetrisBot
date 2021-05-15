#include "Bot.h"


void Bot::decideDirection()
{
	int k = randomizer(0.0, 2.0);

	switch (k)
	{
	case 0:
		direction = Direction::Left;
		break;
	case 1:
		direction = Direction::Right;
		break;
	default:
		direction = Direction::Left;
	}
}

bool Bot::randomError()
{
	int margin = 0;
	switch (level)
	{
	case NOVICE:
		margin = randomizer(0.0, 10.0);
		cout << margin;
		if (margin == 1)
		{
			stack = randomizer(0.0, 5.0);
			return true;
		}
		break;		
	case GOOD:
		margin = randomizer(0.0, 40.0);
		if (margin == 10) 
		{ 
			stack = randomizer(0.0, 5.0);
			return true;
		}
		break;
	case BEST:
		break;
	}
	return false;
}

bool Bot::playerTurn()
{

	if (!tetromino->getTargetFound())
	{
		if (randomError()) {
			tetromino->setTargetFound(true);
		}
		else {
			vec.clear();
			addTempToBoard();
			sortBestScenarios();

			if (vec[0].rotation > 1)
			{
				playerMovement();
				playerMovement();

				for (int i = 0; i < vec[0].rotation - 1; i++)
				{
					direction = Direction::RotateC;
					playerMovement();
				}
			}

			pathToTarget(vec[0].savePts);
			tetromino->setTargetFound(true);
		}
	}

	int random = randomizer(2.0, 4.0);

	for (int i = 0; i < random; i++)
	{
		if (stack != 0)
		{
			initiateMovement();
			playerMovement();
		}
	}
	
	direction = Direction::Down;
	return playerMovement();
}

void Bot::addTempToBoard()
{
	int legal = 0;
	int counter = 0;
	vector<Point> &temp = tetromino->getSaveParts();
	
	for (int i = 0; i < tetromino->getRotationSize(); i++)
	{
		tetromino->initTemporary(i+1);
		while (counter != 16)
		{
			legal = checkTemporary(temp, playerBoard);
			if (legal == -1)
			{
				counter++;
				tetromino->initTemporary(i+1);

				for (int i = 0; i < temp.size(); i++)
				{
					temp[i].setY(temp[i].getY() - counter);
				}

			}
			else if (legal == 1)
			{
				for (int i = 0; i < temp.size(); i++)
				{
					playerBoard[temp[i].getX()][temp[i].getY()] = 1;
				}

				addScenario(temp,i+1);
				findHoles();
				findHeight();
				findCompletedLines();

				for (int i = 0; i < temp.size(); i++)
				{
					playerBoard[temp[i].getX()][temp[i].getY()] = 0;
				}
			}

			if (legal != -1)
			{
				for (int i = 0; i < temp.size(); i++)
				{
					temp[i].move(Direction::Left);
				}
			}

		}
		counter = 0;
	}

}

//sorting all vectors by height and holes
void Bot::sortBestScenarios()
{
	vector<scenarios> tempHoles;
	int _holes = 0;
	int place = 0;
	double result = INT_MIN;
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].finalValue = (vec[i].height * a) + (vec[i].completeLines * b) + (vec[i].holes * c) + (vec[i].bumpiness * d);
		if (vec[i].finalValue > result)
		{
			if (checkUpper(vec[i].savePts, playerBoard))
			{
				result = vec[i].finalValue;
				place = i;
			}
		}
	}

	tempHoles.push_back(vec[place]);
	vec.clear();

	vec.push_back(tempHoles[0]);

	
}

void Bot::findCompletedLines()
{
	scenarios& temp = vec.back();
	bool flag = false;
	int lines = 0;
	for (int i = maxHeight - 2; i >= int(minHeight); i--)
	{
		for (int j = middleWidth-2; j >= int(minWidth); j--)
		{
			if (playerBoard[j][i] == 0)
			{
				flag = false;
				break;
			}
			else if (j == minWidth) { flag = true; }

		}
		if (flag)
		{
			lines++;
		}
	}
	temp.completeLines = lines;
}

void Bot::findHoles()
{
	scenarios &temp = vec.back();
	int _holes = 0;
	for (int i = middleWidth - 2; i >= 0 ; i--)
	{
		for (int j = maxHeight - 2; j >= 2; j--)
		{
			if (playerBoard[i][j] == 0)
			{
				if (playerBoard[i][j - 1] == 1) { _holes++; }
			}
		}
	}
	temp.holes = _holes;
	
}

void Bot::findHeight()
{
	scenarios& temp = vec.back();
	int _height = 0;
	int _bumpiness = 0;
	int _absBumpiness = 0;
	int temp1 = 0;
	int temp2 = 0;
	int* arr = new int[middleWidth - 1]{ 0 };
	
	for (int i = 0; i < middleWidth - 1 ; i++)
	{
		for (int j = minHeight ; j < maxHeight-1; j++)
		{
			if (playerBoard[i][j] == 1)
			{
				_height += maxHeight - j - 1;
				arr[i] = maxHeight - j - 1;
				break;
			}
		}
	
	}
	for (int i = 0; i < middleWidth - 2; i++)
	{
		temp.bumpiness += abs(arr[i + 1] - arr[i]);
	}
	temp.height = _height;
	delete[] arr;
	
}

void Bot::addScenario(vector<Point> saveParts,int _rotation)
{
	int _height = 0;
	int _holes = 0;
	scenarios save;

	save.height = _height;
	save.holes = _holes;
	save.rotation = _rotation;
	save.savePts = saveParts;

	vec.push_back(save);

}


void Bot::pathToTarget(vector<Point> &saveParts)
{

	Point* tempBody = tetromino->getPoints();
	int x;


	int saveLowest1 = INT_MAX;
	int saveLowest2 = INT_MAX;
	for (int i = 0; i < saveParts.size(); i++)
	{
		x = tempBody[i].getX() - distancing - 1;
		if (saveParts[i].getX() < saveLowest1)
		{
			saveLowest1 = saveParts[i].getX();
		}

		if (x < saveLowest2)
		{
			saveLowest2 = x;
		}
	    
	}
	
	if (saveLowest1 < saveLowest2)	{
		stackDirection = Direction::Left;
		stack = saveLowest2 - saveLowest1;
	}
	else {
		stackDirection = Direction::Right;
		stack = saveLowest1 - saveLowest2;
	}

}



int Bot::checkTemporary(vector<Point>& saveParts, int playerBoard[12][18])
{
	int state = 1;
	for (int i = 0; i < saveParts.size(); i++)
	{
		if (saveParts[i].getY() >= maxHeight - 1 || saveParts[i].getY() < minHeight
			|| saveParts[i].getX() < minWidth || saveParts[i].getX() >= middleWidth - 1)
		{
			state = -1;
			break;
		}

		if (playerBoard[saveParts[i].getX()][saveParts[i].getY()] == 1)
		{
			state = 0;
		}
	}
	return state;
}

void Bot::setTemporary(vector<Point>& saveParts, int counter)
{
	int x, y, i;
	for (i = 0; i < saveParts.size(); i++)
	{
		y = saveParts[i].getY();
		x = saveParts[i].getX();
		saveParts[i].setY(y - 1);
		saveParts[i].setX(x + counter);
	}

	
}

bool Bot::checkUpper(vector<Point>& saveParts, int playerBoard[12][18])
{
	vector<Point> temp = saveParts;
	int y, counter = 0;


	while (true)
	{
		counter++;
		if (counter == maxHeight - 5) { return true; }
		for (int i = 0; i < saveParts.size(); i++)
		{
			y = temp[i].getY();
			temp[i].setY(y - 1);
			if (y == minHeight)
			{
				return true;
			}
			if (playerBoard[temp[i].getX()][temp[i].getY()] == 1)
			{
				return false;
			}
		}

	}

}


void Bot::initiateMovement()
{
	direction = stackDirection;
	stack--;
}