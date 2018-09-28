//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "What is your first name? ";
	char name[80];
	std::cin.getline(name, strlen(name));

	std::cout << "What is your last name? ";
	char last_name[100];
	std::cin.getline(last_name, strlen(last_name));

	std::cout << "What letter grade do you deserve? ";
	char ctg;
	std::cin >> ctg;
	ctg = ctg + 1;

	std::cout << "What is your age? ";
	int age = 0;
	std::cin >> age;

	std::cout << "Name: " << last_name << ", " << name << std::endl;
	std::cout << "Grade: " << ctg << std::endl;
	std::cout << "AGE: " << age << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------