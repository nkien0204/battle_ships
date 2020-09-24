#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>

#define S_LENGTH 3
#define S_WIDTH 1

class Ship {
protected:
	int length;
	int width;
public:
	Ship();
	Ship(const int &length, const int &width);
	void setLength(const int &length);
	void setWidth(const int &width);
	int getLength() const;
	int getWidth() const;
};

#endif
