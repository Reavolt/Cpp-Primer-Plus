//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring> // для strlen(), strcpy()

//-------------------------------------------------------------------------------------------------
struct stringy 
{
	char* str;		// указывает на строку 
	int ct;			// длина строки (не считая символа '\0') 
};
//-------------------------------------------------------------------------------------------------
void set(stringy & beany, const char* testing);
void show(const char* string, int size = 1);
void show(const stringy & beany, int size = 1);
void clear_memory(stringy & beany);
//-------------------------------------------------------------------------------------------------
int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing); // первым аргументом является ссылка, 
						 // Выделяет пространство для хранения копии testing, 
						 // использует элемент типа str структуры beany как указатель 
						 // на новый блок, копирует testing в новый блок и 
						 // создает элемент ct структуры beany 

	show(beany);		 // выводит строковый член структуры один раз 
	show(beany, 2);		 // выводит строковый член структуры два раза 
	clear_memory(beany);

	testing[0] = 'D';
	testing[1] = 'u';

	show(testing);		 // выводит сроку testing один раз 
	show(testing, 3);	 // выводит строку testing три раза 
	show("Done!");

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void set(stringy & beany, const char* testing) 
{
	beany.ct = strlen(testing);
	beany.str = new char[beany.ct + 1];
	strcpy(beany.str, testing);
}
//-------------------------------------------------------------------------------------------------
void show(const char* string, int size) 
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << string << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
void show(const stringy & beany, int size) 
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << beany.str << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
void clear_memory(stringy & beany)
{
	delete[] beany.str;
}
//-------------------------------------------------------------------------------------------------