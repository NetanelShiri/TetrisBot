#pragma once
#include "Player.h"


class Bot : public Player
{   
	struct scenarios{
		int height = 0;
		int holes = 0;
		int rotation = 0;
		vector<Point> savePts;
	};

	int counter = 0;
	int stack = 1;
	Direction stackDirection = Direction::Down;
	vector<scenarios> vec; 


public:

	void findHoles();
	void findHeight();
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