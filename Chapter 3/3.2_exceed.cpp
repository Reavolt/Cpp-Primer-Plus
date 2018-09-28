//exceed.срр -- выход за пределы для некоторых целочисленных типов 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#define ZERO 0

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	short sam = SHRT_MAX; // инициализируем переменную максимальным значением
	unsigned short sue = sam;

	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl
		 << "Add $1 to each account." << endl << "Now ";
	sam = sam + 1;
	sue = sue + 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited.\nPoor Sam!" << endl;
	sam = ZERO;
	sue = ZERO;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl;
	cout << "Take $1 from each account." << endl << "Now ";
	sam = sam - 1;
	sue = sue - 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl << "Lucky Sue!" << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Sam has 32767 dollars and Sue has 32767 dollars deposited. 
Add $1 to each account. 
Now Sam has -32768 dollars and Sue has 32768 dollars deposited. 
Poor Sam! 
Sam has 0 dollars and Sue has 0 dollars deposited. 
Take $1 from each account. 
Now Sam has -1 dollars and Sue has 65535 dollars deposited. 
Lucky Sue!
*/