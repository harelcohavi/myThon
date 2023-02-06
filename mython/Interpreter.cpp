#include "pch.h"

#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Harel Cohavi"


int main(int argc,char **argv)
{
	Type* varing = nullptr;

	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		// parsing command
		try
		{
			varing = Parser::parseString(input_string);
		
			if (varing->isPrintable())
			{
				std::cout << varing->toString() << std::endl;
			}
			if (varing->isTemp())
			{
				delete varing;
			}
			varing = nullptr;

		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	return 0;
}
