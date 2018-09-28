//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	
#include <fstream>
#include <cstdlib>

//-------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cerr << "Error, two arguments representing filenames are missing";
		std::cerr << std::endl;
		exit(EXIT_FAILURE);
	}
	else 
	if (argc > 3)
	{
		std::cerr << "More arguments than necessary are detected" << std::endl;
		std::cerr << "Only the first two arguments will be used" << std::endl;
	}

	std::cout << "Warning: this will erase the contents of " << argv[2];
	std::cout << ". Proceed? (y/n) ";

	char ch;
	std::cin >> ch;
	
	if (ch != 'y' && ch != 'Y')
	{
		return 0;
	}
	else
	{
		std::ifstream infile;
		infile.open(argv[1]);
		
		if (!infile.is_open())
		{
			std::cerr << "Error, could not open " << argv[1] << std::endl;
			exit(EXIT_FAILURE);
		}

		std::ofstream outfile;
		outfile.open(argv[2]);
		
		if (!outfile.is_open())
		{
			std::cerr << "Error, could not open " << argv[2] << std::endl;
			exit(EXIT_FAILURE);
		}

		while (infile.get(ch))
		{
			outfile.put(ch);
		}
		infile.close();
		outfile.close();
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------