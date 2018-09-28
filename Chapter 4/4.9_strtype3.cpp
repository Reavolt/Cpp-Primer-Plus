//strtype3.cpp -- дополнительные средства класса string 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string> // обеспечение доступа к классу string 
#include <cstring> // библиотека обработки строк в стиле С 

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	// Присваивание объектов string и символьных массивов 
	str1 = str2; // копирование str2 в str2 
	strcpy(charr1, charr2); // копирование charr2 в charr1 

	// Добавление объектов string и символьных массивов 
	str1 += " paste"; // добавление " paste" в конец strl 
	strcat(charr1, " juice"); // добавление " juice" в конец charr1 

	// Определение длины объекта string и строки в стиле С 
	int len1 = str1.size(); // получение длины strl 
	int len2 = strlen(charr1); // получение длины charr1 

	cout << "The string " << str1 << " contains "
		 << len1 << " characters. \n";
	cout << "The string " << charr1 << " contains "
		 << len2 << " characters. \n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
The string panther paste contains 13 characters.
The string jaguar juice contains 12 characters.
*/