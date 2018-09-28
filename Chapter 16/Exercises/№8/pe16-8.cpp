//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <iterator>
#include <string>

//-------------------------------------------------------------------------------------------------
bool string_compare(std::string s1, std::string s2);
//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter Mat's list of friends ";
	std::cout << "(enter after each name, quit to quit):\n";
	
	std::string name;
	getline(std::cin, name);
	
	std::vector<std::string> mat_list;
	while (name != "quit")
	{
		if (name != "")
		{
			mat_list.push_back(name);
		}
		getline(std::cin, name);
	}
	std::cout << std::endl;

	std::cout << "Enter Pat's list of friends ";
	std::cout << "(enter after each name, quit to quit):\n";
	getline(std::cin, name);
	
	std::vector<std::string> pat_list;
	while (name != "quit")
	{
		if (name != "")
		{
			pat_list.push_back(name);
		}
		getline(std::cin, name);
	}
	std::cout << std::endl;

	sort(mat_list.begin(), mat_list.end(), string_compare);
	sort(pat_list.begin(), pat_list.end(), string_compare);
	std::vector<std::string> merged_list;
	std::insert_iterator<std::vector<std::string>> insert(merged_list, merged_list.begin());
	set_union(mat_list.begin(), mat_list.end(), pat_list.begin(), pat_list.end(), insert, string_compare);

	std::cout << "Here is our guestlist: " << std::endl;
	
	for (int i = 0; (unsigned)i < merged_list.size(); i++)
	{
		std::cout << merged_list[i] << std::endl;
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
bool string_compare(std::string s1, std::string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}
//-------------------------------------------------------------------------------------------------