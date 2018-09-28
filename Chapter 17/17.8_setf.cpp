//setf.срр — использование setf() для управления форматированием 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	int temperature = 63;

	cout << "Today's water temperature: ";
	cout.setf(ios_base::showpos);   // показывать знак плюс 
	cout << temperature << endl;

	cout << "For our programming friends, that's\n";
	cout << std::hex << temperature << endl; // использование шестнадцатеричного представления
	cout.setf(ios_base::uppercase);  // применение прописных символов в шестнадцатеричном представлении 
	cout.setf(ios_base::showbase);   // использование префикса ОХ для шестнадцатеричных значений 
	cout << "or\n";
	cout << temperature << endl;
	cout << "How " << true << "!  oops -- How ";
	cout.setf(ios_base::boolalpha);
	cout << true << "!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Today's water temperature: +63
For our programming friends, that's
3f
or
0X3F
How 0X1!  oops -- How true!
*/