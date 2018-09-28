//arrstruc.срр -- массив структур 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
//-------------------------------------------------------------------------------------------------
int main() 
{
	inflatable guests[2] = // инициализация массива структур 
	{
		{ "Bambi", 0.5, 21.99 }, // первая структура в массиве 
		{ "Godzilla" , 2000, 565.99 } // следующая структура в массиве 
	};
	cout << "The guests " << guests[0].name << " and " << guests[1].name
		 << "\nhave a combined volume of "
		 << guests[0].volume + guests[1].volume << " cubic feet.\n";

	cin.get();
	cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
The guests Bambi and Godzilla
have a combined volume of 2000.5 cubic feet
*/