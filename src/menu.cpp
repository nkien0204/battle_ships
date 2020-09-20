#include "../include/menu.h"

int Menu::getChoice() {
	int choice = 0;
	cout << "Your choice: "; cin >> choice;

	return choice;
}

void Menu::running() {
	bool running = true;

	while(running) {
		printMenu();
		int choice = getChoice();
		if (choice == 0) running = false;
	}
}

Menu::~Menu() {}