//mixtypes.cpp -- некоторые комбинации типов 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
struct antarctica_years_end
{
	int year;
	/* определение других нужных данных */
};
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	antarctica_years_end s01, s02, s03;
	s01.year = 1998;
	antarctica_years_end* pa = &s02;
	pa->year = 1999;
	antarctica_years_end trio[3]; // массив из трех структур 
	trio[0].year = 2003;
	cout << trio->year << endl;
	const antarctica_years_end* arp[3] = { &s01, &s02, &s03 };
	cout << arp[1]->year << endl;
	const antarctica_years_end** ppa = arp;
	auto ppb = arp; // автоматическое выведение типа в C++11 
					// или можно использовать const antarctica_years_end ** ppb = arp; 
	cout << (*ppa)->year << endl;
	cout << (*(ppb + 1))->year << endl;
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
2003
1999
1998
1999
*/