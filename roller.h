#ifndef ROLLER_H
#define ROLLER_H
#include <vector>
#include <string>
#include "die.h"

class Roller {
public:
	bool loadFromArgs(std::vector<std::string> args);
	int roll();
	std::vector<std::string> unload();
private:
	bool isANum(char c);
	std::vector<Die> diceList;
	std::vector<char> numbers = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
};

#endif
