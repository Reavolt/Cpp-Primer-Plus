//copyit.cpp — copy() и итераторы 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <iterator> 
#include <vector> 

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;

	int casts[10] = { 6, 7, 2, 9 ,4 , 11, 8, 7, 10, 5 };
	vector<int> dice(10);
	// Копирование из массива в вектор 
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cast!\n";
	// Создание итератора ostream 
	ostream_iterator<int, char> out_iter(cout, " ");
	// Копирование из вектора в выходной поток 
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "Implicit use of reverse iterator.\n";
	// неявное использование обратного итератора 
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "Explicit use of reverse iterator.\n";
	vector<int>::reverse_iterator ri;  
	// явное использование обратного итератора 
	for (auto ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Let the dice be cast!
6 7 2 9 4 11 8 7 10 5
Implicit use of reverse iterator.
5 10 7 8 11 4 9 2 7 6
Explicit use of reverse iterator.
5 10 7 8 11 4 9 2 7 6
Для продолжения нажмите любую клавишу . . .
*/