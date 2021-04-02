#include "Player.h"
#include "gotoxy.h"



void Player::playerInit(char _playerChar, int _width, int _playerNumber,const char _keys[5])
{
	this->playerChar = _playerChar;
	this->widthDefault = _width;
	this->playerNumber = _playerNumber;
	this->arrowKeys[0] = _keys[0]; //Left
	this->arrowKeys[1] = _keys[1]; //Right
	this->arrowKeys[2] = _keys[2]; //Down
	this->arrowKeys[3] = _keys[3]; 
	this->arrowKeys[4] = _keys[4];
}

void Player::playerMovement()
{
	this->tetromino->moveTetromino(direction);
}


void Player::playerDraw()
{
	this->tetromino->drawTetromino();
}

void Player::setDirection(Direction _direction) {
		this->direction = _direction;
}

	Direction Player::getDirection(char key){//////
		for (int i = 0; i < 4; i++)
		{
			if (key == arrowKeys[i])
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

		default:
			tetromino = new SquareShape(this->widthDefault, this->playerChar);
		}

	}

	//returns number between 0 to 6
	int Player::randomizer()
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(0.0, 2.0);

		return (int)dist(mt);
	}