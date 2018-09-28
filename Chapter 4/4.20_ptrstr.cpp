//ptrstr.cpp -- использование указателей на строки 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring> // объявление strlen(), strcpy() 

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	char animal[20] = "bear";	// animal содержит bear 
	const char * bird = "wren"; // bird содержит адрес строки 
	char * ps;					// не инициализировано 
	cout << animal << " and ";  // отображение bear 
	cout << bird << "\n";		// отображение wren 
	//cout << ps << "\n";		// может отобразить мусор, но может вызвать 
								// и аварийное завершение программы 
	cout << "Enter a kind of animal: ";
	cin >> animal;				// нормально, если вводится меньше 20 символов 
								// cin >> ps; очень опасная ошибка, чтобы пробовать; 
								// ps не указывает на выделенное пространство 
	ps = animal;				// установка ps в указатель на строку 
	cout << ps << "!\n";		// нормально; то же, что и применение animal 
	cout << "Before using strcpy():\n";
	cout << animal << " at " << (int *)animal << endl;
	cout << ps << " at " << (int *)ps << endl;
	ps = new char[strlen(animal) + 1]; // получение нового хранилища 
	strcpy_s(ps,strlen(ps), animal);   // копирование строки в новое хранилище 
	cout << "After using strcpy():\n";
	cout << animal << " at " << (int *)animal << endl;
	cout << ps << " at " << (int *) ps << endl;
	delete[] ps;
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
bear and wren
Enter a kind of animal: bear
bear!
Before using strcpy():
bear at 012FFD80
bear at 012FFD80
After using strcpy():
bear at 012FFD80
bear at 0131F5F8
*/