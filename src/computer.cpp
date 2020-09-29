#include "../include/computer.h"
#include "../include/game_play.h"

Computer::Computer() {}

Computer::Computer(const char &level, const Board *hum_board, const vector<Ship *> &hum_ships) {
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

void Computer::choosePosition(int &x, int &y, const vector<vector<int>> matrix, bool &flag) {
	srand(time(NULL));
	switch(level) {
		case EASY:
			playEasyLv(x, y, matrix);
			break;
		case MEDIUM:
			playMediumLv(x, y, matrix, flag);
			break;
		case HARD:
			playHardLv(x, y, matrix, flag);
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

void Computer::playMediumLv(int &x, int &y, const vector<vector<int>> matrix, bool &flag) {
	if (flag == true) {
		int choice = rand() % 4 + 2;
		switch (choice) {
			case UP:
				if (x != 0) {
					x--;
					break;
				}
			case DOWN:
				if (x < matrix.size() - 1) {
					x++;
					break;
				}
			case LEFT:
				if (y != 0) {
					y--;
					break;
				}
			case RIGHT:
				if (y < matrix[0].size() - 1) {
					y++;
					break;
				}
			default:
				break;
		}
	} else {
		playEasyLv(x, y, matrix);
	}

}

void Computer::playHardLv(int &x, int &y, const vector<vector<int>> matrix, bool &flag) {
	vector<vector<int>> temp_matrix(matrix.size(), vector<int> (matrix[0].size(), 2));
	int choice = rand() % 4 + 2;
	int i = 0;
	if (flag == true) {
		while (i < 2) {
			choice = rand() % 4 + 2;
			if (choice == UP) {
				if (x != 0) {
					if (matrix[x-1][y] == 1) {
						x--;
						temp_matrix[x][y] = matrix[x][y];
						break;
					} else if (i < 2) {
						i++;
					}
				}
			} else if (choice == DOWN) {
				if (x < matrix.size() - 1) {
					if (matrix[x+1][y] == 1) {
						x++;
						temp_matrix[x][y] = matrix[x][y];
						break;
					} else if (i < 2) {
						i++;
					}
				}
			} else if (choice == LEFT) {
				if (y != 0) {
					if (matrix[x][y - 1] == 1) {
						y--;
						temp_matrix[x][y] = matrix[x][y];
						break;
					} else if (i < 2) {
						i++;
					}
				}
			} else if (choice == RIGHT) {
				if (y < matrix[0].size() - 1) {
					if (matrix[x][y+1] == 1) {
						y++;
						temp_matrix[x][y] = matrix[x][y];
						break;
					} else if (i < 2) {
						i++;
					}
				}
			}

			if (i == 2) {
				playEasyLv(x, y, matrix);
			}
		}
	} else {
		while (1) {
			playEasyLv(x, y, matrix);
			if (temp_matrix[x][y] == 2) {
				break;
			}
		}
	}
}

Computer::~Computer() {
	for (int i = 0; i < (int)ships.size(); i++) {
		delete ships[i];
	}
	delete board;
}
