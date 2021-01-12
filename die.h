#ifndef DIE_H
#define DIE_H

class Die {
public:
	bool loadFromArgs(std::vector<std::string> args);
	int roll();
};

#endif
