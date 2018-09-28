//forstr2.cpp -- обращение порядка элементов массива 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	cout << "Enter a word: ";
	string word;
	cin >> word;
	// Физическая модификация объекта string 
	char temp;
	int i, j;
	for (j = 0, i = word.size() - 1; j < i; --i, ++j)
	{ // начало блока 
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	} // конец блока 
	cout << word << "\nDone\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter a word: stressed
desserts
Done
*/