#include "../include/board.h"

Board::Board() {
	createMatrix();
}

Board::Board(const unsigned int &height, const unsigned int &width) {
	initMatrix(height, width);
}

void Board::setHeight(const unsigned int &height) {
	this->height = height;
}

void Board::setWidth(const unsigned int &width) {
	this->width = width;
}

void Board::createMatrix() {
	bool choosing = true;
	char choice;

	cout << "Board: Using default size (8x8)? (y = Yes, n = No): "; cin >> choice;
	while (choosing) {
		if (choice == 'y' || choice == 'Y') {
			initMatrix(B_HEIGHT, B_WIDTH);
			choosing = false;
		} else if (choice == 'n' || choice == 'N') {
			cout << "Size of Board (0:(8x8), 1:(12x12), 2:(16x16): "; cin >> choice;
			if (choice != '0' && choice != '1' && choice != '2') {
				cout << "Invalid choice, try again" << endl;
			} else if (choice == '0') {
				initMatrix(8, 8);
			} else if (choice == '1') {
				initMatrix(12, 12);
			} else if (choice == '2') {
				initMatrix(16, 16);
			}
			choosing = false;
		} else {
			cout << "Invalid choice, try again" << endl;
		}
	}
}

void Board::initMatrix(const unsigned int &height, const unsigned int &width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = 0;
		}
	}
}

unsigned int Board::getHeight() const {
	return height;
}

unsigned int Board::getWidth() const {
	return width;
}

vector<vector<int>> Board::getMatrix() const {
	return matrix;
}