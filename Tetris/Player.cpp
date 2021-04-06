#include "Player.h"
#include "gotoxy.h"


void Player::playerInit(char _playerChar, int _width,int _distancing, int _playerNumber,const char _keys[5])
{
	this->playerChar = _playerChar;
	this->widthDefault = _width;
	this->distancing = _distancing;
	this->playerNumber = _playerNumber;
	this->arrowKeys[0] = _keys[0]; //Left
	this->arrowKeys[1] = _keys[1]; //Right
	this->arrowKeys[2] = _keys[2]; //Down
	this->arrowKeys[3] = _keys[3]; //Rotate Clock Wise
	this->arrowKeys[4] = _keys[4]; //Rotate Counter Clock Wise

}

void Player::playerMovement()
{
	
	PlayerBoardTetroUpdate(0);
	int value = isLegalMove();

	if (value == 1)
	{
		if (direction == Direction::RotateC) { playerRotateCW(); } //Rotate Clockwise
		else if (direction == Direction::RotateCC) { playerRotateCCW(); } //Rotate Counter Clockwise
		else { this->tetromino->moveTetromino(direction); }
	}
	else if (value == -1)
	{
		tetromino->drawTetromino();
	}
	PlayerBoardTetroUpdate(1);
	
}

void Player::playerDraw()
{
	
	this->tetromino->drawTetromino();
}

void Player::playerRotateCW()
{
	this->tetromino->RotateCW();
}

void Player::playerRotateCCW()
{
	this->tetromino->RotateCCW();
}

void Player::setDirection(Direction _direction) {
		this->direction = _direction;
}	

	Direction Player::getDirection(char key){
		for (int i = 0; i < 5; i++)
		{
			if (key == arrowKeys[i]|| key == arrowKeys[i]-32)
				return Direction(i);
		}
		return Direction(-1);
	}

	char Player::getPlayerChar() {

		return  playerChar;
	}


	int Player::getWidthDefault() {

		return widthDefault;
	}

	

	void Player::tetrominoCreator()
	{
		int randomNumber = randomizer();

		switch (randomNumber)
		{
		case SquareS:
			tetromino = new SquareShape(this->widthDefault, this->playerChar);
			break;
		case LineS:
			tetromino = new LineShape(this->widthDefault, this->playerChar);
			break;
		case TS:
			tetromino = new TShape(this->widthDefault, this->playerChar);
			break;
		case LS:
			tetromino = new LShape(this->widthDefault, this->playerChar);
			break;
		case JS:
			tetromino = new JShape(this->widthDefault, this->playerChar);
			break;
		case SkewS:
			tetromino = new SkewShape(this->widthDefault, this->playerChar);
			break;
		case RSkewS:
			tetromino = new RSkewShape(this->widthDefault, this->playerChar);
			break;

		default:
			tetromino = new SquareShape(this->widthDefault, this->playerChar);
		}
		
		shapeNumber++;
	}

	void Player::PlayerBoardTetroUpdate(int number)
	{
		Point* pts = tetromino->getPoints();
		int x, y;
		
		for (int i = 0; i < tetromino->getTetrinomSize(); i++)
		{
			x = pts[i].getX();
			y = pts[i].getY();

			
			playerBoard[x-distancing][y] = number;
		}
	}

	void Player::drawFromPlayerBoard()
	{
		for (int i = minWidth + 1; i < middleWidth-1; i++)
		{
			for (int j = minWidth + 1; j < maxHeight-1; j++)
			{
				gotoxy(i + distancing , j);
				if (getXYFromBoard(i, j) == 1)
				{
					cout << playerChar;
				}
			}
		}
	}

	int Player::isLegalMove()
	{
		int x, y , trueToArr;
		int tetSize = tetromino->getTetrinomSize();
		Point* pts = tetromino->getPoints();
	    
		for (int i = 0; i < tetSize; i++)
		{
			
			x = pts[i].getX();
			y = pts[i].getY();
			trueToArr = x - distancing;
		
			switch (direction)
			{
			case Direction::Left:
				if ((playerBoard[trueToArr - 1][y]) != 0 || (trueToArr - 1) == minWidth) { return 0; }
			case Direction::Right:
				if ((playerBoard[trueToArr + 1][y]) != 0 || (trueToArr + 1) == middleWidth) { return 0; }
			case Direction::Down:
				if ((playerBoard[trueToArr][y + 1]) != 0 || (y + 1 == maxHeight)) { return -1; }
			}
		}
		return 1;
	}

	


	//returns number between 0 to 6
	int Player::randomizer()
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(0.0, 7.0);

		return (int)dist(mt);
	}