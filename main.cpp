/*
** A program to provide full dice rolling functionality.
** Calls 'dice' from the command line followed by 'roll',
** 'save' or 'help'. Program stores a list of saved dice rolls.
** Next argument must be [X]dX[+X] where X must be a number.
** Then there are options with -X, where X is a letter.
**
** TODO: Implement program structure.
*/
#include <iostream>
#include <string>
#include <vector>
#include "config.h"
#include "die.h"

int main(int argc, char* argv[])
{
	// If dice is called with no args, call help.
	if(argc <= 1)
		Config::help();
	else
	{
		std::vector<std::string> arguments(argv + 1, argv + argc);
		Die die;
		if(arguments[0] == "-R" || arguments[0] == "--roll")
		{
			if(die.loadFromArgs(arguments))
				std::cout << die.roll();
			else
				Config::error("Not valid die roll. Use -h for help.");
		}
		if(arguments[0] == "-S" || arguments[0] == "--save")
		{
			if(die.loadFromArgs(arguments))
				Config::save(die.unload());
			else
				Config::error("Not valid die roll. Use -h for help.");
		}
		if(arguments[0] == "-L" || arguments[0] == "--load")
		{
			if(arguments.size() < 1)
				Config::error("Specify name of saved dice. Use -h for help.");
			else
			{
				if(Config::findDice(arguments[1]))
				{
					die.loadFromArgs(Config::load(arguments[1]));
					std::cout << die.roll();
				}
				else
					Config::error("No dice found of that name. Use -h for help.");
			}
		}	
		if(arguments[0] == "-F" || arguments[0] == "--flush")
		{
			Config::flush();
			std::cout << "Saved dice deleted." << std::endl;
		}
		else		
			Config::help();
	}
	return 0;
}

