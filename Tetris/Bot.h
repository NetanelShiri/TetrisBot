#pragma once
#include "Player.h"

constexpr double a = -0.510066;
constexpr double b = 0.760666;
constexpr double c = -0.35663;
constexpr double d = -0.184483;


class Bot : public Player
{   
	struct scenarios{
		int height = 0;				// aggerated height
		int holes = 0;				// holes defined as if an empty space is blocked from above
		int completeLines = 0;		// how many lines completed by scenerios
		int bumpiness = 0;          // absolute value between all two columns
		int rotation = 0;           // which rotation is picked
		double finalValue = 0;         // calculation of all above
		vector<Point> savePts;
	};

	int counter = 0;
	int stack = 1;
	Direction stackDirection = Direction::Down;
	vector<scenarios> vec; 


public:

	//algorithm calculations
	void findHoles();
	void findHeight();
	void findCompletedLines();

	int checkTemporary(vector<Point>& saveParts, int playerBoard[12][18]);
	void setTemporary(vector<Point>& saveParts, int counter);
	bool checkUpper(vector<Point>& saveParts, int playerBoard[12][18]);
	void pathToTarget(vector<Point> &saveParts);
	void addScenario(vector<Point> saveParts, int _rotation);
	void addTempToBoard();
	void sortBestScenarios();

	virtual bool playerTurn();
	void decideDirection();
	void initiateMovement();


};