//append.срр — добавление информации в файл 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	
#include <fstream>
#include <string>
#include <cstdlib>  // для exit() 

const char* file = "guests.txt";
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	char ch;

	// Отображение начального содержимого 
	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	// Добавление новых имен 
	ofstream fout(file, ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n"; //не удается открыть файл 
		exit(EXIT_FAILURE);
	}

	cout << "Enter guest names (enter a blank line to quit):\n";
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << name << endl;
	}
	fout.close();

	// Отображение измененного файла 
	fin.clear();  //не обязательно для некоторых компиляторов 
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter guest names (enter a blank line to quit):
Genghis Kant
Hank Attila
Charles Bigg

Here are the new contents of the guests.txt file:
Genghis Kant
Hank Attila
Charles Bigg
Done.
Для продолжения нажмите любую клавишу . . .

Here are the current contents of the guests.txt file:
Genghis Kant
Hank Attila
Charles Bigg
Enter guest names (enter a blank line to quit):
Greta Greppo
LaDonna Mobile
Fannie Mae

Here are the new contents of the guests.txt file:
Genghis Kant
Hank Attila
Charles Bigg
Greta Greppo
LaDonna Mobile
Fannie Mae
Done.
*/