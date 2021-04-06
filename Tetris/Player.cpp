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
		PlayerBoardTetroUpdate(1);
		tetromino->drawTetromino();
		replaceTetromino();
		return;
	}
	PlayerBoardTetroUpdate(1);
	
}

void Player::playerDraw()
{
	
	this->tetromino->drawTetromino();
}

void Player::playerRotateCW()
{
	this->tetromino->RotateCW(playerBoard,distancing);
}

void Player::playerRotateCCW()
{
	this->tetromino->RotateCCW(playerBoard,distancing);
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
		tetromino->drawTetromino();
		shapeNumber++;
	}

	void Player::replaceTetromino()
	{
		delete[] tetromino;
		tetrominoCreator();
	}

	void Player::PlayerBoardTetroUpdate(int number)
	{
		Point* pts = tetromino->getPoints();
		int x, y;
		
		for (int i = 0; i < tetromino->getTetrinomSize(); i++)
		{
			x = pts[i].getX();
			y = pts[i].getY();
			
			playerBoard[x-distancing-1][y-1] = number;
		}
	}	

	void Player::drawFromPlayerBoard()
	{
		for (int i = minWidth; i < middleWidth-1; i++)
		{
			for (int j = minHeight; j < maxHeight-1; j++)
			{
				gotoxy(i + distancing + 1, j + 1);
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
			trueToArr = x - distancing - 1;

			switch (direction)
			{
			case Direction::Left:
				if ((trueToArr) == minWidth || (playerBoard[trueToArr][y]) != 0) { return 0; }
				break;
			case Direction::Right:
				if ((trueToArr++) == middleWidth - 1 || (playerBoard[trueToArr][y]) != 0) { return 0; }
				break;
			case Direction::Down:
				if ((y == maxHeight-1) || (playerBoard[trueToArr][y]) != 0) { return -1; }
				break;
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