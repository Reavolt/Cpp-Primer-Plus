//list.cpp -- использование списка
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

//-------------------------------------------------------------------------------------------------
void outint(int n) { std::cout << n << " "; }
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	list<int> one(5, 2); // список из 5 двоек 
	int stuff[5] = { 1,2,4,8, 6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = { 6, 4, 2, 4, 6, 5 };
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "List one: ";	// первый список 
	for_each(one.begin(), one.end(), outint);
	cout << endl << "List two: ";	// второй список
	for_each(two.begin(), two.end(), outint);
	cout << endl << "List three: ";	// третий список
	for_each(three.begin(), three.end(), outint);
	three.remove(2);
	cout << endl << "List three minus 2s: ";	
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);
	cout << endl << "List three after splice: ";	// третий список после splice() 
	for_each(three.begin(), three.end(), outint);
	cout << endl << "List one: ";
	for_each(one.begin(), one.end(), outint);
	three.unique();
	cout << endl << "List three after unique: ";	// третий список после unique()
	for_each(three.begin(), three.end(), outint);
	three.sort();
	three.unique();
	cout << endl << "List three after sort & unique: ";
	// третий список после sort() и unique() 
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << endl << "Sorted two merged into three: ";
	// слияние отсортированного второго списка с третьим 
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
List one: 2 2 2 2 2
List two: 1 2 4 8 6
List three: 1 2 4 8 6 6 4 2 4 6 5
List three minus 2s: 1 4 8 6 6 4 4 6 5
List three after splice: 2 2 2 2 2 1 4 8 6 6 4 4 6 5
List one:
List three after unique: 2 1 4 8 6 4 6 5
List three after sort & unique: 1 2 4 5 6 8
Sorted two merged into three: 1 1 2 2 4 4 5 6 6 8 8
Для продолжения нажмите любую клавишу . . .
*/