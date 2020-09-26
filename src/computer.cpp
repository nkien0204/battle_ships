#include "../include/computer.h"

Computer::Computer() {}

Computer::Computer(const int &level, const Board *hum_board, const vector<Ship *> &hum_ships) {
	name = "COM";
	this->level = level;
	total_shots = 0;
	n_target_shots = 0;
	hp = 0;

	createBoard(hum_board);
	createShips(hum_ships);
}

void Computer::createBoard(const Board *hum_board) {
	board = new Board(*hum_board);
}

void Computer::createShips(const vector<Ship *> &hum_ships) {
	for (int i = 0; i < (int)hum_ships.size(); i++) {
		ships.push_back(hum_ships[i]);
	}

	for (int i = 0; i < ships.size(); i++) {
		hp += ships[i]->getLength() * ships[i]->getWidth();
	}
}

void Computer::choosePosition(int &x, int &y, const vector<vector<int>> matrix) {
	switch(level) {
		case EASY:
			playEasyLv(x, y, matrix);
			break;
		case MEDIUM:
			playMediumLv(x, y, matrix);
			break;
		case HARD:
			playHardLv(x, y, matrix);
			break;
	} 
}

void Computer::playEasyLv(int &x,  int &y, const vector<vector<int>> matrix) {
	bool choosing = true;

	while(choosing) {
		srand(time(NULL));

		x = rand() % (int)matrix.size();
		y = rand() % (int)matrix[0].size();

		if (matrix[x][y] != -1) {
			choosing = false;
		}
	}
}

void Computer::playMediumLv(int &x, int &y, const vector<vector<int>> matrix) {
	cout << "playing in medium level" << endl;
}

void Computer::playHardLv(int &x, int &y, const vector<vector<int>> matrix) {
	cout << "playing in hard level" << endl;
}

Computer::~Computer() {
	for (int i = 0; i < (int)ships.size(); i++) {
		delete ships[i];
	}
	delete board;
}
