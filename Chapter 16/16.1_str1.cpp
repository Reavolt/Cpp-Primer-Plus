//str1.cpp — введение в класс string 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
// Использование различных конструкторов класса string 

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	string one("Lottery Winner!");     // ctor #1
	cout << one << endl;               // перегруженная <<
	string two(20, '$');               // ctor #2
	cout << two << endl;
	string three(one);                 // ctor #3
	cout << three << endl;
	one += " Oops!";                   // перегруженная += 
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';
	string four;                       // ctor #4
	four = two + three;                // перегруженная +, = 
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);               // ctor #5
	cout << five << "!\n";
	string six(alls + 6, alls + 10);     // ctor #6
	cout << six << ", ";
	string seven(&five[6], &five[10]);   // снова ctor #6 
	cout << seven << "...\n";
	string eight(four, 7, 16);           // ctor #7
	cout << eight << " in motion!" << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Lottery Winner!
$$$$$$$$$$$$$$$$$$$$
Lottery Winner!
Lottery Winner! Oops!
Sorry! That was Pottery Winner!
All's well that ends!
well, well...
That was Pottery in motion!
Для продолжения нажмите любую клавишу . . .
*/