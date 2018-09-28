//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

//-------------------------------------------------------------------------------------------------
std::vector<int> Lotto(int spots, int selected);
//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter the number of spots on the lottery card: ";
	int spots = 0;
	std::cin >> spots;
	
	std::cout << "Enter the number of spots to be selected: ";
	int selected = 0;
	std::cin >> selected;

	std::vector<int> result = Lotto(spots, selected);
	std::cout << "Your lucky numbers are: ";
	
	for (int i = 0; (unsigned)i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
std::vector<int> Lotto(int spots, int selected)
{
	if (spots < selected)
	{
		std::cout << "The second argument of Lotto() must be less than ";
		std::cout << "the first argument." << std::endl;
		std::cout << "Program abort" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (spots < 0 || selected < 0)
	{
		std::cout << "Both arguments of Lotto() must be positive integers";
		std::cout << std::endl;
		std::cout << "Program abort" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::vector<int> v;
	for (int i = 1; i < spots + 1; i++)
	{
		v.push_back(i);
	}

	random_shuffle(v.begin(), v.end());
	
	std::vector<int> picks;
	for (int i = 0; i < selected; i++)
	{
		picks.push_back(v[i]);
	}
	return picks;
}
//-------------------------------------------------------------------------------------------------