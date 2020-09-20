#include "../include/game_play.h"

GamePlay::GamePlay() {
	running();
}

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

	Board *hum_board = new Board();
	Board *com_board = new Board(hum_board->getHeight(), hum_board->getWidth());
	boards.push_back(hum_board);
	boards.push_back(com_board);

	Player *human = new Human();
	Player *computer = new Computer(level);
	players.push_back(human);
	players.push_back(computer);
}

void GamePlay::showResult() const {

}

void GamePlay::play() {

}

void GamePlay::showHighScore() const {

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
		case 0:
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
	}
}

void GamePlay::printMenu() const {
	cout << "BATTLE SHIPS" << endl;
	cout << "1. Play" << endl;
	cout << "2. Show high score" << endl;
	cout << "*************************" << endl;
}

GamePlay::~GamePlay() {
	for (int i = 0; i < (int)players.size(); i++) {
		delete players[i];
		delete boards[i];
	}
}