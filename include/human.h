#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player {
public:
	Human();
	void choosePosition(int &x, int &y, const vector<vector<int>> matrix, bool &flag);
	void createShips();
	void createBoard();
	~Human();
};

#endif
