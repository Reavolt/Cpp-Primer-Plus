//pointer.ерр -- наша первая переменная-указатель 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int updates = 6; // объявление переменной 
	int* p_updates; // объявление указателя на int 
	p_updates = &updates; // присвоить адрес int указателю 
						  // Выразить значения двумя способами 
	cout << "Values: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;
	// Выразить адреса двумя способами 
	cout << "Addresses: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;
	// Изменить значение через указатель 
	*p_updates = *p_updates + 1;
	cout << "Now updates = " << updates << endl;

	cin.get();
	cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Values: updates = 6, *p_updates = 6
Addresses: &updates = 006FF7D4, p_updates = 006FF7D4
Now updates = 7
*/