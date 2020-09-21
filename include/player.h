#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "ship.h"
#include "board.h"

#define N_SHIPS 3

using namespace std;

class Player {
protected:
	string name;
	static vector<Ship *> ships;
	Board board;
	int total_shots;
	int n_target_shots;
public:
	Player();
	void setTotalShots(const int &total_shots);
	void setNrTargetShots(const int &n_target_shots);
	int getTotalShots() const;
	int getNrTargetShots() const;
	int getNrShips() const;
	vector<Ship *> getShips() const;
	
	virtual void choosePosition(unsigned int &x, unsigned int &y, const vector<vector<int>> matrix) = 0;
	virtual void createShips() = 0;
	virtual ~Player();
};

#endif