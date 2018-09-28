//structur.срр -- простая структура
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
struct inflatable // объявление структуры 
{
	char name[20];
	float volume;
	double price;
};
//-------------------------------------------------------------------------------------------------
int main() 
{
	inflatable guest =
	{
		"Glorious Gloria", // значение name 
		1.88,			   // значение volume 
		29.99			   // значение value 
	};					   // guest — структурная переменная типа inflatable 
	// Инициализация указанными значениями 

	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	}; // pal — вторая переменная типа inflatable 

	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name << "!\n"; // pal.name - член name переменной pal 
	cout << "You can have both for $";
	cout << guest.price + pal.price << "!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Expand your guest list with Glorious Gloria and Audacious Arthur!
You can have both for $62.98!
*/