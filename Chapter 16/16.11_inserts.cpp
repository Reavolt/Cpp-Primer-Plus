//inserts.срр — сору() и итераторы вставки 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

//-------------------------------------------------------------------------------------------------
void output(const std::string & s) { std::cout << s << " "; }
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	string s1[4] = { "fine", "fish", "fashion", "fate" };
	string s2[2] = { "busy", "bats" };
	string s3[2] = { "silly", "singers" };
	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), output);
	cout << endl;

	// Конструирование анонимного объекта типа back_insert_iterator 
	copy(s2, s2 + 2, back_insert_iterator<vector<string> >(words));
	for_each(words.begin(), words.end(), output);
	cout << endl;

	// Конструирование анонимного объекта типа insert_iterator 
	copy(s3, s3 + 2, insert_iterator<vector<string> >(words, words.begin()));
	for_each(words.begin(), words.end(), output);
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
fine fish fashion fate
fine fish fashion fate busy bats
silly singers fine fish fashion fate busy bats
Для продолжения нажмите любую клавишу . . .
*/