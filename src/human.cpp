#include "../include/human.h"
#include "../include/input_exception.h"

Human::Human() {
	cin.ignore();
	cout << "Enter your name: "; getline(cin, name);
	total_shots = 0;
	n_target_shots = 0;
	hp = 0;

	createBoard();
	createShips();
}

void Human::choosePosition(int &x, int &y, const vector<vector<int>> matrix, bool &flag) {
	bool choosing = true;
	string s_x, s_y;

	while (choosing) {
		try {
			cout << "Enter x: "; cin >> s_x;	x = stoi(s_x);
			cout << "Enter y: "; cin >> s_y;	y = stoi(s_y);

			if ((x >= (int)matrix.size()) || (y >= (int)matrix[0].size())) {
				throw InputException();
			} else if (matrix[x][y] == -1) {
				cout << "Already got score on this coordinate, try another one" << endl;
			} else {
				choosing = false;
			}
		} catch (InputException ie) {
			cout << ie.what() << endl;
		} catch (...) {
			cout << "Invalid input: coodination must be numbers" << endl;
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
	string s_n_ships;

	while (1) {
		while (choosing) {
			try {
				cout << "Enter number of ships: "; cin >> s_n_ships;	n_ships = stoi(s_n_ships);
				if (n_ships <=0) {throw InputException();}
				else choosing = false;
			} catch (InputException ie) {
				cout << ie.what() << endl;
			} catch (...) {
				cout << "Invalid input: Number of ships must be a number" << endl;
			}
		}

		choosing = true;

		while (choosing) {
			try {
				cout << "Ships: Using default size (1x3)? (y = Yes, n = No): "; cin >> choice;
				if (choice == 'y' || choice == 'Y') {
					for (int i = 0; i < n_ships; i++) {
						Ship *my_ship = new Ship(S_LENGTH, S_WIDTH);
						ships.push_back(my_ship);
					}
					choosing = false;
				} else if (choice == 'n' || choice == 'N') {
					for (int i = 0; i < n_ships; i++) {
						try {
							cout << "Size of Ship[" << i << "] (0:(3x1), 1:(5x1), 2:(7x1)) = "; cin >> choice;
							if (choice != '0' && choice != '1' && choice != '2') {
								i--;
								throw InputException();
							} else if (choice == '0') {
								Ship *my_ship31 = new Ship(3, 1);
								ships.push_back(my_ship31);
							} else if (choice == '1') {
								Ship *my_ship51 = new Ship(5, 1);
								ships.push_back(my_ship51);
							} else if (choice == '2') {
								Ship *my_ship71 = new Ship(7, 1);
								ships.push_back(my_ship71);
							}
						} catch (InputException ie) {
							cout << ie.what() << endl;
						}
					}
					choosing = false;
				} else {
					throw InputException();
				}
			} catch (InputException ie) {
				cout << ie.what() << endl;
			}
		}

		for (int i = 0; i < ships.size(); i++) {
			hp += ships[i]->getLength() * ships[i]->getWidth();
		}
		cout << "hp: " << hp << endl;

		if (hp <= (board->getHeight() * board->getWidth())) {
			break;
		} else {
			cout << "Could not put ships on board, please resize the ships" << endl;
			hp = 0;
			choosing = true;
			int size = ships.size();
			for (int i = 0; i < size; i++) {
				delete ships[0];
				ships.erase(ships.begin());
			}
		}
	}
}

Human::~Human() {
	for (int i = 0; i < (int)ships.size(); i++) {
		delete ships[i];
	}
	delete board;
}
