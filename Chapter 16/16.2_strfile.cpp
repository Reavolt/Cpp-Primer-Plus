//strfile.cpp -- чтение строк из файла 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		cerr << "Can't open file. Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;

	getline(fin, item, ':');
	while (fin)  // while input is good
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done\n";
	fin.close();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
file tobuy.txt
sardines:chocolate ice cream:pop corn:leeks:
cottage cheese:olive oil:butter:tofu:
========================
1: sardines
2: chocolate ice cream
3: pop corn
4: leeks
5:
cottage cheese
6: olive oil
7: butter
8: tofu
Done
Для продолжения нажмите любую клавишу . . .
*/