//getfun.cpp — использование get() и getline () 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

const int Limit = 255;

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char input[Limit];

	cout << "Enter a string for getline() processing:\n";	// запрос на ввод строки 
	cin.getline(input, Limit, '#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 1\n";

	char ch;
	cin.get(ch);
	cout << "The next input character is " << ch << endl;

	if (ch != '\n')
		cin.ignore(Limit, '\n');    // отбрасывание остальной части строки 

	cout << "Enter a string for get() processing:\n";
	cin.get(input, Limit, '#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 2\n";

	cin.get(ch);
	cout << "The next input character is " << ch << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter a string for getline() processing:
Please pass
me a #3 melon!
Here is your input:
Please pass
me a
Done with phase 1
The next input character is 3
Enter a string for get() processing:
I still
want my #3 melon
Here is your input:
I still
want my
Done with phase 2
The next input character is #
*/