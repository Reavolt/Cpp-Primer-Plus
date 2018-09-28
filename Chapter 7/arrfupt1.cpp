//arfupt.cpp -- массив указателей на функции 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

using namespace std;
//------------------------------------------------------------------------------------------------
// Различные нотации, одни и те же сигнатуры 
const double* f1(const double ar[], int n);
const double* f2(const double[], int);
const double* f3(const double*, int);
//------------------------------------------------------------------------------------------------
int main() 
{
	double av[3] = { 1112.3, 1542.6, 2227.9 };
	
	//указатель на функцию
	typedef const double *(*p_fun)(const double *, int);
	p_fun p1 = f1;
	auto p2 = f2; // C++ 0x автоматический вывод типа
	cout << "Using pointers to functions:\n";
	cout << " Address  Value\n";
	cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

	// pa массив указателей
	p_fun pa[3] = { f1,f2,f3 };
	// auto не работает с инициализацией списка
	// но он работает для инициализации до одного значения
	// pb указатель на первый элемент pa
	auto pb = pa;
	cout << "\nUsing an array of pointers to functions:\n";
	cout << " Address  Value\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
	cout << "\nUsing a pointer to a pointer to a function:\n";
	cout << " Address  Value\n";
	for (int i = 0; i < 3; i++)
		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

	// Использование указателя на массив указателей на функции
	cout << "\nUsing pointers to an array of pointers:\n";
	cout << " Address  Value\n";
	//простой способ объявления pc
	auto pc = &pa;
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
	// более сложнее объявить pd
	p_fun(*pd)[3] = &pa;
	// хранить возвращаемое значение в pdb
	const double * pdb = (*pd)[1](av, 3);
	cout << pdb << ": " << *pdb << endl;
	// альтернативные обозначения
	cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
// Простейшие функции 
const double* f1(const double* ar, int n) 
{
	return ar;
}
//------------------------------------------------------------------------------------------------
const double* f2(const double ar[], int n) 
{
	return ar + 1;
}
//------------------------------------------------------------------------------------------------
const double* f3(const double ar[], int n) 
{
	return ar + 2;
}
//------------------------------------------------------------------------------------------------
/*
Using pointers to functions:
Address  Value
0093FCA8: 1112.3
0093FCB0: 1542.6

Using an array of pointers to functions:
Address  Value
0093FCA8: 1112.3
0093FCB0: 1542.6
0093FCB8: 2227.9

Using a pointer to a pointer to a function:
Address  Value
0093FCA8: 1112.3
0093FCB0: 1542.6
0093FCB8: 2227.9

Using pointers to an array of pointers:
Address  Value
0093FCA8: 1112.3
0093FCB0: 1542.6
0093FCB8: 2227.9
*/