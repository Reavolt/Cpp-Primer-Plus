//textin4.cpp -- чтение символов с помощью cin.get()
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int ch; // должно быть типа int, а не char 
	int count = 0;
	while ((ch = cin.get()) != EOF) // проверка конца файла 
	{
		cout.put(char(ch));
		++count;
	}
	cout << endl << count << " characters read\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
The sullen mackerel sulks in the shadowy shallows.<Enter>
The sullen mackerel sulks in the shadowy shallows.
Yes, but the blue bird of happiness harbors secrets.<Enter>
Yes, but the blue bird of happiness harbors secrets.
<Ctrl+Z><XEnter>
104 characters read
*/