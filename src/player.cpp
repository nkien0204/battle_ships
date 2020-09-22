#include "../include/player.h"

Player::Player() {}

void Player::setTotalShots(const int &total_shots) {
	this->total_shots = total_shots;
}

void Player::setNrTargetShots(const int &n_target_shots) {
	this->n_target_shots = n_target_shots;
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

Player::~Player() {}