//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "Wine.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter name of wine: "; // ввод названия вина 
	char lab[50];
	std::cin.getline(lab, 50);
	std::cout << std::endl;
	
	std::cout << "Enter number of years: "; // ввод количества годов сбора винограда 
	int yrs = 0;
	std::cin >> yrs;
	
	Wine holding(lab, yrs);	// сохранение названия, лет, 
							// создание массивов из yrs элементов 
	holding.GetBottles();	// предложение ввести год и количество бутылок 
	holding.Show();			// вывод содержимого объекта 
	
	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	// Создание нового объекта, инициализация 
	// с использованием данных из массивов у и b 
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	std::cout << std::endl;
	
	std::cout << "Total bottles for " << more.Label();  // используется метод Label() 
	std::cout << ": " << more.sum() << std::endl; 		// используется метод sum() 
	std::cout << "Bye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------

/*
Enter name of wine: Gully Wash

Enter number of years: 4
Enter Gully Wash data for 4 year(s):
Enter year: 1988
Enter bottles for that year: 42

Enter year: 1994
Enter bottles for that year: 58

Enter year: 1998
Enter bottles for that year: 122

Enter year: 2001
Enter bottles for that year: 144

Wine: Gully Wash
Year    Bottles
1988    42
1994    58
1998    122
2001    144
Wine: Gushing Grape Red
Year    Bottles
1993    48
1995    60
1998    72

Total bottles for Gushing Grape Red: 180
Bye
*/