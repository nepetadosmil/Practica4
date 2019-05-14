#pragma once
#include <iostream>

class UserMenu {
public:
	UserMenu();
	// Asks user for a valid option and returns the choice
	unsigned getOption(unsigned max);
	~UserMenu();
};