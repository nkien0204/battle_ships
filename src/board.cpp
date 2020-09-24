#include "../include/board.h"

Board::Board() {
	createMatrix();
}

Board::Board(const int &height, const int &width) {
	initMatrix(height, width);
}

void Board::setHeight(const int &height) {
	this->height = height;
}

void Board::setWidth(const int &width) {
	this->width = width;
}

void Board::createMatrix() {
	bool choosing = true;
	char choice;

	while (choosing) {
		cout << "BOARD: Using default size (8x8)? (y = Yes, n = No): "; cin >> choice;
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

void Board::initMatrix(const int &height, const int &width) {
	vector<int> matrix_col(width);

	for (int i = 0; i < height; i++) {
		matrix.push_back(matrix_col);
		for (int j = 0; j < width; j++) {
			matrix[i].push_back(0);
		}
	}

	showMatrix();
}

void Board::showMatrix() const {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int Board::getHeight() const {
	return height;
}

int Board::getWidth() const {
	return width;
}

vector<vector<int>> Board::getMatrix() const {
	return matrix;
}
