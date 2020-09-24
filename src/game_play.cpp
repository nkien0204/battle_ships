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
	srand(time(NULL));
	for (int i = 0; i < (int)player->getNrShips(); i++) {
		
		int x = rand() % player->getBoard()->getHeight();
		int y = rand() % player->getBoard()->getWidth();
		
		vector<vector<int>> matrix = player->getBoard()->getMatrix();

		//2:UP, 3:DOWN, 4:LEFT, 5:RIGHT
		int direction = rand() % 4 + 2;

		if (!checkShipsPosition(x, y, direction, player->getShips()[i]->getLength(), matrix)) {
			i--;
		}
		player->getBoard()->setMatrix(matrix);
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

bool GamePlay::checkUp(int x, const int &y, const int &len, vector<vector<int>> &matrix) {
	int temp_x = x;
	for (int i = 0; i < len; i++) {
		if (temp_x < 0 || matrix[temp_x][y] != 0) {
			return false;
		} else temp_x--;
	}

	for (int i = 0; i < len; i++, x--) {
		matrix[x][y] = 1;
	}

	return true;
}

bool GamePlay::checkDown(int x, const int &y, const int &len, vector<vector<int>> &matrix) {
	int temp_x = x;
	for (int i = 0; i < len; i++) {
		if (temp_x >= (int)matrix.size() || matrix[temp_x][y] != 0) {
			return false;
		} else temp_x++;
	}

	for (int i = 0; i < len; i++, x++) {
		matrix[x][y] = 1;
	}

	return true;
}

bool GamePlay::checkLeft(const int &x, int y, const int &len, vector<vector<int>> &matrix) {
	int temp_y = y;
	for (int i = 0; i < len; i++) {
		if (temp_y < 0 || matrix[x][temp_y] != 0) {
			return false;
		} else temp_y--;
	}

	for (int i = 0; i < len; i++, y--) {
		matrix[x][y] = 1;
	}

	return true;
}

bool GamePlay::checkRight(const int &x, int y, const int &len, vector<vector<int>> &matrix) {
	int temp_y = y;
	for (int i = 0; i < len; i++) {
		if (temp_y >= (int)matrix[0].size() || matrix[x][temp_y] != 0) {
			return false;
		} else temp_y++;
	}

	for (int i = 0; i < len; i++, y++) {
		matrix[x][y] = 1;
	}

	return true;
}

void GamePlay::showResult() const {
	cout << "Show result" << endl;
}

void GamePlay::play() {
	setShipsPosition(players[HUMAN]);
	setShipsPosition(players[COM]);
}

void GamePlay::showHighScore() const {
	cout << "Show high score" << endl;
}

void GamePlay::showUserInfo() const {
	cout << "--------------------" << endl;

	cout << "Name: " << players[HUMAN]->getName() << endl;
	cout << "Amount of ships(size): " << players[HUMAN]->getNrShips() 
		 << "(" << players[HUMAN]->getShips()[0]->getLength() << "x" << players[HUMAN]->getShips()[0]->getWidth() << ")" << endl;
	cout << "Board data: " << endl;
	cout << "  Size: " << players[HUMAN]->getBoard()->getHeight() << "x" << players[HUMAN]->getBoard()->getWidth() << endl;
	cout << "  Status:" << endl;
	players[HUMAN]->getBoard()->showMatrix();
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
