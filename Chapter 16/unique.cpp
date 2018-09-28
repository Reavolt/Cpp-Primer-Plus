//unique.cpp
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include <memory>

using namespace std;

//-------------------------------------------------------------------------------------------------
unique_ptr<string> demo(const char * s)
{
	unique_ptr<string> temp(new string(s));
	return temp;
}
//-------------------------------------------------------------------------------------------------
int main()
{
	unique_ptr<string> ps1, ps2;
	ps1 = demo("Uniquely special");
	ps2 = move(ps1); // включить назначение
	ps1 = demo(" and more");
	cout << *ps2 << *ps1 << endl;
	
	std::cin.get();
	std::cin.get();
    return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Uniquely special and more
Для продолжения нажмите любую клавишу . . .
*/