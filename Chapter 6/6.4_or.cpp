//or.срр -- использование логической операции "ИЛИ" 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	cout << "This program may reformat your hard disk\n"
		"and destroy all your data.\n"
		"Do you wish to continue? <y/n> ";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y') // у или Y 
		cout << "You were warned! \a\a\n";
	else if (ch == 'n' || ch == 'N') // n или N 
		cout << "A wise choice . . . bye\n";
	else
		cout << "That wasn't а у or n! Apparently you "
		"can't follow\ninstructions, so "
		"I'll trash your disk anyway.\a\a\a\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
This program may reformat your hard disk
and destroy all your data.
Do you wish to continue? <y/n> N
A wise choice . . . bye
*/