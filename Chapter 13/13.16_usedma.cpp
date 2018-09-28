//usedma.cpp -- наследование, друзья и динамическое вьщеление памяти 
//Компилировать вместе с dma.h 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "13.14_dma.h" 

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "Displaying baseDMA object:\n";		// отображение объекта baseDMA 
	cout << shirt << endl;
	cout << "Displaying lacksDMA object:\n";	// отображение объекта lacksDMA 
	cout << balloon << endl;
	cout << "Displaying hasDMA object:\n";		// отображение объекта hasDMA 
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "Result of lacksDMA copy:\n";		// результат копирования lacksDMA 
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "Result of hasDMA assignment:\n";	// результат присваивания hasDMA 
	cout << map2 << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Displaying baseDMA object:
Label: Portabelly
Rating: 8

Displaying lacksDMA object:
Label: Blimpo
Rating: 4
Color: red

Displaying hasDMA object:
Label: Buffalo Keys
Rating: 5
Style: Mercator

Result of lacksDMA copy:
Label: Blimpo
Rating: 4
Color: red

Result of hasDMA assignment:
Label: Buffalo Keys
Rating: 5
Style: Mercator

Для продолжения нажмите любую клавишу . . .
*/