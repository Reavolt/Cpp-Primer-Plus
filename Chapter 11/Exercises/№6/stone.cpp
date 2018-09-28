//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "stonewt.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	const int ARR_SIZE = 6;

	Stonewt eleven(11, 0);
	Stonewt arr[ARR_SIZE] = { 30.27, 102.34, 80.51 };
	Stonewt maxElement = arr[0];
	Stonewt minElement = arr[0];

	for (int i = 0, j = ARR_SIZE - 1; i < ARR_SIZE / 2; ++i, --j)
	{
		arr[j] = arr[i] * 2.0;
	}

	int quantity = 0;

	for (int i = 0; i < ARR_SIZE; ++i)
	{
		if (arr[i] > maxElement)
		{
			maxElement = arr[i];
		}
		if (arr[i] < minElement)
		{
			minElement = arr[i];
		}
		if (arr[i] >= eleven)
		{
			++quantity;
		}
	}

	std::cout << "Maximal element is: " << maxElement << std::endl;
	std::cout << "Minimal element is: " << minElement << std::endl;
	std::cout << "Quantity of elements bigger than 11 stones is: ";
	std::cout << quantity << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------