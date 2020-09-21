#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#define EXIT 0

using namespace std;

class Menu {
protected:
	virtual void doTask(const int &choice) = 0;
	virtual void printMenu() const = 0;
	int getChoice();
public:
	void running();
	virtual ~Menu();
};

#endif