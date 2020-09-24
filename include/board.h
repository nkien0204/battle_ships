#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

using namespace std;

#define B_HEIGHT 8
#define B_WIDTH 8

class Board {
protected:
	int height;
	int width;
	vector<vector<int>> matrix;
public:
	Board();
	void setHeight(const int &height);
	void setWidth(const int &width);
	int getHeight() const;
	int getWidth() const;
	vector<vector<int>> getMatrix() const;
	void showMatrix() const;
	void createMatrix();
	void setMatrix(const vector<vector<int>> &matrix);
private:
	void initMatrix(const int &height, const int &width);
};

#endif
