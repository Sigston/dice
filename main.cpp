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

void help();

int main(int argc, char* argv[])
{
	// If dice is called with no args, call help.
	if(argc < 1)
		help();
	if(argc == 1)
	{
		// Roll simple dice as XdX+/-X
	}
	else
	{
		// Attempt to process with options
	}
	return 0;
}

// Runs the help dialogue.
void help()
{
	std::cout << "Usage: dice COMMAND [DICE] [OPTION]..." << std::endl;
	std::cout << "A full-featured dice rolling program." << std::endl;
	std::cout << "";
}
