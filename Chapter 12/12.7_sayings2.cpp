// sayings2.cpp — использование указателей на объекты 
// компилировать вместе с stringl.cpp 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <cstdlib> // (или stdlib.h) для rand(), srand() 
#include <ctime>   // (или time.h) для time() 
#include "12.4_string1.h"

const int ArSize = 10;
const int MaxLen = 81;
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	String name;
	cout << "Hi, what's your name?\n>> "; // ввод имени 
	cin >> name;
	cout << name << ", please enter up to " << ArSize
		 << " short sayings <empty line to quit>:\n"; // ввод пословиц 
	String sayings[ArSize];
	char temp[MaxLen]; // временное хранилище для строки 
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0') // пустая строка? 
			break; // i не. инкрементируется 
		else
			sayings[i] = temp; // перегруженное присваивание 
	}
	int total = i; // общее количество прочитанных строк 
	if (total > 0)
	{
		cout << "Here are your sayings:\n"; // вывод пословиц 
		for (i = 0; i < total; i++)
			cout << sayings[i] << "\n";
		// Указатели для отслеживания кратчайшей и первой строки 
		String * shortest = &sayings[0]; // ицициализация первым объектом 
		String * first = &sayings[0];
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first) // сравнение значений 
				first = &sayings[i]; // присваивание адреса 
		}
		cout << "Shortest saying: \n" << *shortest << endl;
		// вывод кратчайшей пословицы 
		cout << "First alphabetically: \n" << * first << endl;
		// вывод первой пословицы по алфавиту 
		srand(time(0));
		int choice = rand() % total; // выбор случайного индекса 
									 // Создание и инициализация объекта String с помощью new 
		String * favorite = new String(sayings[choice]);
		cout << "My favorite saying: \n" << *favorite << endl;
		// вывод любимой пословицы 
		delete favorite;
	}
	else
	cout << "Not much to say, eh?\n"; // ничего не было введено 
	cout << "Bye.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Hi, what's your name?
>> Kirt Rood
Kirt Rood, please enter up to 10 short sayings <empty line to quit>:
1: a friend in need is a friend indeed
2: neither a borrower nor a lender be
3: a stitch in time saves nine
4: a niche in time saves stine
5: it takes a crook to catch a crook
6: cold hands, warm heart
7:
Here are your sayings:
a friend in need is a friend indeed
neither a borrower nor a lender be
a stitch in time saves nine
a niche in time saves stine
it takes a crook to catch a crook
cold hands, warm heart
Shortest saying:
cold hands, warm heart
First alphabetically:
a friend in need is a friend indeed
My favorite saying:
cold hands, warm heart
Bye.
Для продолжения нажмите любую клавишу . . .
*/