//nested.срр -- вложенные циклы и двумерный массив 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

const int Cities = 5;
const int Years = 4;
//-------------------------------------------------------------------------------------------------
int main() 
{
	const char * cities[Cities] =  // массив указателей на 5 строк 
	{                           
		"Gribble City",
		"Gribbletown",
		"New Gribble",
		"San Gribble",
		"Gribble Vista"
	};

	int maxtemps[Years][Cities] =  // двумерный массив 
	{
		{ 96, 100, 87, 101, 105 },   // значения для maxtemps [0] 
		{ 96, 98, 91, 107, 104 },    // значения для maxtemps [1] 
		{ 97, 101, 93, 108, 107 },   // значения для maxtemps [2] 
		{ 98, 103, 95, 109, 108 }    // значения для maxtemps [3] 
	};

	cout << "Maximum temperatures for 2008 - 2011\n\n";
	for (int city = 0; city < Cities; ++city)
	{
		cout << cities[city] << ":\t";
		for (int year = 0; year < Years; ++year)
			cout << maxtemps[year][city] << "\t";
		cout << endl;
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Maximum temperatures for 2008 - 2011

Gribble City:   96      96      97      98
Gribbletown:    100     98      101     103
New Gribble:    87      91      93      95
San Gribble:    101     107     108     109
Gribble Vista:  105     104     107     108
*/