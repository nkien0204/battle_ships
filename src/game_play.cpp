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
		int x_hum = rand() % boards[HUMAN]->getHeight();
		int y_hum = rand() % boards[HUMAN]->getWidth();

		int x_com = rand() % boards[COM]->getHeight();
		int y_com = rand() % boards[COM]->getWidth();

		//2:UP, 3:DOWN, 4:LEFT, 5:RIGHT
		int direction_hum = rand() % 6 + 2;
		int direction_com = rand() % 6 + 2;

		vector<vector<int>> hum_matrix = boards[HUMAN]->getMatrix();
		vector<vector<int>> com_matrix = boards[COM]->getMatrix();

		if (hum_matrix[x_hum][y_hum] == 1) {
			i--;
		} //else if ()
	}
}

bool GamePlay::checkShipsPosition() const {}

void GamePlay::showResult() const {

}

void GamePlay::play() {

}

void GamePlay::showHighScore() const {

}

void GamePlay::showUserInfo() const {
	for (int i = 0; i < (int)players.size(); i++) {
		cout << "--------------------" << endl;

		if (i == HUMAN) {
			cout << "HUMAN" << endl;
		} else {
			cout << "COMPUTER" << endl;
		}

		// cout << "Name: " << players[i]->getName() << endl;
		// cout << "Amount of ships(size): " << players[i]->getNrShips() 
		// 	<< "(" << players[i]->getShips()[0]->getLength() << "x" << players[i]->getShips()[0]->getWidth() << ")" << endl;
		// cout << "Board data: "
		// 	<< "Size: " << players[i]->getBoard()->getHeight() << "x" << players[i]->getBoard()->getWidth() << endl;
		// if (i == HUMAN) {
		// 	cout << "Board status:" << endl;
		// 	// players[HUMAN]->getBoard()->showMatrix();
		// }
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
	cout << "free" << endl;
}