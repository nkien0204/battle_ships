#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

using namespace std;

#define B_HEIGHT 8
#define B_WIDTH 8

class Board {
protected:
	unsigned int height;
	unsigned int width;
	vector<vector<int>> matrix;
public:
	Board();
	Board(const unsigned int &height, const unsigned int &width);
	void setHeight(const unsigned int &height);
	void setWidth(const unsigned int &width);
	unsigned int getHeight() const;
	unsigned int getWidth() const;
	vector<vector<int>> getMatrix() const;
	void createMatrix();
private:
	void initMatrix(const unsigned int &height, const unsigned int &width);
};

#endif