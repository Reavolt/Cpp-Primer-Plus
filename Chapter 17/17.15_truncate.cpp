//truncate.срр — использование get() для усечения входной строки в случае необходимости 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
const int SLEN = 10;
inline void eatline() { while (std::cin.get() != '\n') continue; }
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	char name[SLEN];
	char title[SLEN];
	cout << "Enter your name: ";	// приглашение для ввода имени 
	cin.get(name, SLEN);
	if (cin.peek() != '\n')
		cout << "Sorry, we only have enough room for "
		<< name << endl;	// вывод сообщения о недостатке места 
	eatline();
	cout << "Dear " << name << ", enter your title: \n";	//приглашение для ввода должности 
	cin.get(title, SLEN);
	if (cin.peek() != '\n')
		cout << "We were forced to truncate your title.\n";	// вынужденное усечение названия должности 
	eatline();
	cout << " Name: " << name
		<< "\nTitle: " << title << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter your name: Ella Fishsniffer
Sorry, we only have enough room for Ella Fish
Dear Ella Fish, enter your title:
Executive Adjunct
We were forced to truncate your title.
Name: Ella Fish
Title: Executive
*/