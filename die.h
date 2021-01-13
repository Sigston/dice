#ifndef DIE_H
#define DIE_H
#include <random>

class Die {
public:
	Die(int sides);
	int roll(std::mt19937 engine);
private:
	std::uniform_int_distribution<int> mSides;
};

#endif
