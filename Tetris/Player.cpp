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

bool Player::playerMovement()
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
	
		return true;
	}
	PlayerBoardTetroUpdate(1);
	
	return false;
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

	Direction Player::getDirection(char key){
		for (int i = 0; i < 5; i++)
		{
			if (key == arrowKeys[i]|| key == arrowKeys[i]-32)
				return Direction(i);
		}
		return Direction(-1);
	}
	

	void Player::tetrominoCreator()
	{
		
		int randomNumber = randomizer(0.0 ,7.0);
		int bombChance = randomizer(0.0, 20.0);
		if (bombChance == 10) { randomNumber = BombS; }

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
		case BombS:
     		tetromino = new Bomb(this->widthDefault,this->playerChar);
		 	break;
		
		default:
			tetromino = new SquareShape(this->widthDefault, this->playerChar);
		}
		if (!initCheck(tetromino))
		{
			playerGameOver = true;
			return;
		}
		if (mode == 1) { tetromino->rainbowBody(); }

		tetromino->drawTetromino();
		shapeNumber++;
	}

	void Player::replaceTetromino()
	{
		//for bomb type, explode + setscore + clear all empty lines
		if (typeid(*tetromino) == typeid(Bomb))
		{
			int bombed = dynamic_cast<Bomb*>(tetromino)->suicide(playerBoard,distancing);
			setScore(bombed * 15);
			this->clearEmptyLines();
			this->drawFromPlayerBoard();
		}
		//tetromino->setTargetFound(false);

		delete[] tetromino;
		tetrominoCreator();
	}

	bool Player::initCheck(Tetrominos *tetromino)
	{
		Point pts = *tetromino->getPoints();
		int x = pts.getX();
		int y = pts.getY();
		for (int i = 0; i < tetromino->getTetrinomSize(); i++)
		{
			if (playerBoard[x - distancing - 1][y - 1] == 1) { return false; }
		}
		return true;
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
		static int check = 0;
		for (int i = minWidth; i < middleWidth-1; i++)
		{
			for (int j = minHeight; j < maxHeight-1; j++)
			{
				gotoxy(i + distancing + 1, j + 1);
				if (playerBoard[i][j] == 1)
				{
					if (mode == 1) { color(playerChar, check ); }
					else if (mode == 2) { color(playerChar, -1); }
					else { cout << playerChar; }
					check++;
					if (check == 4) { check = 0; }
				}
				else { cout << ' '; }
			}
		}

		
	}

	int Player::isLegalMove()
	{
		int x, y , trueXToArr ,trueYToArr;
		int tetSize = tetromino->getTetrinomSize();
		Point* pts = tetromino->getPoints();
		
		for (int i = 0; i < tetSize; i++)
		{
			
			x = pts[i].getX();
			y = pts[i].getY();
			trueXToArr = x - distancing - 1;
			trueYToArr = y - 1;
			switch (direction)
			{
			case Direction::Left:
				if ((trueXToArr) == minWidth || (playerBoard[trueXToArr-1][y-1]) != 0) { return 0; }
				break;
			case Direction::Right:
				if (trueXToArr + 1 == middleWidth - 1 || (playerBoard[trueXToArr+1][y-1]) != 0) { return 0; }
				break;
			case Direction::Down:
				if ((y == maxHeight-1) || (playerBoard[trueXToArr][y]) != 0) { return -1; }
				break;
			}
		}
		return 1;
	}

	void Player::checkFullLines()
	{
		bool flag = false;
		int lines = 0;
		int height = int(maxHeight) - 2;
		int width = int(middleWidth) - 2;
		for (int i = height; i >=  int(minHeight); i--)
		{
			for (int j = width; j >= int(minWidth); j--)
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
				bombLine(i);
			    i++;
				this->drawFromPlayerBoard();
				
			}
		}
		if (lines) { CalculateScore(lines); }
	}

	void Player::clearEmptyLines()
	{
		int maximize = 0;
		bool none = true;
		bool flag = false;
		int height = int(maxHeight) - 2;
		int width = int(middleWidth) - 2;
		while (maximize++ != maxHeight)
		{
			for (int i = height; i >= int(minHeight); i--)
			{
				for (int j = width; j >= int(minWidth); j--)
				{
					if (playerBoard[j][i] == 1)
					{
						flag = false;
						break;
					}
					else if (j == minWidth) { flag = true; }

				}
				if (flag)
				{
					bombLine(i);
					break;
				}
				if (flag) { break; }
			}
		}
	}

	void Player::bombLine(int height)
	{
		//drop all other lines from above
		for (int i = height - 1; i >= int(minHeight); i--)
		{
			for (int j = int(middleWidth) - 2; j >= int(minWidth); j--)
			{
				playerBoard[j][i + 1] = playerBoard[j][i];
			}
		}
	}

	void Player::CalculateScore(int lines)
	{
		int score = (int)pow(lines*15, 2);
		this->setScore(score);
		PrintScore();
	}

	void Player::PrintScore()
	{
		int visualChange = 0;
		if (distancing > 0) { visualChange = 3; }

		gotoxy(minWidth + distancing +visualChange, maxHeight + 1);
		cout << 'P' << this->playerNumber << " Score:" << score;
	}

	

	Player:: ~Player()
	{
	
		delete tetromino;
	}

	Player& Player::operator=(const Player& other)
	{
		if (this != &other) {
			direction = other.direction;

			for(int i=0;i<5;i++)
			arrowKeys[i] = other.arrowKeys[i];
		
			for (int i = 0; i < 18; ++i) {
				for (int j = 0; j < 12; ++i)
					playerBoard[j][i] = other.playerBoard[j][i];
			}
			playerNumber =other.playerNumber;
			widthDefault = other.widthDefault;
			distancing = other.distancing;
			playerChar = other.playerChar;
			score = other.score;
			tetromino = other.tetromino;

			shapeNumber = other.shapeNumber;
			trueWidthToArr = other.trueWidthToArr;
			playerGameOver = other.playerGameOver;
		}
		return *this;

	}

	Player:: Player(const Player& other)
	{
		*this = other;
	//	this->tetrominoCreator();
	}