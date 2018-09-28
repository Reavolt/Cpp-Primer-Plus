//strgback.срр -- функция, возвращающая указатель на char 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------------------------
char* buildstr(char c, int n); // прототип 
//------------------------------------------------------------------------------------------------
int main() 
{
	int times;
	char ch;
	cout << "Enter a character: "; // ввод символа 
	cin >> ch;
	cout << "Enter an integer: ";  // ввод целого числа 
	cin >> times;
	char *ps = buildstr(ch, times);
	cout << ps << endl;
	delete[] ps;					// освобождение памяти 
	ps = buildstr('+', 20);		// повторное использование указателя 
	cout << ps << "-DONE-" << ps << endl;
	delete[] ps;					// освобождение памяти 

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
// Строит строку из п символов с 
char* buildstr(char c, int n)
{
	char* pstr = new char[n + 1];
	pstr[n] = '\0';		// завершение строки 
	while (n-- > 0)
		   pstr[n] = c;		// заполнение остатка строки 
	return pstr;
}
//------------------------------------------------------------------------------------------------
/*
Enter a character: V
Enter an integer: 46
VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
++++++++++++++++++++-DONE-++++++++++++++++++++
*/