//strin.cpp -- форматированное чтение из символьного массива 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	
#include <sstream> 
#include <string> 

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	string lit = "It was a dark and stormy day, and "
		" the full moon glowed brilliantly. ";
	istringstream instr(lit); // использование буфера для ввода 
	string word;
	while (instr >> word)   // чтение по одному слову 
		cout << word << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
It
was
a
dark
and
stormy
day,
and
the
full
moon
glowed
brilliantly.
*/