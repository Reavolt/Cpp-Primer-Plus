//usealgo.срр -- использование нескольких элементов STL 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;

//-------------------------------------------------------------------------------------------------
char toLower(char ch) { return tolower(ch); }
string & ToLower(string & st);
void display(const string & s);
//-------------------------------------------------------------------------------------------------
int main()
{
	vector<string> words;
	cout << "Enter words (enter quit to quit):\n";	// запрос на ввод слов 
	string input;
	while (cin >> input && input != "quit")
		words.push_back(input);

	cout << "You entered the following words:\n";	// отображение введенных слов 
	for_each(words.begin(), words.end(), display);
	cout << endl;

	// Помещение слов в набор с преобразование букв в строчные 
	set<string> wordset;
	transform(words.begin(), words.end(),
		insert_iterator<set<string> >(wordset, wordset.begin()),
		ToLower);
	cout << "\nAlphabetic list of words:\n";	// список слов в алфавитном порядке 
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	// Помещение и частоты его помещения в карту 
	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		 wordmap[*si] = count(words.begin(), words.end(), *si);

	// Отображение содержимого карты 
	cout << "\nWord frequency:\n";	// частота появления слов 
	for (si = wordset.begin(); si != wordset.end(); si++)
		 cout << *si << ": " << wordmap[*si] << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
string & ToLower(string & st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}
//-------------------------------------------------------------------------------------------------
void display(const string & s)
{
	cout << s << " ";
}
//-------------------------------------------------------------------------------------------------
/*
Enter words (enter quit to quit):
The dog saw the cat and thought the cat fat
The cat thought the cat perfect
quit
You entered the following words:
The dog saw the cat and thought the cat fat The cat thought the cat perfect

Alphabetic list of words:
and cat dog fat perfect saw the thought

Word frequency:
and: 1
cat: 4
dog: 1
fat: 1
perfect: 1
saw: 1
the: 5
thought: 2
Для продолжения нажмите любую клавишу . . .
*/