//strtype2.cpp -- присваивание, сложение, добавление
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string> // обеспечение доступа к классу string 

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	string si = "penguin";
	string s2, s3;

	// Присваивание одного объекта string другому 
	cout << "You can assign one string object to another: s2 = sl\n";
	s2 = si;
	cout << "si: " << si << ", s2: " << s2 << endl;

	// Присваивание строки в стиле С объекту string 
	cout << "You can assign a C-style string to a string object.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2: " << s2 << endl;

	// Конкатенация строк 
	cout << "You can concatenate strings: s3 = si + s2\n";
	s3 = si + s2;
	cout << "s3: " << s3 << endl;

	// Добавление строки 
	cout << "You can append strings. \n";
	si += s2;
	cout << "sl += s2 yields si = " << si << endl;
	s2 += " for a day";
	cout << "s2 += \" for a day\" yields s2 = " << s2 << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/* 
You can assign one string object to another: s2 = si 
si: penguin, s2: penguin 
You can assign a C-style string to a string object. 
52 = "buzzard" 
s2: buzzard 
You can concatenate strings: s3 = si + s2 
s3: penguinbuzzard 
You can append string's. 
si += s2 yields si = penguinbuzzard 
s2 += " for a day" yields s2 = buzzard for a day  
*/