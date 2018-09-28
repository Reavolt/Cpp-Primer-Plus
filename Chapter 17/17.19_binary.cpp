//binary.срр — бинарный файловый ввод-вывод 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	// для большинства систем не требуется 
#include <fstream>
#include <iomanip>
#include <cstdlib>  // для exit() 

const char* file = "planets.dat";
//-------------------------------------------------------------------------------------------------
inline void eatline() { while (std::cin.get() != '\n') continue; }
//-------------------------------------------------------------------------------------------------
struct planet
{
	char name[20];      // название планеты 
	double population;  // население 
	double g;           // ускорение свободного падения 
};
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	planet pl;
	cout << fixed << right;

	// Отображение начального содержимого 
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary); // бинарный файл 
	// Примечание: некоторые системы не принимают режим ios_base:rbinary 
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (fin.read((char *)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}

	// Добавление новых данных 
	ofstream fout(file,
		ios_base::out | ios_base::app | ios_base::binary);
	// Примечание: некоторые системы не принимают режим ios:ibinary 
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output:\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter planet name (enter a blank line to quit):\n";	// ввод названия планеты 
	cin.get(pl.name, 20);
	while (pl.name[0] != '\0')
	{
		eatline();
		cout << "Enter planetary population: ";	// ввод названия планеты 
		cin >> pl.population;
		cout << "Enter planet's acceleration of gravity: ";
		// Ввод ускорения свободного падения 
		cin >> pl.g;
		eatline();
		fout.write((char *)&pl, sizeof pl);
		cout << "Enter planet name (enter a blank line "
			"to quit):\n";	// ввод названия планеты 
		cin.get(pl.name, 20);
	}
	fout.close();

	// Отображение измененного файла 
	fin.clear();    // не обязательно в некоторых реализациях, но это не помешает 
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.read((char *)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter planet name (enter a blank line to quit):
Earth
Enter planetary population: 6928198253
Enter planet's acceleration of gravity: 9.81
Enter planet name (enter a blank line to quit):

Here are the new contents of the planets.dat file:
Earth:   6928198253  9.81
Done.
Для продолжения нажмите любую клавишу . . .

Here are the current contents of the planets.dat file:
Earth:   6928198253  9.81
Enter planet name (enter a blank line to quit):
Jenny1s World
Enter planetary population: 32155648
Enter planet's acceleration of gravity: 8.93
Enter planet name (enter a blank line to quit):

Here are the new contents of the planets.dat file:
Earth:   6928198253  9.81
Jenny1s World :     32155648  8.93
Done.
*/