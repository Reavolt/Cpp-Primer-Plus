//carrots.cpp: -- программа по технологии производства пищевых продуктов 
//использует и отображает переменную
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	int carrots;
	
	carrots = 25;
	cout << "I have " << carrots << " carrots.";
	cout << endl;
	carrots = carrots - 1;
	cout << "Crunh, Crunch. Now I have " << carrots << " carrots." << endl;
	
	std::cin.get();
	std::cin.get();
    	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
I have 25 carrots.
Crunh, Crunch. Now I have 24 carrots.
*/
