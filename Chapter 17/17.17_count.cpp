//count.срр --- подсчет символов в списке файлов 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	
#include <fstream>
#include <cstdlib>    // для exit() 

//-------------------------------------------------------------------------------------------------
int main(int argc, char * argv[])
{
	using namespace std;
	if (argc == 1)         // выход при отсутствии аргументов 
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin;              // открытие потока 
	long count;
	long total = 0;
	char ch;

	for (int file = 1; file < argc; file++)
	{
		fin.open(argv[file]);  // подключение потока к argv[file] 
		if (!fin.is_open())
		{
			cerr << "Could not open " << argv[file] << endl;	//не удается открыть файл 
			fin.clear();
			continue;
		}
		count = 0;
		while (fin.get(ch))
			count++;
		cout << count << " characters in " << argv[file] << endl; // количество символов в файле 
		total += count;
		fin.clear();       // требуется для некоторых реализаций 
		fin.close();       // отключение от файла 
	}
	cout << total << " characters in all files\n";	// количество символов во всех файлах 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
$ a.out
Usage: a.out filename[s]
$ a.out paris rome
3580 characters in paris
4886 characters in rome
8466 characters in all files
$
*/