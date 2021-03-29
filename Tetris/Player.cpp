#include "Player.h"
#include "gotoxy.h"


//player constructor
//Player::Player()
//
//void Square:: setArrowKeys(const char* keys) { // "wzad"
       // arrowKeys[0] = keys[0];
//		arrowKeys[1] = keys[1];
//		arrowKeys[2] = keys[2];
//		arrowKeys[3] = keys[3];
//	}
//
void Player::playerInit(char _playerChar, int _width, int _playerNumber,const char _keys[5])
{
	this->playerChar = _playerChar;
	this->widthDefault = _width;
	this->playerNumber = _playerNumber;
	this->arrowKeys[0] = _keys[0];
	this->arrowKeys[1] = _keys[1];
	this->arrowKeys[2] = _keys[2];
	this->arrowKeys[3] = _keys[3];
	this->arrowKeys[4] = _keys[4];
}

void Player::setDirection(int dir) {
		direction = dir;
}

	int  Player::getDirection(char key){//////
		for (int i = 0; i < 4; i++)
		{
			if (key == arrowKeys[i])
				return i;
		}
		return -1;
	}

	char Player::getPlayerChar() {

		return  playerChar;
	}


	int Player::getWidthDefault() {

		return widthDefault;
	}

	/*
	bool Player:: checkeEndOfBoard(Player player) {///////

		switch (player.getFigure)
		{
		case 1:
			if (checkLocation() != false)
				return 0;
			else//we reach the end of board with this figure
			return true;

			
			break;
		default:
			break;
		}
	}
	*/
	