//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter the number of earned tvarpov: ";
	unsigned int twarp = 0;

	while (std::cin >> twarp) 
	{
		unsigned int summ = 0;

		if (twarp <= 10000) 
		{
			std::cout << "Your tax = 0" << std::endl;
		}
		else if ((twarp >= 10000) && (twarp <= 20000)) 
		{
			summ = (twarp * 0) + ((twarp - 5000) * 0.10);
			std::cout << "Your tax = " << summ << std::endl;
		}
		else if ((twarp >= 20000) && (twarp <= 35000)) 
		{
			summ = (5000 * 0) + (10000 * 0.10) + ((twarp - 10000) * 0.15);
			std::cout << "Your tax = " << summ << std::endl;
		}
		else if (twarp >= 35000) 
		{
			summ = (5000 * 0) + (10000 * 0.10) + (20000 * 0.15) + ((twarp - 35000) * 0.20);
			std::cout << "Your tax = " << summ << std::endl;
		}
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
