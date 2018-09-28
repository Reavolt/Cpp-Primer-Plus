//usestok1.срр -- использование класса Stock 
//Компилировать вместе с stock10.cpp 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "10.4_stock10.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	{
		using std::cout;
		// Использование конструкторов для создания новых объектов 
		cout << "Using constructors to create new objects\n";
		Stock stockl("NanoSmart", 12, 20.0); // первый синтаксис 
		stockl.show();
		Stock stock2 = Stock("Boffo Objects", 2, 2.0); // второй синтаксис 
		stock2.show();
		// Присваивание stockl объекту stock2 
		cout << "Assigning stockl to stock2:\n";
		stock2 = stockl;
		// Вывод stockl и stock2 
		cout << "Listing stockl and stock2:\n";
		stockl.show();
		stock2.show();
		// Использование конструктора для сброса объекта 
		cout << "Using a constructor to reset an object\n";
		stockl = Stock("Nifty Foods", 10, 50.0); // временный объект 
		cout << "Revised stockl:\n";
		stockl.show();
		cout << "Done\n";
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Using constructors to create new objects
Constructor using NanoSmart called
Company: NanoSmart Shares: 12
Share Price: $ 20.000 Total Worth: $240.00
Constructor using Boffo Objects called
Company: Boffo Objects Shares: 2
Share Price: $ 2.000 Total Worth: $4.00
Assigning stockl to stock2:
Listing stockl and stock2:
Company: NanoSmart Shares: 12
Share Price: $ 20.000 Total Worth: $240.00
Company: NanoSmart Shares: 12
Share Price: $ 20.000 Total Worth: $240.00
Using a constructor to reset an object
Constructor using Nifty Foods called
Bye, Nifty Foods!
Revised stockl:
Company: Nifty Foods Shares: 10
Share Price: $ 50.000 Total Worth: $500.00
Done
Bye, NanoSmart!
Bye, Nifty Foods!
*/