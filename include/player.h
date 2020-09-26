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
	vector<Ship *> ships;
	Board *board;
	int total_shots;
	int n_target_shots;
	int hp;
public:
	Player();
	void setTotalShots();
	void setNrTargetShots();
	int getTotalShots() const;
	int getNrTargetShots() const;
	int getNrShips() const;
	string getName() const;
	Board *getBoard() const;
	vector<Ship *> getShips() const;
	void setHP(const int &hp);
	int getHP() const;

	virtual void choosePosition(int &x, int &y, const vector<vector<int>> matrix) = 0;
	virtual ~Player();
};

#endif
