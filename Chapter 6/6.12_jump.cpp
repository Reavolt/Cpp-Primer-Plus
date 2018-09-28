//jump.срр -- использование операторов continue и break 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

const int ArSize = 80;
//-------------------------------------------------------------------------------------------------
int main()
{
	char line[ArSize];
	int spaces = 0;

	cout << "Enter a line of text:\n";	// запрос на ввод строки текста 
	cin.get(line, ArSize);
	cout << "Complete line:\n" << line << endl; // вывод полной строки 
	cout << "Line through first period:\n";	// вывод строки до первой точки 
	for (int i = 0; line[i] != '\0'; i++)
	{
		cout << line[i];    // отображение символа 
		if (line[i] == '.') // завершение, если это точка 
			break;
		if (line[i] != ' ') // пропуск оставшейся части цикла 
			continue;
		spaces++;
	}
	cout << "\n" << spaces << " spaces\n";
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter a line of text:
Let's do lunch today. You can pay!
Complete line:
Let's do lunch today. You can pay!
Line through first period:
Let's do lunch today.
3 spaces
Done.
*/