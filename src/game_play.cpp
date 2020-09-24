#include "../include/game_play.h"

GamePlay::GamePlay() {}

void GamePlay::initialize() {
	int level;
	bool choosing = true;

	while(choosing) {
		cout << "Choose level (0: EASY, 1: MEDIUM, 2:HARD): "; cin >> level;
		if (level != 0 && level != 1 && level != 2) {
			cout << "Invalid level, try again" << endl;
		} else {
			choosing = false;
		}
	}

	Player *human = new Human();
	Player *computer = new Computer(level, human->getBoard(), human->getShips());

	players.push_back(human);
	players.push_back(computer);
}

void GamePlay::setShipsPosition(Player *player) {
	for (int i = 0; i < (int)player->getNrShips(); i++) {
		srand(time(NULL));
		int x = rand() % player->getBoard()->getHeight();
		int y = rand() % player->getBoard()->getWidth();
		vector<vector<int>> matrix = player->getBoard()->getMatrix();
		Ship *ship = player->getShips()[i];

		//2:UP, 3:DOWN, 4:LEFT, 5:RIGHT
		int direction = rand() % 6 + 2;

		if (!checkShipsPosition(x, y, direction, ship->getLength(), matrix)) {
			i--;
		}

		delete ship;
	}
}

bool GamePlay::checkShipsPosition(const int &x, const int &y, const int &dir, const int &len, vector<vector<int>> &matrix) {
	bool check;

	switch (dir) {
		case UP:
			check = checkUp(x, y, len, matrix);
			break;
		case DOWN:
			check = checkDown(x, y, len, matrix);
			break;
		case LEFT:
			check = checkLeft(x, y, len, matrix);
			break;
		case RIGHT:
			check = checkRight(x, y, len, matrix);
			break;
		default:
			check = false;
			break;
	}

	return check;
}

bool GamePlay::checkUp(int x, const int &y, const int &len, vector<vector<int>> &matrix) const {
	for (int i = 0; i < len; i++, x--) {
		if (x < 0 || matrix[x][y] != 0) {
			return false;
		}
	}

	for (int i = 0; i < len; i++, x++) {
		matrix[x][y] = 1;
	}

	return true;
}

bool GamePlay::checkDown(int x, const int &y, const int &len, vector<vector<int>> &matrix) const {
	for (int i = 0; i < len; i++, x++) {
		if (x >= (int)matrix.size() || matrix[x][y] != 0) {
			return false;
		}
	}

	for (int i = 0; i < len; i++, x--) {
		matrix[x][y] = 1;
	}

	return true;
}

bool GamePlay::checkLeft(const int &x, int y, const int &len, vector<vector<int>> &matrix) const {
	for (int i = 0; i < len; i++, y--) {
		if (y < 0 || matrix[x][y] != 0) {
			return false;
		}
	}

	for (int i = 0; i < len; i++, y++) {
		matrix[x][y] = 1;
	}

	return true;
}

bool GamePlay::checkRight(const int &x, int y, const int &len, vector<vector<int>> &matrix) const {
	for (int i = 0; i < len; i++, y++) {
		if (y >= (int)matrix[0].size() || matrix[x][y] != 0) {
			return false;
		}
	}

	for (int i = 0; i < len; i++, y--) {
		matrix[x][y] = 1;
	}

	return true;
}

void GamePlay::showResult() const {
	cout << "Show result" << endl;
}

void GamePlay::play() {
	cout << "Playing" << endl;
}

void GamePlay::showHighScore() const {
	cout << "Show high score" << endl;
}

void GamePlay::showUserInfo() const {
	for (int i = 0; i < (int)players.size(); i++) {
		cout << "--------------------" << endl;

		if (i == HUMAN) {
			cout << "HUMAN" << endl;
		} else {
			cout << "COMPUTER" << endl;
		}

		cout << "Name: " << players[i]->getName() << endl;
		cout << "Amount of ships(size): " << players[i]->getNrShips() 
			<< "(" << players[i]->getShips()[0]->getLength() << "x" << players[i]->getShips()[0]->getWidth() << ")" << endl;
		cout << "Board data: "
			<< "Size: " << players[i]->getBoard()->getHeight() << "x" << players[i]->getBoard()->getWidth() << endl;
		if (i == HUMAN) {
			cout << "Board status:" << endl;
			players[HUMAN]->getBoard()->showMatrix();
		}
	}
}

void GamePlay::doTask(const int &choice) {
	switch(choice) {
		case 1:
			initialize();
			play();
			showResult();
			break;
		case 2:
			showHighScore();
			break;
		case 3:
			showUserInfo();
			break;
		case 0:
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
	}
}

void GamePlay::printMenu() const {
	cout << "###################################" << endl;
	cout << "BATTLE SHIPS" << endl;
	cout << "1. Play" << endl;
	cout << "2. Show high score" << endl;
	cout << "3. Show user info" << endl;
	cout << "*************************" << endl;
}

GamePlay::~GamePlay() {
	for (int i = 0; i < (int)players.size(); i++) {
		delete players[i];
	}
}
