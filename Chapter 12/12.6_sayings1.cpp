// sayingsl.cpp — использование расширенного класса String 
// компилировать вместе с stringl.cpp 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "12.4_string1.h"

const int ArSize = 10;
const int MaxLen = 81;
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	String name;
	cout << "Hi, what's your name?\n>> "; // ввод имени 
	cin >> name;
		cout << name << ", please enter up to " << ArSize
		<< " short sayings <empty line to quit>:\n"; // ввод поговорки 
	String sayings[ArSize]; // массив объектов 
	char temp[MaxLen]; // временное хранилище для строки 
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0') // пустая строка? 
			break; // i не инкрементируется 
		else
			sayings[i] = temp; // перегруженное присваивание 
	}
	int total = i; // общее количество прочитанных строк 
	if (total > 0)
	{
		cout << "Here are your sayings:\n"; // вывод поговорок 
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}
		cout << "Shortest saying:\n" << sayings[shortest] << endl;
		// Самая короткая поговорка 
		cout << "First alphabetically:\n" << sayings[first] << endl;
		// Первая по алфавиту 
		cout << "This program used " << String::HowMany()
			 << " String objects. Bye.\n";
		// Количество используемых объектов String 
	}
	else
		cout << "No input! Bye.\n"; // ничего не было введено 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Hi, what's your name?
>> Misty Gutz
Misty Gutz, please enter up to 10 short sayings <empty line to quit>:
1: a fool and his money are soon parted
2: penny wise, pound foolish
3: the love of money is the root of much evil
4: out of sight, out of mind
5: absence makes the heart grow fonder
6: absinthe makes the hart grow fonder
7:
Here are your sayings:
a: a fool and his money are soon parted
p: penny wise, pound foolish
t: the love of money is the root of much evil
o: out of sight, out of mind
a: absence makes the heart grow fonder
a: absinthe makes the hart grow fonder
Shortest saying:
penny wise, pound foolish
First alphabetically:
a fool and his money are soon parted
This program used 11 String objects. Bye.
Для продолжения нажмите любую клавишу . . .
*/