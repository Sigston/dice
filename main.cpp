/*
** A program to provide full dice rolling functionality.
** Calls 'dice' from the command line followed by 'roll',
** 'save' or 'help'. Program stores a list of saved dice rolls.
** Next argument must be [X]dX[+X] where X must be a number.
** Then there are options with -X, where X is a letter.
**
** TODO: implement Die class
** TODO: implement Config file reading and writing
*/
#include <iostream>
#include <string>
#include <vector>
#include "config.h"
#include "roller.h"

void roll(Roller& roller, std::vector<std::string>& args);
void save(Roller& roller, std::vector<std::string>& args);
void load(Roller& roller, std::vector<std::string>& args);
void flush();
void help();

int main(int argc, char* argv[])
{
	// If dice is called with no args, call help.
	if(argc <= 1)
		Config::help();
	// Otherwise process main commands.
	else
	{
		std::vector<std::string> arguments(argv + 1, argv + argc);
		Roller roller;
		if(arguments[0] == "-R" || arguments[0] == "--roll")
			roll(roller, arguments);
		if(arguments[0] == "-S" || arguments[0] == "--save")
			save(roller, arguments);
		if(arguments[0] == "-L" || arguments[0] == "--load")
			load(roller, arguments);
		if(arguments[0] == "-F" || arguments[0] == "--flush")
			flush();
		else		
			help();
	}
	return 0;
}

void roll(Roller& roller, std::vector<std::string>& args)
{
	if(roller.loadFromArgs(args))
		std::cout << roller.roll();
	else
		Config::error("Not valid die roll. Use -h for help.");
}

void save(Roller& roller, std::vector<std::string>& args)
{
	if(roller.loadFromArgs(args))
		Config::save(roller.unload());
	else
		Config::error("Not valid die roll. Use -h for help.");
}

void load(Roller& roller, std::vector<std::string>& args)
{
	if(args.size() < 1)
		Config::error("Specify name of saved dice. Use -h for help.");
	else
	{
		if(Config::findDice(args[1]))
		{
			roller.loadFromArgs(Config::load(args[1]));
			std::cout << roller.roll();
		}
		else
			Config::error("No dice found of that name. Use -h for help.");
	}
}

void flush()
{
	Config::flush();
	std::cout << "Saved dice deleted." << std::endl;
}

void help()
{
	Config::help();
}
