#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"
#include "board.h"
#include "ship.h"
#include <time.h>

#define EASY 	'0'
#define MEDIUM 	'1'
#define HARD 	'2'

class Computer : public Player {
private:
	char level;
public:
	Computer();
	Computer(const char &level, const Board *hum_board, const vector<Ship *> &hum_ships);
	void createBoard(const Board *hum_board);
	void createShips(const vector<Ship *> &hum_ships);
	void choosePosition(int &x, int &y, const vector<vector<int>> matrix);
	~Computer();
private:
	void playEasyLv(int &x, int &y, const vector<vector<int>> matrix);
	void playMediumLv(int &x, int &y, const vector<vector<int>> matrix);
	void playHardLv(int &x, int &y, const vector<vector<int>> matrix);
};

#endif
