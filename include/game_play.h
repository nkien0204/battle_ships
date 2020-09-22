// players[0]: human
// players[1]: computer

// board[0]: board of human
// board[1]: board of computer


#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include <iostream>
#include <vector>
#include "board.h"
#include "player.h"
#include "menu.h"
#include "human.h"
#include "computer.h"

#define HUMAN 	0
#define COM   	1

#define UP 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5

using namespace std;

class GamePlay : public Menu {
private:
	vector<Board *> boards;
	vector<Player *> players;
	bool turn;
public:
	GamePlay();
	~GamePlay();
private:
	int getLevel() const;
	void initialize();
	void initEasy(const int &level);
	void initMedium(const int &level);
	void initHard(const int &level);
	void showResult() const;
	void play();
	void showHighScore() const;
	void option();
	void doTask(const int &choice);
	void printMenu() const;
	void setShipsPosition(Player *player);
	bool checkShipsPosition() const;
	void showUserInfo() const;
};

#endif