//swaps.срр -- обмен значениями с помощью ссылок и указателей 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;
//-------------------------------------------------------------------------------------------------
void swapr(int & a, int & b); // a, b - псевдонимы для int 
void swapp(int* p, int* q); // p, q - адреса int 
void swapv(int a, int b); // a, b - новые переменные 
//-------------------------------------------------------------------------------------------------
int main()
{
	int wallet1 = 300;
	int wallet2 = 350;
	cout << "walletl = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	// Использование ссылок для обмена содержимого 
	cout << "Using references to swap contents:\n";
	swapr(wallet1, wallet2); // передача переменных 
	cout << "walletl = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	// Использование указателей для обмена содержимого 
	cout << "Using pointers to swap contents again:\n";
	swapp(&wallet1, &wallet2); // передача адресов переменных 
	cout << "walletl = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	// Попытка использования передачи по значению 
	cout << "Trying to use passing by value:\n";
	swapv(wallet1, wallet2); // передача значений переменных 
	cout << "walletl = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void swapr(int & a, int & b) // использование ссылок 
{
	int temp;
	temp = a; // использование a, b для получения значений переменных 
	a = b;
	b = temp;
}
//-------------------------------------------------------------------------------------------------
void swapp(int* p, int* q) // использование указателей 
{
	int temp;
	temp = *p; // использование *р, *q для получения значений переменных 
	*p = *q;
	*q = temp;
}
//-------------------------------------------------------------------------------------------------
void swapv(int a, int b) // попытка использования значений 
{
	int temp;
	temp = a; // использование a, b для получения значений переменных 
	a = b;
	b = temp;
}
//-------------------------------------------------------------------------------------------------
/*
walletl = $300 wallet2 = $350
Using references to swap contents:
walletl = $350 wallet2 = $300
Using pointers to swap contents again:
walletl = $300 wallet2 = $350
Trying to use passing by value:
walletl = $300 wallet2 = $350
*/