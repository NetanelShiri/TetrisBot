#pragma once
#pragma warning( push )
#pragma warning( disable : 26451 )
#pragma warning( disable : 26812 )

#include <random>
#include "Point.h"

#include "Tetrominos.h"
#include "SquareShape.h"
#include "LineShape.h"
#include "JShape.h"
#include "LShape.h"
#include "TShape.h"
#include "SkewShape.h"
#include "RSkewShape.h"
#include "Bomb.h"
using std::vector;


class Player {

	enum Tetromino { SquareS, LineS, TS, LS, JS, SkewS, RSkewS , BombS};

	//default player settings
protected:
	Direction direction = Direction::Down;
	char arrowKeys[5];
	int playerNumber = 0;
	int widthDefault = 0;
	int distancing = 0;
	char playerChar = ' ';
	
	//player score monitor
	int score = 0;

	//player shape control
	Tetrominos* tetromino = nullptr;

	//player board control
	int playerBoard[12][18] = { 0 };
	int shapeNumber = 0;
	int trueWidthToArr = ((playerNumber - 1) * distancing);
	bool playerGameOver = false;

public:
	Player() {};
	virtual ~Player();//dtor
	Player& operator=(const Player& other);//operator =
	Player(const Player& a);//copy ctor


	virtual bool playerTurn() = 0;
	bool playerMovement();
	void playerDraw();
	void playerRotateCW();
	void playerRotateCCW();
	void playerInit(char _playerChar,int _width,int _distancing,int _playerNumber,const char _keys[5]);
	

	void tetrominoCreator();
	void replaceTetromino();
	
	//getters
	char getPlayerChar() { return  playerChar; }
	int getPlayerNumber() { return playerNumber; }
	int getWidthDefault() { return widthDefault; }
	int getScore() { return score; }
	Tetrominos* getTetromino() { return tetromino; }
	bool getPlayerState() { return playerGameOver; }
	Direction getDirection(char key);

	//calculations
	void CalculateScore(int lines);
	void PrintScore();
	void checkFullLines();
	void bombLine(int height);
	void clearEmptyLines();

	//setters
	void setDirection(Direction _direction){ this->direction = _direction; }
	void setScore(int _score) { score += _score; }
	
	
	void PlayerBoardTetroUpdate(int number);
	void drawFromPlayerBoard();
	int isLegalMove();
	bool initCheck(Tetrominos *tetromino); //used to determine if game over
	
};