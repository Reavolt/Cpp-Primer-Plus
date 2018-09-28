//twofile2.срр -- переменные с внутренним и внешним связыванием 
//Компилировать c twofile1.cpp
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream> 

extern int tom; // переменная tom определена в другом месте 
static int dick = 10; // переопределяет внешнюю переменную dick 
int harry = 200; // определение внешней переменной, 
				 // конфликт с harry из twofilel отсутствует 
//-------------------------------------------------------------------------------------------------
void remote_access()
{
	using namespace std;
	cout << "remote_access () reports the following addresses:\n"; // вывод адресов 
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
}
//-------------------------------------------------------------------------------------------------
/*
main () reports the following addresses:
0022B00C = &tom, 0022B010 = &dick, 0022B014 = &harry
remote_access () reports the following addresses:
0022B00C = &tom, 0022B000 = &dick, 0022B004 = &harry
*/