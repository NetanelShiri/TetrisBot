#include "Bot.h"


void Bot::decideDirection()
{
	int k = randomizer(0.0, 4.0);

	switch (k)
	{
	case 0:
		direction = Direction::Left;
		break;
	case 1:
		direction = Direction::Left;
		break;
	case 2:
		direction = Direction::Right;
		break;
	case 3:
		direction = Direction::Right;
		break;
	}
}

bool Bot::playerTurn()
{
	if (!tetromino->getTargetFound())
	{
		
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


	if (stack != 0)
	{
		initiateMovement();
		playerMovement();
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
		while (counter != 14)
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
	//make vector that contains the minimum holes
	while (true)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i].holes == _holes)
			{
				tempHoles.push_back(vec[i]);
			}

		}
		if (tempHoles.size() != 0) { break; }
		_holes++;
	}

	int _height = tempHoles[0].height;
	int place = 0;
	
	
	//now find lowest height out of the minimum holes vector
	for (int i = 0; i < tempHoles.size(); i++)
	{
		if (tempHoles[i].height < _height)
		{
			_height = tempHoles[i].height;
			place = i;
		}
		
	}

	vec.clear();
	vec.push_back(tempHoles[place]);
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
	
	for (int i = 0; i < middleWidth - 1 ; i++)
	{
		for (int j = minHeight ; j < maxHeight-1; j++)
		{
			if (playerBoard[i][j] == 1)
			{
				_height += maxHeight - j - 1;
				break;
			}
		}
	}
	temp.height = _height;
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
		//cout << stack;
	}
	else {
		stackDirection = Direction::Right;
		stack = saveLowest1 - saveLowest2;
		//cout << stack;
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
	//	cout << "( " << saveParts[i].getX() << ',' << saveParts[i].getY() << ")";
	}

	
}

bool Bot::checkUpper(vector<Point>& saveParts, int playerBoard[12][18])
{
	vector<Point> temp = saveParts;
	int y , counter = 0;


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