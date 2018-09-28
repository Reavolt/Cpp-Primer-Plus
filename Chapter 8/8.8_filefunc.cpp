//filefunc.cpp -- функция с параметром ostream & 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <fstream> 

using namespace std;

const int LIMIT = 5;
//-------------------------------------------------------------------------------------------------
void file_it(ostream & os, double fo, const double fe[], int n);
//-------------------------------------------------------------------------------------------------
int main()
{
	ofstream fout;
	const char * fn = "ер-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{ 
		cout << "Can't open " << fn << ". Bye.\n"; // не удается открыть файл 
		exit(EXIT_FAILURE);
	}
	double objective;
	// Ввод фокусного расстояния объектива телескопа в мм 
	cout << "Enter the focal length of your "
		"telescope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];
	// Ввод фокусного расстояния окуляров в мм 
	cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "Done\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void file_it(ostream & os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed); // сохранение исходного состояния форматирования 
	os.precision(0);
	os << "Focal length of objective: " << fo << " mm\n"; // фокусное расстояние объектива 
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(12);
	os << "f.l. eyepiece";
	os.width(15);
	os << "magnification" << endl; // коэффициент увеличения 
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial); // восстановление исходного состояния форматирования 
}
//-------------------------------------------------------------------------------------------------
/*
Enter the focal length of your telescope objective in mm: 1800
Enter the focal lengths, in mm, of 5 eyepieces:
Eyepiece #1: 30
Eyepiece #2: 19
Eyepiece #3: 14
Eyepiece #4: 8.8
Eyepiece #5: 7.5
Focal length of objective: 1800 mm
f.l. eyepiece  magnification
30.0             60
19.0             95
14.0             129
8.8              205
7.5              240
Done
*/