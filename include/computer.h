#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"
#include "board.h"
#include "ship.h"
#include <time.h>

#define EASY 		0
#define MEDIUM 	1
#define HARD 		2

class Computer : public Player {
private:
	int level;
public:
	Computer();
	Computer(const int &level, const Board *hum_board, const vector<Ship *> &hum_ships);
	void createBoard(const Board *hum_board);
	void createShips(const vector<Ship *> &hum_ships);
	void choosePosition(unsigned int &x,unsigned int &y, const vector<vector<int>> matrix);
	~Computer();
private:
	void playEasyLv(unsigned int &x,unsigned int &y, const vector<vector<int>> matrix);
	void playMediumLv(unsigned int &x,unsigned int &y, const vector<vector<int>> matrix);
	void playHardLv(unsigned int &x,unsigned int &y, const vector<vector<int>> matrix);
};

#endif