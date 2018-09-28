//init_ptr.cpp -- инициализация указателя 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int higgens = 5;
	int * pt = &higgens;
	cout << "Value of higgens = " << higgens
		 << "; Address of higgens = " << &higgens << endl;
	cout << "Value of *pt = " << *pt
		 << "; Value of pt = " << pt << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Value of higgens = 5; Address of higgens = 0113FC78
Value of *pt = 5; Value of pt = 0113FC78
*/