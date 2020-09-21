#include "../include/player.h"

vector<Ship *> Player::ships = {NULL};

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

Player::~Player() {}