#include "../include/ship.h"

Ship::Ship() {
	length = S_LENGTH;
	width = S_WIDTH;
}

Ship::Ship(const Ship &cpy_ship) {
	unsigned int cpy_length = cpy_ship.getLength();
	unsigned int cpy_width = cpy_ship.getWidth();
}

Ship::Ship(const unsigned int &length, const unsigned int &width) {
	// check ship size with board size

	this->length = length;
	this->width = width;
}

void Ship::setLength(const unsigned int &length) {
	this->length = length;
}

void Ship::setWidth(const unsigned int &width) {
	this->width = width;
}

unsigned int Ship::getLength() const {
	return length;
}

unsigned int Ship::getWidth() const {
	return width;
}