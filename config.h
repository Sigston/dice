#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>

namespace Config
{

	void help();
	void error(std::string str);
	void save(std::vector<std::string> args);
	std::vector<std::string> load(std::string str);
	bool findDice(std::string str);
	void flush();			
}

#endif
