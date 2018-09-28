//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "dma.h" 

const int ArrLength = 3;
const int LEN = 40;
//-------------------------------------------------------------------------------------------------
int main()
{
	abcDMA* arr[ArrLength];
	char label[LEN];
	char style[LEN];
	char color[LEN];
	
	int rating = 0;
	int choice = 0;

	for (int i = 0; i < ArrLength; i++)
	{
		std::cout << "For element " << i + 1 << ", enter the label: ";
		std::cin.getline(label, LEN);
		
		std::cout << "Enter the rating: ";
		std::cin >> rating;
		
		std::cout << "Enter 1 if this is to be a baseDMA object" << std::endl;
		std::cout << "Enter 2 if this is to be a hasDMA object" << std::endl;
		std::cout << "Enter 3 if this is to be a lacksDMA object" << std::endl;
		std::cin >> choice;
		std::cin.get();
		
		switch (choice)
		{
		case 1:
			arr[i] = new baseDMA(label, rating);
			break;
		case 2:
			std::cout << "Enter the style: ";
			std::cin.getline(style, LEN);
			arr[i] = new hasDMA(style, label, rating);
			break;
		case 3:
			std::cout << "Enter color: ";
			std::cin.getline(color, LEN);
			arr[i] = new lacksDMA(color, label, rating);
			break;
		default:
			std::cout << "Unrecognized input, setting object ";
			std::cout << "to baseDMA";
			arr[i] = new baseDMA(label, rating);
			break;
		}

	}
	std::cout << "Here's what you entered:" << std::endl;
	
	for (int i = 0; i < ArrLength; i++)
	{
		std::cout << "Element " << i + 1 << ":" << std::endl;
		arr[i]->View();
	}

	for (int i = 0; i < ArrLength; i++)
	{
		delete arr[i];
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------