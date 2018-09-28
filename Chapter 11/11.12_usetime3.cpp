// usetime3.cpp — использование четвертой черновой версии класса Time 
// Компилировать usetime3.cpp и mytime3.cpp вместе 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "11.10_mytime3.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;
	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca; // operator* () 
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17; // функция-член operator*() 
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Aida and Tosca:
3 hours, 35 minutes; 2 hours, 48 minutes
Aida + Tosca: 6 hours, 23 minutes
Aida * 1.17: 4 hours, 11 minutes
10.0 * Tosca: 28 hours, 0 minutes
Для продолжения нажмите любую клавишу . . .
*/