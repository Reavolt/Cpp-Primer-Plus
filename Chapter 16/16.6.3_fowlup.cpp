//fowlup.cpp  -- unique_ptr не хороший выбор
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include <memory>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	unique_ptr<string> films[5] =
	{
		unique_ptr<string>(new string("Fowl Balls")),
		unique_ptr<string>(new string("Duck Walks")),
		unique_ptr<string>(new string("Chicken Runs")),
		unique_ptr<string>(new string("Turkey Errors")),
		unique_ptr<string>(new string("Goose Eggs"))
	};
	unique_ptr<string> pwin;
	pwin = films[2];   // films[2], pwin оба указывают на "Chicken Runs"

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Невозможно использовать присваивание -> строка 20
*/