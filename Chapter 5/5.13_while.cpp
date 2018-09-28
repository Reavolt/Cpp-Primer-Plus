//while.срр -- представление цикла while 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

using namespace std;

const int ArSize = 20;
//-------------------------------------------------------------------------------------------------
int main() 
{
	char name[ArSize];

	cout << "Your first name, please: "; // ввод имени 
	cin >> name;
	// Вывод имени посимвольно и в кодах ASCII 
	cout << "Here is your name, verticalized and ASCIIized:\n";
	int i = 0;                  // начать с начала строки 
	while (name[i] != '\0')     // обрабатывать до конца строки 
	{
		cout << name[i] << ": " << int(name[i]) << endl;
		i++;                    // не забудьте этот шаг 
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Your first name, please: Muffy
Here is your name, verticalized and ASCIIized:
M: 77
u: 117
f: 102
f: 102
y: 121
*/