//plus_one.cpp -- операция инкремента 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int a = 20;
	int b = 20;

	cout << "а = " << a << ": b = " << b << "\n";
	cout << "a++ = " << a++ << " : ++b = " << ++b << "\n";
	cout << "a = " << a << ": b = " << b << "\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
а = 20: b = 20
a++ = 20 : ++b = 21
a = 21: b = 21
*/