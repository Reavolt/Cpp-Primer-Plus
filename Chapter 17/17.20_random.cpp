//random.срр — произвольный доступ к бинарному файлу 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	//для большинства систем не требуется 
#include <fstream>
#include <iomanip>
#include <cstdlib>  // для exit() 

const int LIM = 20;
//-------------------------------------------------------------------------------------------------
struct planet
{
	char name[LIM];     // название планеты 
	double population;  // название планеты 
	double g;           // ускорение свободного падения 
};
//-------------------------------------------------------------------------------------------------
const char* file = "planets.dat";  // ПРЕДПОЛАГАЕТСЯ, ЧТО СУЩЕСТВУЕТ (пример binary.срр) 
inline void eatline() { while (std::cin.get() != '\n') continue; }
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	planet pl;
	cout << fixed;

	// Отображение начального содержимого 
	fstream finout;    // потоки чтения и записи 
	finout.open(file,
		ios_base::in | ios_base::out | ios_base::binary);
	// Примечание: некоторые системы Unix требуют опустить | ios:ibinary 
	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);  // перейти в начало 
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (finout.read((char *)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
			finout.clear(); // очистить флаг eof 
		else
		{
			cerr << "Error in reading " << file << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " could not be opened -- bye.\n";
		exit(EXIT_FAILURE);
	}

	// Изменить запись 
	cout << "Enter the record number you wish to change: ";
	long rec;
	cin >> rec;
	eatline();              // избавление от символов новой строки
	if (rec < 0 || rec >= ct)
	{
		cerr << "Invalid record number -- bye\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl;  // преобразование в тип streampos 
	finout.seekg(place);    // произвольный доступ 
	if (finout.fail())
	{
		cerr << "Error on attempted seek\n";
		exit(EXIT_FAILURE);
	}

	finout.read((char *)&pl, sizeof pl);
	cout << "Your selection:\n";
	cout << rec << ": " << setw(LIM) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
		finout.clear();    // очистить флаг eof 

	cout << "Enter planet name: ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "Enter planetary population: ";
	cin >> pl.population;
	cout << "Enter planet's acceleration of gravity: ";
	cin >> pl.g;
	finout.seekp(place);    // вернуться назад 
	finout.write((char *)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "Error on attempted write\n";
		exit(EXIT_FAILURE);
	}

	// Отображение измененного файла 
	ct = 0;
	finout.seekg(0);     // перейти в начало файла 
	cout << "Here are the new contents of the " << file
		<< " file:\n";
	while (finout.read((char *)&pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(LIM) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Here are the current contents of the planets.dat file:
0: Earth: 6928198253 9.81
1: Jenny's World: 32155648 8.93
2: Tramtor: 89000000000 15.03
3: Trellan: 5214000 9.62
4: Freestone: 3945851000 8.68
5: Taanagoot: 361000004 10.23
6: Marin: 252409 9.79
Enter the record number you wish to change: 2
Your selection:
2: Tramtor: 89000000000 15.03
Enter planet name: Trantor
Enter planetary population: 89521844777
Enter planet's acceleration of gravity: 10.53
Here are the new contents of the planets.dat file:
0: Earth: 6928198253 9.81
1: Jenny's World: 32155648 8.93
2: Trantor: 89521844777 10.53
3: Trellan: 5214000 9.62
4: Freestone: 3945851000 8.68
5: Taanagoot: 361000004 10.23
6: Marin: 252409 9.79
Done.
*/