//hexoctl.срр -- показывает шестнадцатеричные и восьмеричные литералы 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int chest = 42;
	int waist = 0x42;
	int inseam = 042;

	cout << "Monsieur cuts a striking figure!\n";
	cout << "Chest = " << chest << " (42 in decimal)\n";
	cout << "Waist = " << waist << " (0x42 in hex)\n";
	cout << "inseam = " << inseam << " (042 in octal)\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Monsieur cuts a striking figure!
chest = 42 (42 in decimal)
waist = 66 (0x42 in hex)
inseam = 34 (042 in octal)
*/