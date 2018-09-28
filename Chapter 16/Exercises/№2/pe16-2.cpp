//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
bool isPalindrome(std::string & str);
//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter a string: ";
	std::string str;
	getline(std::cin, str);

	if (isPalindrome(str))
	{
		std::cout << str << " is a palindrome" << std::endl;
	}
	else
	{
		std::cout << str << " is not a palindrome" << std::endl;
	}

	std::cin.get();
	std::cin.get();
    return 0;
}
//-------------------------------------------------------------------------------------------------
bool isPalindrome(std::string & str)
{
	std::string palind;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
		{
			palind.push_back(tolower(str[i]));
		}
	}
		
	for (int i = 0, j = palind.size() - 1; i < j; i++, j--)
	{
		if (palind[i] != palind[j])
		{
			return false;
		}
	}
	return true;
}
//-------------------------------------------------------------------------------------------------