//addpntrs.ерр -- сложение указателей 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3, 2, 1 };

	// Два способа получить адрес массива 
	double * pw = wages; // имя массива равно адресу 

	// либо использование операции взятия адреса с элементом массива 
	short * ps = &stacks[0];
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "add 1 to the pw pointer: \n"; // добавление 1 к указателю pw 
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "add 1 to the ps pointer: \n"; // добавление 1 к указателю ps 
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

	// Доступ к двум элементам с помощью нотации массивов 
	cout << "access two elements with array notation\n";
	cout << "stacks[0] = " << stacks[0]
		 << ", stacks[1] = " << stacks[1] << endl;

	// Доступ к двум элементам с помощью нотации указателей 
	cout << "access two elements with pointer notation\n";
	cout << "*stacks = " << *stacks
		 << ", * (stacks + 1) = " << * (stacks + 1) << endl;

	cout << sizeof(wages) << " = size of wages array\n"; // размер массива wages 
	cout << sizeof(pw) << " = size of pw pointer\n"; // размер указателя pw 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
pw = 010FFC28, *pw = 10000
add 1 to the pw pointer:
pw = 010FFC30, *pw = 20000

ps = 010FFC18, *ps = 3
add 1 to the ps pointer:
ps = 010FFC1A, *ps = 2

access two elements with array notation
stacks[0] = 3, stacks[1] = 2
access two elements with pointer notation
*stacks = 3, * (stacks + 1) = 2
24 = size of wages array
4 = size of pw pointer
*/