//twotemps.срр -- использование перегруженных шаблонов функций 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

const int Lim = 8;
//-------------------------------------------------------------------------------------------------
template <typename T> // исходный шаблон 
void Swap(T &a, T &b);
template <typename T> // новый шаблон 
void Swap(T a[], T b[], int n);
void Show(int a[]);
//-------------------------------------------------------------------------------------------------
int main()
{
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i, j); // соответствует исходному шаблону 
	cout << "Now i, j = " << i << ", " << j << ".\n";
	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,7,2,0,1,9,6,9 };
	cout << "Original arrays:\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim); // соответствует новому шаблону 
	cout << "Swapped arrays:\n";
	Show(d1);
	Show(d2);

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
void Swap(T & a, T & b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
void Swap(T a[], T b[], int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
//-------------------------------------------------------------------------------------------------
void Show(int a[])
{
	using namespace std;
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
	cout << a[i];
	cout << endl;
}
//-------------------------------------------------------------------------------------------------
/*
i, j = 10, 20.
Using compiler-generated int swapper:
Now i, j = 20, 10.
Original arrays:
07/04/1776
07/20/1969
Swapped arrays:
07/20/1969
07/04/1776
*/