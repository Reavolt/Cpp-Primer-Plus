//usestok2.cpp -- использование класса Stock 
//Компилировать вместе с stock20.cpp 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "10.7_stock20.h"

const int STKS = 4;
//-------------------------------------------------------------------------------------------------
int main()
{
	// Создание массива инициализированных объектов 
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		 stocks[st].show();
	// Установка указателя н первый элемент 
	const Stock * top = &stocks[0];
	for (st = 1; st < STKS; st++)
		 top = &top->topval(stocks[st]);
	// Теперь top указывает на самый ценный пакет акций 
	std::cout << "\nMost valuable holding:\n";
	top->show();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Stock holdings:
Company: NanoSmart Shares: 12
Share Price: $20.000 Total Worth: $240.00
Company: Boffo Objects Shares: 200
Share Price: $2.000 Total Worth: $400.00
Company: Monolithic Obelisks Shares: 130
Share Price: $3.250 Total Worth: $422.50
Company: Fleep Enterprises Shares: 60
Share Price: $6.500 Total Worth: $390.00

Most valuable holding:
Company: Monolithic Obelisks Shares: 130
Share Price: $3.250 Total Worth: $422.50
*/