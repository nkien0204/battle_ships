#include "../include/player.h"

Player::Player() {}

void Player::setTotalShots() {
	this->total_shots++;
}

void Player::setNrTargetShots() {
	this->n_target_shots++;
}

int Player::getNrShips() const {
	return (int)ships.size();
}

Board *Player::getBoard() const {
	return board;
}

vector<Ship *> Player::getShips() const {
	return ships;
}

string Player::getName() const {
	return name;
}

void Player::setHP(const int &hp) {
	this->hp = hp;
}

int Player::getHP() const {
	return hp;
}

int Player::getNrTargetShots() const {
	return n_target_shots;
}

int Player::getTotalShots() const {
	return total_shots;
}

Player::~Player() {}