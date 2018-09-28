//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
struct car
{
	std::string name;
	int age;
};
//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter the number of machines that you want to catalog: ";
	int array_count;
	(std::cin >> array_count).get();

	car* ptr = new car[array_count];
	for (size_t i = 0; i < array_count; i++)
	{
		std::cout << "Car №" << i + 1 << "" << std::endl;
		std::cout << "Enter the manufacturer: ";
		getline(std::cin, ptr[i].name);
		std::cout << "Please enter the year of manufacture: ";
		(std::cin >> ptr[i].age).get();
	}

	std::cout << "Here is your collection:" << std::endl;

	for (size_t j = 0; j < array_count; j++)
	{
		std::cout << ptr[j].age << " : " << ptr[j].name << std::endl;
	}
	delete[] ptr;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------