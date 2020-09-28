#ifndef INPUT_EXCEPTION_H
#define INPUT_EXCEPTION_H

#include <iostream>
#include <exception>
using namespace std;

class InputException : public exception {
	public:
		const char *what() const throw() {
			return "Invalid choice, try again";
		}
};
#endif