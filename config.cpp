#include <iostream>
#include "config.h"

// Runs the help dialogue.
void Config::help()
{
	std::cout << "Usage: dice COMMAND [DICE] [OPTION]..." << std::endl;
	std::cout << "A full-featured dice rolling program." << std::endl;
	std::cout << "\n COMMANDS" << std::endl;
	std::cout << "  -R, --roll   Roll a die." << std::endl;
	std::cout << "  -S, --save   Save a die." << std::endl;
	std::cout << "  -L, --load   Load a die." << std::endl;
	std::cout << "  -F, --flush  Flush saved dice." << std::endl;
	std::cout << "  -h, --help   Run this dialogue." << std::endl;
	std::cout << "\n DICE FORMAT" << std::endl;
	std::cout << "  [X]dY[[+][-]Z], where X is the number of dice, Y the number of sides, and " << std::endl;
	std::cout << "    Z an optional raw amount to add to the role." << std::endl;
	std::cout << "\n OPTION" << std::endl;
	std::cout << "  -c, --easy-crit   Critical hit (easy). Modifies preceding die and followed by a side. Will roll again on hit." << std::endl;
	std::cout << "  -C  --hard-crit   Critical hit (hard). Modifies preceding die and followed by a side. Will roll again to " << std::endl;
	std::cout << "                    confirm hit, then add a third roll onto the total." <<std::endl;
	std::cout << "  -m  --minus       Followed by a valid die. Subtracts from the total." << std::endl;
	std::cout << "  -p  --plus        Followed by a valid die. Adds to the total." << std::endl;
	std::cout << "\n EXAMPLES" << std::endl;
	std::cout << "  dice -R 5d6+1     Rolls five six-sided dice, adding 1 to each roll." << std::endl;
	std::cout << "  dice -S big-roll 3d2+2 -p 12d6 -c 12 11" << std::endl;
	std::cout << "                    Saves a dice roll called big-roll consisting of three rolls of a two-sided dice," << std::endl;
	std::cout << "                    plus twelve rolls of a six sided dice with an additional roll on each 12 and 11 rolled." << std::endl;
	std::cout << "\nSee github.com/Sigston/dice for more." << std::endl;
}

// Print the error string in a nice way.
void Config::error(std::string str)
{
}

// Save the arguments string as a dice: please check when saving that the string is valid.
void Config::save(std::vector<std::string> args)
{
}

// Will take a string associated with a die and return the arg list. Will return empty if cannot find.
std::vector<std::string> Config::load(std::string str)
{
	return std::vector<std::string>();
}

// Looks for a die with the string, false if not found
bool Config::findDice(std::string str)
{
	return true;
}

// Deletes all saved dice.
void Config::flush()
{
}
	
