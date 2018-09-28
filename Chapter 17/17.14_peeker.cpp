//peeker.срр — некоторые методы istream 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	// Считывание и отображение символов до символа # 
	char ch;

	while (cin.get(ch))      // завершение по достижении EOF 
	{
		if (ch != '#')
			cout << ch;
		else
		{
			cin.putback(ch);  // повторная вставка символа 
			break;
		}
	}

	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";	// достигнут конец файла 
		std::exit(0);
	}

	while (cin.peek() != '#')  // "заглядывание" вперед 
	{
		cin.get(ch);
		cout << ch;
	}
	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
		cout << "End of file reached.\n";	// достигнут конец файла 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
I used а #3 pencil when I should have used a #2.
I used а
# is next input character.
3 pencil when I should have used a
# is next input character.
*/