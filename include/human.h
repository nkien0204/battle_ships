#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player {
public:
	Human();
	void choosePosition(unsigned int &x,unsigned int &y, const vector<vector<int>> matrix);
	void createShips();
	~Human();
};

#endif