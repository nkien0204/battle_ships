#include "../include/human.h"

Human::Human() {
	cout << "Enter your name: "; cin >> name;
	total_shots = 0;
	n_target_shots = 0;

	createBoard();
	createShips();
}

void Human::choosePosition(int &x, int &y, const vector<vector<int>> matrix) {
	bool choosing = true;

	while (choosing) {
		cout << "Enter x: "; cin >> x;
		cout << "Enter y: "; cin >> y;

		if ((x >= (int)matrix.size()) || (y >= (int)matrix[0].size())) {
			cout << "Invalid coordinate" << endl;
		} else if (matrix[x][y] == -1) {
			cout << "Already got score on this coordinate, try another one" << endl;
		} else {
			choosing = false;
		}
	}
}

void Human::createBoard() {
	board = new Board();
}

void Human::createShips() {
	char choice;
	bool choosing = true;
	int n_ships;

	while (choosing) {
		cout << "Enter number of ships: "; cin >> n_ships;
		if (n_ships <=0) {cout << "Invalid number of ships, try again" << endl;}
		else choosing = false;
	}

	choosing = true;

	while (choosing) {
		Ship *my_ship = NULL;
		cout << "Ships: Using default size (1x3)? (y = Yes, n = No): "; cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			for (int i = 0; i < n_ships; i++) {
				my_ship = new Ship(S_LENGTH, S_WIDTH);
				ships.push_back(my_ship);
			}
			choosing = false;
		} else if (choice == 'n' || choice == 'N') {
			for (int i = 0; i < n_ships; i++) {
				cout << "Size of Ship[" << i << "] (0:(3x1), 1:(5x1), 2:(7x1)) = "; cin >> choice;
				if (choice != '0' && choice != '1' && choice != '2') {
					cout << "Invalid choice, try again" << endl;
					i--;
				} else if (choice == '0') {
					my_ship = new Ship(3, 1);
					ships.push_back(my_ship);
				} else if (choice == '1') {
					my_ship = new Ship(5, 1);
					ships.push_back(my_ship);
				} else if (choice == '2') {
					my_ship = new Ship(7, 1);
					ships.push_back(my_ship);
				}
			}
			choosing = false;
		}
	}
}

Human::~Human() {
	for (int i = 0; i < (int)ships.size(); i++) {
		delete ships[i];
	}
	delete board;
}
