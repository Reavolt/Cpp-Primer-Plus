//limits.срр -- некоторые ограничения целых чисел 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	//операция sizeof выдает размер типа или переменной
	cout << "int is " << sizeof(int) << " bytes." << endl;
	cout << "short is " << sizeof n_short << " bytes." << endl;
	cout << "long is " << sizeof n_long << " bytes." << endl;
	cout << "long long is " << sizeof n_llong << " bytes." << endl;
	cout << endl;

	cout << "Maximum values: " << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl;
	cout << endl;

	cout << "Minimum int values: = " << INT_MIN <<endl;
	cout << "Bits per byte: = " << CHAR_BIT << endl;
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
int is 4 bytes, 
short is 2 bytes, 
long is 4 bytes. 
long long is 8 bytes. 
Maximum values: 
int: 2147483647 
short: 32767 
long: 2147483647 
long long: 9223372036854775807 
Minimum int value = -2147483648 
Bits per byte = 8 
*/