// players[0]: human
// players[1]: computer

// board[0]: board of human
// board[1]: board of computer


#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
	void play();
	void showHighScore() const;
	void option();
	void doTask(const int &choice);
	void printMenu() const;
	void setShipsPosition(Player *player);
	bool checkShipsPosition(const int &x, const int &y, const int &dir, const int &length, vector<vector<int>> &matrix);
	void showUserInfo() const;
	bool checkUp(int x, const int &y, const int &length, vector<vector<int>> &matrix);
	bool checkDown(int x, const int &y, const int &length, vector<vector<int>> &matrix);
	bool checkLeft(const int &x, int y, const int &length, vector<vector<int>> &matrix);
	bool checkRight(const int &x, int y, const int &length, vector<vector<int>> &matrix);
	void shot();
	void setHighScore();
	int getHightScore(const string &line) const;
};

#endif
