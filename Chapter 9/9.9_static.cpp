//static.срр -- использование статической локальной переменной 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

// Константы 
const int ArSize = 10;
//-------------------------------------------------------------------------------------------------
// Прототип функции 
void strcount(const char* str);
//-------------------------------------------------------------------------------------------------
int main() 
{
	using namespace std;
	char input[ArSize];
	char next;

	cout << "Enter a line:\n";
	cin.get(input, ArSize);
	while (cin)
	{
		cin.get(next);
		while (next != '\n') // строка не помещается; 
			cin.get(next);   // избавиться от остатка 
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		cin.get(input, ArSize);
	}
	cout << "Bye\n";

	cin.clear();
	while (cin.get() != '\n')
		   continue;
	cin.get();
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void strcount(const char* str)
{
	using namespace std;
	static int total = 0; // статическая локальная переменная 
	int count = 0; // автоматическая локальная переменная 
	cout << "\"" << str << "\" contains ";
	while (*str++) // переход к концу строки 
	   	   count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
//-------------------------------------------------------------------------------------------------
/*
Enter a line:
nice pants
"nice pant" contains 9 characters
9 characters total
Enter next line (empty line to quit):
thanks
"thanks" contains 6 characters
15 characters total
Enter next line (empty line to quit):
parting is such sweet sorrow
"parting i" contains 9 characters
24 characters total
Enter next line (empty line to quit):
ok
"ok" contains 2 characters
26 characters total
Enter next line (empty line to quit):

Bye
*/