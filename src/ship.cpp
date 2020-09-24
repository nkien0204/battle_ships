#include "../include/ship.h"

Ship::Ship() {
	length = S_LENGTH;
	width = S_WIDTH;
}

Ship::Ship(const int &length, const int &width) {

	this->length = length;
	this->width = width;
}

void Ship::setLength(const int &length) {
	this->length = length;
}

void Ship::setWidth(const int &width) {
	this->width = width;
}

int Ship::getLength() const {
	return length;
}

int Ship::getWidth() const {
	return width;
}
