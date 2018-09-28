//forstrl.cpp -- использование цикла for для строки 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
int main() 
{
	using namespace std;
	cout << "Enter a word: ";
	string word;
	cin >> word;
	// Отображение символов в обратном порядке 
	for (int i = word.size() - 1; i >= 0; i--)
		 cout << word[i];
	cout << "\nBye.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter a word: animal
lamina
Bye.
*/