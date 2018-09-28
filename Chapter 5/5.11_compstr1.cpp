//compstr1.срр -- сравнение строк с использованием массивов 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring> // прототип для strcmp() 

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	char word[5] = "?ate";
	for (char ch = 'a'; strcmp(word, "mate"); ch ++)
	{
		 cout << word << endl;
		 word[0] = ch;
	}
	cout << "After loop ends, word is " << word << endl; // вывод word по завершении цикла 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
?ate
aate
bate
cate
date
eate
fate
gate
hate
iate
jate
kate
late
After loop ends, word is mate
*/