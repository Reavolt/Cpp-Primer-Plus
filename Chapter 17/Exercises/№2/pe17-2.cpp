//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	
#include <fstream>
#include <cstdlib>

//-------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cerr << "Error, a filename must be an argument on the command line.";
		std::cerr << std::endl;
		exit(EXIT_FAILURE);
	}

	if (argc > 2)
	{
		std::cout << "Arguments on the command line beyond the first are ignored";
		std::cout << std::endl;
	}

	std::ofstream outfile;
	outfile.open(argv[1]);
	
	if (!outfile.is_open())
	{
		std::cerr << "Error, could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	std::cout << "Enter input (ctrl-D when done): ";
	
	char ch;
	while (std::cin.get(ch))
	{
		outfile.put(ch);
	}
	
	if (!std::cin.eof())
	{
		std::cerr << "Warning, input quit due to something other than ";
		std::cerr << "simulated EOF" << std::endl;
	}
	outfile.close();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------