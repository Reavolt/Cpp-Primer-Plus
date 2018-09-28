//listrmv.cpp -- применение STL к строке 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <list>
#include <algorithm>

const int LIM = 10;
//-------------------------------------------------------------------------------------------------
void Show(int);
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);

	cout << "Original list contents:\n\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	la.remove(4);
	cout << "After using the remove() method:\n";
	cout << "la:\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);
	cout << "After using the remove() function:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;
	lb.erase(last, lb.end());
	cout << "After using the erase() method:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void Show(int v)
{
	std::cout << v << ' ';
}
//-------------------------------------------------------------------------------------------------
/*
Original list contents:
4 5 4 2 2 3 4 8 1 4
After using the remove() method:
la:     5 2 2 3 8 1
After using the remove() function:
lb:     5 2 2 3 8 1 4 8 1 4
After using the erase() method:
lb:     5 2 2 3 8 1
*/