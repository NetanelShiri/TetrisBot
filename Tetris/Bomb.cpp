#include "Bomb.h"
#include "Tetrominos.h"

//default ctor
Bomb::Bomb() { playerWidth = 0; playerChar = '#'; }

//square constructor for specific player
Bomb::Bomb(int _width , int _ch)
{
	playerWidth = _width;
	playerChar = bombChar;
	initTetromino();
}

int Bomb::suicide(int playerBoard[12][18], int distancing)
{
	int bombed = 0;
	int dirX, dirY;
	int trueSizeArr;
	saveParts.resize(1);

	//furthest corner 
	dirX = this->getPoints()->getX() - 4;
	dirY = this->getPoints()->getY() - 4;
	

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			saveParts[0].setX(dirX);
			saveParts[0].setY(dirY);

			if (checkInBorders(saveParts, distancing))
			{
				trueSizeArr = dirX - distancing - 1;
				if (playerBoard[trueSizeArr][dirY - 1] == 1) { bombed++; }
				playerBoard[trueSizeArr][dirY - 1] = 0;
				gotoxy(dirX, dirY);
				cout << ' ';
			}
			dirX++;
		}
		dirX -= 9;
		dirY++;
		
	}
	fixBombedLine(playerBoard, distancing);
	return bombed;
}

void Bomb::fixBombedLine(int playerBoard[12][18], int distancing)
{
	int fakeIteration = 0;
	bool flag = false;
	for (int i = minWidth; i < middleWidth - 1; i++)
	{
		for (int j = maxHeight-2; j >= 2; j--)
		{
		
			if (playerBoard[i][j] == 1)
			{
				fakeIteration = (int)j;
				while (true)
				{
					if ((fakeIteration+1) < maxHeight - 1)
					{
						if (playerBoard[i][fakeIteration + 1] == 0) {
							playerBoard[i][fakeIteration] = 0;
							playerBoard[i][fakeIteration + 1] = 1;
							fakeIteration++;
						}
						else { break; }
					}
					else { break; }
				}

			}
			flag = false;
		}
		
	}
}

//drawing the square
void Bomb::drawTetromino() {

	body[0].draw(this->playerChar);
}

//setting location in bottom right.	
void Bomb::initTemporary(int _rotation)
{
	saveParts.resize(1);

	//[11][17]
	saveParts[0].setX(middleWidth - 2);
	saveParts[0].setY(maxHeight - 2);
}

//initialize the square by player location
void Bomb::initTetromino() {

	body[0].setX(this->playerWidth);
	body[0].setY(1);
	body[1].setX(this->playerWidth);
	body[1].setY(1);
	body[2].setX(this->playerWidth);
	body[2].setY(1);
	body[3].setX(this->playerWidth);
	body[3].setY(1);
}

//deleting upper points and relocating the points , and then drawing the deleted points in their new locations
void Bomb::moveTetromino(Direction direction)
{

	clearBody();

	body[0].move(direction);
	body[1].move(direction);
	body[2].move(direction);
	body[3].move(direction);

	this->drawTetromino();
}

void Bomb::RotateCW(int playerBoard[12][18], int distancing)
{
	return;
}

void Bomb::RotateCCW(int playerBoard[12][18], int distancing) {
	return;
}
