#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>

#define S_LENGTH 3
#define S_WIDTH 1

class Ship {
protected:
	unsigned int length;
	unsigned int width;
public:
	Ship();
	Ship(const Ship &cpy_ship);
	Ship(const unsigned int &length, const unsigned int &width);
	void setLength(const unsigned int &length);
	void setWidth(const unsigned int &width);
	unsigned int getLength() const;
	unsigned int getWidth() const;
};

#endif