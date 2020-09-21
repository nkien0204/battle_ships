#include "../include/menu.h"

int Menu::getChoice() {
	int choice;
	cout << "Your choice (0: quit): "; cin >> choice;

	return choice;
}

void Menu::running() {
	bool running = true;

	while(running) {
		printMenu();
		int choice = getChoice();
		doTask(choice);
		if (choice == EXIT) running = false;
	}
}

Menu::~Menu() {}