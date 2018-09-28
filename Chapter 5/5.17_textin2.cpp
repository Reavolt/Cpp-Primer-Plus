//textin2.срр -- использование cin.get(char) 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	char ch;
	int count = 0;
	cout << "Enter characters; enter # to quit:\n";
	cin.get(ch); // использование функции cin.get(ch) 
	while (ch != '#') 
	{
		cout << ch;
		++count;
		cin.get(ch); // использование ее снова 
	}
	cout << endl << count << " characters read\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter characters; enter # to quit:
Did you use a #2 pencil?
Did you use a
14 characters read
*/