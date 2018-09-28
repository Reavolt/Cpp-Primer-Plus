//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	
#include <fstream>
#include <cstdlib>

//-------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		std::cerr << "Error, two arguments representing filenames are missing";
		std::cerr << std::endl;
		exit(EXIT_FAILURE);
	}
	else 
	if (argc > 4)
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
		std::ifstream infile_first;
		infile_first.open(argv[1]);
		
		if (!infile_first.is_open())
		{
			std::cerr << "Error, could not open " << argv[1] << std::endl;
			exit(EXIT_FAILURE);
		}

		std::ifstream infile_second;
		infile_second.open(argv[2]);
		
		if (!infile_second.is_open())
		{
			std::cerr << "Error, could not open " << argv[2] << std::endl;
			exit(EXIT_FAILURE);
		}

		std::ofstream outfile;
		outfile.open(argv[3]);
		
		if (!outfile.is_open())
		{
			std::cerr << "Error, could not open " << argv[3] << std::endl;
			exit(EXIT_FAILURE);
		}

		while (!infile_first.eof() && !infile_second.eof())
		{
			while (infile_first.get(ch) && ch != '\n')
			{
				outfile.put(ch);
			}
			outfile.put(' ');
			
			while (infile_second.get(ch) && ch != '\n')
			{
				outfile.put(ch);
			}
			outfile.put('\n');

			infile_first.peek(); 
			infile_second.peek();
		}
		
		if (infile_first.eof() && !infile_second.eof())
		{
			while (infile_second.get(ch) && ch != '\n')
			{
				outfile.put(ch);
			}
			outfile.put('\n');
		}
		else if (infile_second.eof() && !infile_first.eof())
		{
			while (infile_first.get(ch) && ch != '\n')
			{
				outfile.put(ch);
			}
			outfile.put('\n');
		}
		infile_first.close();
		infile_second.close();
		outfile.close();
	}
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------