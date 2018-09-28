//twod.cpp — создание двумерного массива 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "14.17_arraytp.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP< ArrayTP<int, 5>, 10> twodee;

	int i, j;

	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;
		for (j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}
		cout << ": sum = ";
		cout.width(3);
		cout << sums[i] << ", average = " << aves[i] << endl;
	}
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
1  2  3  4  5 : sum =  15, average = 1.5
2  4  6  8 10 : sum =  30, average = 3
3  6  9 12 15 : sum =  45, average = 4.5
4  8 12 16 20 : sum =  60, average = 6
5 10 15 20 25 : sum =  75, average = 7.5
6 12 18 24 30 : sum =  90, average = 9
7 14 21 28 35 : sum = 105, average = 10.5
8 16 24 32 40 : sum = 120, average = 12
9 18 27 36 45 : sum = 135, average = 13.5
10 20 30 40 50 : sum = 150, average = 15
Done.
*/