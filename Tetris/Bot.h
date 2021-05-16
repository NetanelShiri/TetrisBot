#pragma once
#include "Player.h"

//my little secret ( GA )
constexpr double a = -0.510066;
constexpr double b = 0.760666;
constexpr double c = -0.35663;
constexpr double d = -0.184483;


class Bot : public Player
{
	enum BotLevel { NOVICE = 1, GOOD, BEST };

	struct scenarios{
		int height = 0;				// aggerated height
		int holes = 0;				// holes defined as if an empty space is blocked from above
		int completeLines = 0;		// how many lines completed by scenerios
		int bumpiness = 0;          // absolute value between all two columns
		int rotation = 0;           // which rotation is picked
		double finalValue = 0;      // calculation of all above
		vector<Point> savePts;
	};

	int counter = 0;
	int stack = 1;
	int level = NOVICE;
	
	Direction stackDirection = Direction::Down;
	vector<scenarios> vec; 


public:
	Bot()=default;

	Bot& operator=(const Bot& other){
		Player::operator=(other);


		for (int i = 0; i < vec.size(); i++) {
			vec[i].height = other.vec[i].height;
			vec[i].holes = other.vec[i].holes;
			vec[i].completeLines = other.vec[i].completeLines;
			vec[i].bumpiness = other.vec[i].bumpiness;

			vec[i].rotation = other.vec[i].rotation;

			vec[i].finalValue = other.vec[i].finalValue;
			
			for (int j = 0; j < vec[i].savePts.size(); j++) {
				vec[i].savePts[j] = other.vec[i].savePts[j];
			}

		}

		counter = other.counter;
		stack = other.stack;
		stackDirection = other.stackDirection;
		     

	};//operator =
	Bot(const Bot& a):Player(a) {};

	//algorithm calculations
	void findHoles();
	void findHeight();
	void findCompletedLines();

	int checkTemporary(vector<Point>& saveParts, int playerBoard[12][18]);
	void setTemporary(vector<Point>& saveParts, int counter);
	void pathToTarget(vector<Point> &saveParts);
	void addScenario(vector<Point> saveParts, int _rotation);
	void addTempToBoard();
	void sortBestScenarios();
	bool randomError();
	void setLevel(int _level) { level = (BotLevel)_level; }
	int  getLevel() { return (int)level; }
	virtual bool playerTurn();
	void decideDirection();
	void initiateMovement();
	bool checkUpper(vector<Point>& saveParts, int playerBoard[12][18]);
	


};