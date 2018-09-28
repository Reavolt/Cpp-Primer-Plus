//strc_ref.cpp -- использование ссылок на структуру 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------------------
struct free_throws
{
	string name;
	int made;
	int attempts;
	float percent;
};
//-------------------------------------------------------------------------------------------------
void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);
//-------------------------------------------------------------------------------------------------
int main()
{
	// Частичные инициализации — оставшиеся неинициализированными 
	// члены устанавливаются в О 
	free_throws one = { "Ifelsa Branch", 13, 14 };
	free_throws two = { "Andor Knott", 10, 16 };
	free_throws three = { "Minnie Max", 7, 9 };
	free_throws four = { "Whily Looper", 5, 9 };
	free_throws five = { "Long Long", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };

	// Инициализация не производится
	free_throws dup;
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);

	// Использование возвращаемого значения в качестве аргумента 
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);

	// Использование возвращаемого значения в присваивании 
	dup = accumulate(team, five);
	cout << "Displaying team:\n";
	display(team);

	// Отображение dup после присваивания 
	cout << "Displaying dup after assignment:\n";
	display(dup);
	set_pc(four);
	// Неблагоразумное присваивание 
	accumulate(dup, five) = four;

	// Отображение dup после неблагоразумного присваивания 
	cout << "Displaying dup after ill-advised assignment:\n";
	display(dup);

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void display(const free_throws & ft)
{
	cout << "Name: " << ft.name << '\n';		 // вывод члена name 
	cout << "Made: " << ft.made << '\t';		 // вывод члена made 
	cout << "Attempts: " << ft.attempts << '\t'; // вывод члена attempts 
	cout << "Percent: " << ft.percent << '\n';   // вывод члена percent 
}
//-------------------------------------------------------------------------------------------------
void set_pc(free_throws & ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f *float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;
}
//-------------------------------------------------------------------------------------------------
free_throws & accumulate(free_throws & target, const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}
//-------------------------------------------------------------------------------------------------
/*
Name: Ifelsa Branch
Made: 13        Attempts: 14    Percent: 92.8571
Name: Throwgoods
Made: 13        Attempts: 14    Percent: 92.8571
Name: Throwgoods
Made: 23        Attempts: 30    Percent: 76.6667
Name: Throwgoods
Made: 35        Attempts: 48    Percent: 72.9167
Displaying team:
Name: Throwgoods
Made: 41        Attempts: 62    Percent: 66.129
Displaying dup after assignment:
Name: Throwgoods
Made: 41        Attempts: 62    Percent: 66.129
Displaying dup after ill-advised assignment:
Name: Whily Looper
Made: 5 Attempts: 9     Percent: 55.5556
*/