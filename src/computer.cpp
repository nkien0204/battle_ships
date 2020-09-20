#include "../include/computer.h"

Computer::Computer() {}

Computer::Computer(const int &level) {
	name = "COM";
	this->level = level;
	total_shots = 0;
	n_target_shots = 0;
}

void Computer::createShips() {}

void Computer::choosePosition(unsigned int &x, unsigned int &y, const vector<vector<int>> matrix) {
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

void Computer::playEasyLv(unsigned int &x, unsigned int &y, const vector<vector<int>> matrix) {
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

void Computer::playMediumLv(unsigned int &x, unsigned int &y, const vector<vector<int>> matrix) {

}

void Computer::playHardLv(unsigned int &x, unsigned int &y, const vector<vector<int>> matrix) {

}

Computer::~Computer() {
	for (int i = 0; i < (int)ships.size(); i++) {
		delete ships.at(i);
	}
}