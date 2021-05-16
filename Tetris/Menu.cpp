#include "Menu.h"
#include "Tetris.h"



bool Menu::modeMenu(Tetris &tet)
{
	clearKeyboardBuffer();
	char key;
	string gameSpeedPhrase = "(4) Set game speed : ";
	string gameSpeedLevel = tet.setGameSpeed();

	system("cls");
	cout << "Pick Mode:  (Press Number) " << endl;
	cout << "(1) Normal Mode" << endl;
	cout << "(2) Rainbow Mode" << endl;
	cout << "(3) Epilepsy Mode | WARNING: This mode contains flashing lights which\n "
		"	          | May not be suitable for photosensitive epilepsy." << endl << endl;

	cout << gameSpeedPhrase <<tet.getLevel() << ' ' << gameSpeedLevel << endl << endl;


	cout << "(0) Return to main menu " << endl;

	do {
		key = _getch();
		while (_kbhit())
		{
			Sleep(200);
		}
		if (key == '4') {
			gotoxy(0, 6);
			for (int i = 0; i < gameSpeedPhrase.length() + gameSpeedLevel.length() + 5; i++) { cout << ' '; }
			gameSpeedLevel = tet.setGameSpeed();
			gotoxy(0, 6);
			cout << gameSpeedPhrase << tet.getLevel() << ' ' << gameSpeedLevel;
		}
	} while ((key != '1') && (key != '2') && (key != '3') && (key != '0'));

	system("cls");
	switch (key)
	{
	case '1':
		mode = 0;
		break;
	case '2':
		mode = 1;
		break;
	case '3':
		mode = 2;
		break;
	case '0':
		return false;
		break;
	default:
		break;
	}
	return true;
}

//calculate the players scores
void Menu::scoreBoard(Tetris &tet)
{
	vector<pair<int, int>> scores;
	int i = 0;

	cout << endl << "~~~~~~Scoreboard~~~~~" << endl;
	for (int i = 0; i < tet.getPlayersAmount(); i++)
	{
		scores.push_back(make_pair(tet.getPlayers()[i]->getScore(),tet.getPlayers()[i]->getPlayerNumber()));
	}
	sort(scores.rbegin(), scores.rend());

	for (auto it : scores) {
		cout << ++i << ".Player " << it.second << " score is : " << it.first << endl;
	}
	cout << endl;
}

void Menu::instructions()
{
	clearKeyboardBuffer();
	system("cls");
	cout << "          Player 1 keys            Player 2 keys" << endl;
	cout << "Left         A or a                    j or J     " << endl;
	cout << "Right        D or d                    l or L     " << endl;
	cout << "Rotate       S or s                    k or K     " << endl;
	cout << "cRotate      W or w                    i or I     " << endl;
	cout << "Accelerate   X or x                    m or M     " << endl << endl;

	cout << "Press any key to return";

	while (!_kbhit())
	{
		Sleep(200);
	}
	system("cls");
	return;

}

bool Menu::botMenu(Tetris &tet)
{
	clearKeyboardBuffer();
	char key;
	int numberKey;

	system("cls");
	cout << "Pick Level:  (Press Number) " << endl;
	cout << "(1) Novice" << endl;
	cout << "(2) Good" << endl;
	cout << "(3) Best" << endl;

	cout << "(0) Return to main menu " << endl;
	do {
		key = _getch();
		while (_kbhit())
		{
			Sleep(200);
		}
	} while ((key != '1') && (key != '2') && (key != '3') && (key != '0'));

	numberKey = key - '0';
	switch (key)
	{
	case '1':
	case '2':
	case '3':
		if ((int)tet.getType() == 1) { dynamic_cast<Bot*>(tet.getPlayers()[1])->setLevel(numberKey); }
		else if ((int)tet.getType() == 2) {
			dynamic_cast<Bot*>(tet.getPlayers()[0])->setLevel(numberKey);
			dynamic_cast<Bot*>(tet.getPlayers()[1])->setLevel(numberKey);
		}
		break;
	case '0':
		return false;
		break;
	default:
		break;
	}
	return true;
}
