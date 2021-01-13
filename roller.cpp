#include <string>
#include "roller.h"

bool Roller::loadFromArgs(std::vector<std::string> args)
{
	bool success = true;
	// Divide the arg list up into distinct dice.
	while(true)
	{
		// First string should be XdX where X is a number.
		// Check that there is a 'd'
		size_t dLoc = args[0].find('d');
		if(dLoc == std::string::size_type)
		{
			success = false;
			break;
		}
		// Check that there are only numbers before and after and assign to variables.
		int numberOfDice, diceSides;
		// No number before means only one die.
		if(dLoc == 0)
			numberOfDice = 1;
		else
		{
			// Check that the things before 'd' are number and assign them.
			for(char c : args[0].substr(0, dLoc))
			{
				if(!isANum(c))
					success = false;
			}
			if(!success)
				break;
			else
				numberOfDice = std::stoi(args[0].substr(0, dLoc));
		}
		// If no numbers after 'd', error.
		if((args[0].begin() + dLoc + 1) == args[0].end())
		{
			success = false;
			break;
		}
		else
		{
			// Check that the things after 'd' are number and assign them.
			for(char c : args[0].substr(dLoc + 1))
			{
				if(!isANum(c))
					success = false;
			}
			if(!success)
				break;
			else
				diceSides = std::stoi(args[0].substr(dLoc + 1));
		}
		// Get rid of the dice arg and create the right dice. We will proccess additional options
		// and then add the right number to the Roller list.
		args.erase(args.begin());
		Die die(diceSides);
		// If empty, we are done. Otherwise, check whether the next arg begins with '-'
		if(args.empty())
		{
			for(int x = 0; x < numberOfDice; x++)
				diceList.push_back(die);
			break;
		{
		if(args[0].empty() || args[0][0] != '-')
		{
			success = false;
			break;
		}
		// We now need to deal with options
		
	}
	return success;
}

int Roller::roll()
{
	int result = 0;
	for(auto it = diceList.begin(); it < diceList.end(); it++)
		result += it.roll();
	return 0;
}

std::vector<std::string> Roller::unload()
{
	return std::vector<std::string>();
}

bool Roller::isANum(char c)
{
	for(char val : numbers)
	{
		if(c == val)
			return true;
	}
	return false; 
}
