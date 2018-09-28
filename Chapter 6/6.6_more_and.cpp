//more_and.cрр -- использование логической операции "И" 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
const char* qualify[4] =          // массив указателей на строки 
{   
	"10,000-meter race.\n",	       // забег на 10 000 метров 
	"mud tug-of-war.\n",		   // перетягивание каната в грязи 
	"masters canoe jousting.\n",   // состязания мастеров каноэ 
	"pie-throwing festival.\n"	   // фестиваль по бросанию пирожков 
};
//-------------------------------------------------------------------------------------------------
int main() 
{
	int age;
	cout << "Enter your age in years: ";	// запрос возраста в годах 
	cin >> age;
	int index;

	if (age > 17 && age < 35)
		index = 0;
	else if (age >= 35 && age < 50)
		index = 1;
	else if (age >= 50 && age < 65)
		index = 2;
	else
		index = 3;

	cout << "You qualify for the " << qualify[index]; // вывод рекомендованного результата 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter your age in years: 87
You qualify for the pie-throwing festival.
*/