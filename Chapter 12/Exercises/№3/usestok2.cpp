//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "stock20.h"

const int STKS = 4;
//-------------------------------------------------------------------------------------------------
int main()
{
	// Создание массива инициализированных объектов 
	Stock stocks[STKS] = 
	{
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "Stock holdings:\n";
	for (int st = 0; st < STKS; st++)
	{
		 std::cout << stocks[st];
	}
	
	// Установка указателя н первый элемент 
	const Stock* top = &stocks[0];
	for (st = 1; st < STKS; st++)
	{
		 top = &top->topval(stocks[st]);
	}
	
	// Теперь top указывает на самый ценный пакет акций 
	std::cout << "\nMost valuable holding:\n";
	std::cout << *top;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------