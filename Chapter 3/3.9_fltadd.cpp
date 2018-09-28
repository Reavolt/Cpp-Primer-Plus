//fltadd.cpp -- потеря точности при работе с float
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	float a = 2.34E+22F;
	float b = a + 1.0F;

	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
а = 2.34е+022
b - а = 0
*/