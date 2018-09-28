//sumfile.cpp -- чтение файла
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <fstream>   // для файлового ввода-вывода 
#include <cstdlib>   // поддержка exit() 

const int SIZE = 60;
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	
	char filename[SIZE];
	ifstream inFile;       // объект для обработки файлового ввода 

	cout << "Enter name of data file: "; // запрос имени файла данных 
	cin.getline(filename, SIZE);
	inFile.open(filename);  // ассоциирование inFile с файлом 
	if (!inFile.is_open())  // не удалось открыть файл 
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;         // количество прочитанных элементов 

	inFile >> value;        // ввод первого значения 
	while (inFile.good())   // пока ввод успешен и не достигнут EOF 
	{
		++count;            // еще один элемент прочитан 
		sum += value;       // вычисление текущей суммы 
		inFile >> value;    // ввод следующего значения 
	}
	if (inFile.eof())
		// достигнут конец файла 
		cout << "End of file reached.\n";
	else if (inFile.fail())
		// ввод прекращен из-за несоответствия типа данных 
		cout << "Input terminated by data mismatch.\n";
	else
		// ввод прекращен по неизвестной причине 
		cout << "Input terminated for unknown reason.\n";
	if (count == 0)
		// данные для обработки отсутствуют 
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;	// прочитано элементов 
		cout << "Sum: " << sum << endl;				// сумма 
		cout << "Average: " << sum / count << endl; // среднее значение 
	}
	inFile.close();        // завершение работы с файлом 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter name of data file: scores.txt
End of file reached.
Items read: 12
Sum: 204.5
Average: 17.0417
*/