//fileio.cpp
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	// для многих систем не требуется 
#include <fstream>
#include <string>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	string filename;

	cout << "Enter name for new file: ";	// запрос имени нового файла 
	cin >> filename;

	// Создание объекта выходного потока для нового файла и назначение ему имени fout 
	ofstream fout(filename.c_str());

	fout << "For your eyes only!\n";      // запись в файл 
	cout << "Enter your secret number: "; // вывод на экран 
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();           // закрытие файла 

	// Создание объекта входного потока для нового файла и назначение ему имени fin 
	ifstream fin(filename.c_str());
	cout << "Here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch))  // чтение символа из файла 
		cout << ch;      // и его вывод на экран
	cout << "Done\n";
	fin.close();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter name for new file: pythag
Enter your secret number: 3.14159
Here are the contents of pythag:
For your eyes only!
Your secret number is 3.14159
Done

file pythag
For your eyes only!
Your secret number is 3.14159
*/