//strtype4.cpp -- ввод строки с пробелами 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string> // обеспечение доступа к классу string 
#include <cstring> // библиотека обработки строк в стиле С 

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	char charr[20];
	string str;

	// Длина строки в charr перед вводом 
	cout << "Length of string in charr before input: "
		 << strlen(charr) << endl;

	// Длина строки в str перед вводом 
	cout << "Length of string in str before input: "
		 << str.size() << endl;

	cout << "Enter a line of text:\n"; // ввод строки текста 
	cin.getline(charr, 20); // указание максимальной длины 
	cout << "You entered: " << charr << endl;

	cout << "Enter another line of text:\n"; // ввод другой строки текста 
	getline(cin, str); // теперь сіn - аргумент; спецификатор длины отсутствует 
	cout << "You entered: " << str << endl;

	// Длина строки в charr после ввода 
	cout << "Length of string in charr after input: "
		 << strlen(charr) << endl;
	// Длина строки в str после ввода 
	cout << "Length of string in str after input: "
		 << str.size() << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Length of string in charr before input: 27
Length of string in str before input: 0
Enter a line of text:
peanut butter
You entered: peanut butter
Enter another line of text:
blueberry jam
You entered: blueberry jam
Length of string in charr after input: 13
Length of string in str after input: 13
*/