//morechar.срр -- сравнение типов char и int 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	char ch = 'M'; //Присваиваем ch код ASCII символа M
	int i = ch; //Сохраняем этот же код в int
	cout << "The ASCII code for " << ch << " is " << i << endl;
	
	cout << "Add one to the character code: " << endl;
	ch = ch + 1; //Изменяем код символа в ch
	i = ch; //Сохраняем код нового символа в i
	cout << "The ASCII code for " << ch << " is " << i << endl;

	//Использование функции-члена cout.put(ch) для отображения символа
	cout << "Display char ch using cout.put(ch): ";
	cout.put(ch);
	//Использование cout.put() для отображения символьной костанты
	cout.put('!');

	cout << endl << "Done" << endl;
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
The ASCII code for M is 77
Add one to the character code:
The ASCII code for N is 78
Displaying char ch using cout.put (ch) : N!
Done
*/