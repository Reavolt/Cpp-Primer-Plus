//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "VintagePort.h" 

const int arrSize = 2;
const int LEN = 50;
//-------------------------------------------------------------------------------------------------
int main()
{
	char brand[LEN];
	char style[LEN];
	int bottles = 0;
	char nickname[LEN];
	int year = 0;
	int choice = 0;
	Port* arr[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		std::cout << "Object " << i + 1 << std::endl;
		std::cout << "Enter the brand for the object: ";
		std::cin.getline(brand, LEN);
		std::cout << "Enter the number of bottles: ";
		std::cin >> bottles;
		std::cin.get(); 	// discard newline character
		std::cout << "Enter 1 if you would like this to be a Port object" << std::endl;
		std::cout << "Enter 2 if you would like this to be a Vintage Port object";
		std::cout << std::endl;
		std::cin >> choice;
		std::cin.get(); 	// discard newline character

		switch (choice)
		{
		case 1:
			std::cout << "Enter the style: ";
			std::cin.getline(style, LEN);
			arr[i] = new Port(brand, style, bottles);
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "Enter the nickname: ";
			std::cin.getline(nickname, LEN);
			std::cout << "Enter the year: ";
			std::cin >> year;
			std::cin.get(); 
			arr[i] = new VintagePort(brand, bottles, nickname, year);
			std::cout << std::endl;
			break;
		default:
			std::cout << "Input not recognized. Making a default Port object";
			std::cout << std::endl;
			arr[i] = new Port();
			break;
		}
	}
	
	std::cout << "Here's our array:" << std::endl
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << "Element 1: " << std::endl;
		arr[i]->Show();
	}
	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------