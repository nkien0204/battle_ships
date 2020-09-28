#include "../include/game_play.h"
#include "../include/input_exception.h"

GamePlay::GamePlay() {}

void GamePlay::initialize() {
	char level;
	bool choosing = true;

	while(choosing) {
		try {
			cout << "Choose level (0: EASY, 1: MEDIUM, 2:HARD): "; cin >> level;	
			if (level != '0' && level != '1' && level != '2') {
				throw InputException();
			} else {
				choosing = false;
			}
		} catch (InputException e) {
			cout << e.what() << endl;
		}
	}

	Player *human = new Human();
	Player *computer = new Computer(level, human->getBoard(), human->getShips());

	players.push_back(human);
	players.push_back(computer);
}

void GamePlay::setShipsPosition(Player *player) {
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

void GamePlay::play() {
	bool running = true;

	srand(time(NULL));
	setShipsPosition(players[HUMAN]);
	setShipsPosition(players[COM]);
	
	shot();
}

void GamePlay::shot() {
	bool turn = HUMAN;
	bool running = true;
	int x, y;
	string s_x, s_y;

	while (running) {
		vector<vector<int>> matrix = players[!turn]->getBoard()->getMatrix();
		
		cout << "human board" << endl;
		players[HUMAN]->getBoard()->showMatrix();

		cout << "computer board" << endl;
		players[COM]->getBoard()->showMatrix();

		if (turn == HUMAN) {
			bool choosing = true;
			while (choosing) {
				try {
					cout << "Enter shot coordination:" << endl;
					cout << "  x: "; cin >> s_x;	x = stoi(s_x);
					cout << "  y: "; cin >> s_y;	y = stoi(s_y);
					if (x >= (int)matrix.size() || y >= (int)matrix[0].size() || x < 0 || y < 0) {
						cout << "Invalid coordinate, try again" << endl;
					} else {
						choosing = false;
					}
				} catch (InputException ie) {
					cout << ie.what() << endl;
				} catch (...) {
					cout << "Invalid input, coodination must be numbers" << endl;
				}
			}
		} else {
			players[COM]->choosePosition(x, y, matrix);
			cout << "Computer choose x = " << x << ", y = " << y << endl;
		}

		if (matrix[x][y] == 1) {
			players[turn]->setNrTargetShots();
			int current_opponent_hp = players[!turn]->getHP() - 1;
			cout << "Good shot!, opponent's HP =  " 
			<< current_opponent_hp << endl << endl;

			matrix[x][y] = -1;

			players[!turn]->getBoard()->setMatrix(matrix);
			players[turn]->setTotalShots();

			if (current_opponent_hp <= 0) {
				if (turn == HUMAN) {
					cout << "YOU WIN" << endl;
					cout << "Shots on target: " << players[HUMAN]->getNrTargetShots() << endl;
					cout << "Total shots: " << players[HUMAN]->getTotalShots() << endl;
					cout << "Score: " << (float)players[HUMAN]->getNrTargetShots() / players[HUMAN]->getTotalShots() * 100 << endl << endl;
					setHighScore();
				} else {
					cout << "COMPUTER WIN" << endl;
					cout << "Shots on target: " << players[COM]->getNrTargetShots() << endl;
					cout << "Total shots: " << players[COM]->getTotalShots() << endl;
					cout << "Score: " << (float)players[COM]->getNrTargetShots() / players[COM]->getTotalShots() * 100 << endl;
				}
				running = false;
			}
			players[!turn]->setHP(current_opponent_hp);
		} else {
			cout << "Missing!" << endl << endl;
			players[turn]->setTotalShots();
			turn = !turn;
		}
	}
}

void GamePlay::showHighScore() const {
	fstream file("high_score.txt");
	if (!file.is_open()) {
		cout << "Error while open file" << endl;
		return;
	}
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	file.close();
}

void GamePlay::showUserInfo() const {
	cout << "--------------------" << endl;

	if (players.size() == 0) {
		cout << "No user" << endl;
	} else {
		cout << "Name: " << players[HUMAN]->getName() << endl;
		cout << "Amount of ships(size): " << players[HUMAN]->getNrShips() 
			<< "(" << players[HUMAN]->getShips()[0]->getLength() << "x" << players[HUMAN]->getShips()[0]->getWidth() << ")" << endl;
		cout << "Board data: " << endl;
		cout << "  Size: " << players[HUMAN]->getBoard()->getHeight() << "x" << players[HUMAN]->getBoard()->getWidth() << endl;
		cout << "  Status:" << endl;
		players[HUMAN]->getBoard()->showMatrix();
	}
}

void GamePlay::doTask(const int &choice) {
	switch(choice) {
		case 1:
			initialize();
			play();
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

void GamePlay::setHighScore() {
	string file_name = "high_score.txt";
	ofstream create_file;
	create_file.open(file_name, ios::app);
	if (!create_file.is_open()) {
		cout << "Error while open file" << endl;
		return;
	}
	create_file.close();

	ifstream read_file(file_name);
	if (!read_file.is_open()) {
		cout << "Error while open file1" << endl;
		return;
	}
	
	vector<string> lines;
	int score = (float)players[HUMAN]->getNrTargetShots() / players[HUMAN]->getTotalShots() * 100;
	string line;
	bool valid = true;
	bool choosing = true;

	if (!getline(read_file, line)) {
		string new_line = players[HUMAN]->getName() + " " + to_string(score);
		lines.push_back(new_line);
		cout << "empty" << endl;
	} else {
		while (choosing) {
			cout << "line: " << line  << endl;
			int high_score = getHightScore(line);
			string new_line = players[HUMAN]->getName() + " " + to_string(score);
			
			if (score >= high_score && valid) {
				
				lines.push_back(new_line);
				valid = false;
			}
			lines.push_back(line);

			if (getline(read_file, line)) {
				choosing = true;
			} else {
				choosing = false;
				if (lines.size() < 10 && valid) {
					lines.push_back(new_line);
				}
			}
			cout << lines.size();
		}
	}

	read_file.close();
	cout << lines.size() << endl;
	if (lines.size() > 10) {
		lines.erase(lines.end());
	}

	ofstream write_file(file_name, ios::trunc);
	if (!write_file.is_open()) {
		cout << "Error while open file" << endl;
		return;
	}

	for (int i = 0; i < (int)lines.size(); i++) {
		write_file << lines[i] + "\n";
		cout << lines[i] << endl;
	}
	write_file.close();
}

int GamePlay::getHightScore(const string &line) const {
	int high_score = 0;
	size_t index_found = line.find(" ");

	high_score = stoi(line.substr(index_found+1));

	return high_score;
}

GamePlay::~GamePlay() {
	for (int i = 0; i < (int)players.size(); i++) {
		delete players[i];
	}
}
