//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "Sales_class.h"  

//-------------------------------------------------------------------------------------------------
int main()
{
	double arr[] = { 123.12, 522.22, 455.42, 777.32 };

	SALES::Sales Struct1;
	Struct1 = SALES::Sales(arr, SALES::QUARTERS);
	Struct1.showSales();

	std::cout << std::endl;

	SALES::Sales Struct2;
	Struct2 = SALES::Sales(arr, SALES::QUARTERS);
	Struct2.setSales();
	Struct2.showSales();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------