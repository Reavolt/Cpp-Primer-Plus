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
	for (int i = 0, j = str.size() - 1; i < j; i++, j--)
	{
		if (str[i] != str[j])
		{
			return false;
		}
	}
	return true;
}
//-------------------------------------------------------------------------------------------------