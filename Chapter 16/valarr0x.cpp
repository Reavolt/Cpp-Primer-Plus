//valarr0x.cpp
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <valarray>
#include <algorithm>
#include <cstdlib>

const int size_ten = 10;

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;

	valarray<double> numbers(size_ten);
	int i;
	for (i = 0; i < size_ten; i++)
		numbers[i] = rand() + i * 1.23;

	for (i = 0; i < size_ten; i++)
		cout << numbers[i] << ' ';
	cout << endl;
	sort(begin(numbers), end(numbers));
	for (i = 0; i < size_ten; i++)
		cout << numbers[i] << ' ';
	cout << endl;
	// cin.get();

	std::cin.get();
	std::cin.get();
    return 0;
}
//-------------------------------------------------------------------------------------------------
/*
41 18468.2 6336.46 26503.7 19173.9 15730.1 11485.4 29366.6 26971.8 24475.1
41 6336.46 11485.4 15730.1 18468.2 19173.9 24475.1 26503.7 26971.8 29366.6
Для продолжени¤ нажмите любую клавишу . . .
*/