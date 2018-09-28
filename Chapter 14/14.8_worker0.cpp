//worker0.cpp --методы классов работников 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring> 
#include "14.7_worker0.h"

using std::cout;
using std::cin;
using std::endl;

//-------------------------------------------------------------------------------------------------
// Методы Worker 
// Виртуальный деструктор должен быть реализован, даже если он является чистым 
Worker::~Worker() {}
//-------------------------------------------------------------------------------------------------
void Worker::Set()
{
	cout << "Enter worker's name: "; // ввод имени и фамилии работчика 
	getline(cin, fullname);
	cout << "Enter worker's ID: "; // ввод идентификатора работчика 
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
//-------------------------------------------------------------------------------------------------
void Worker::Show() const
{
	cout << "Name: " << fullname << "\n"; // имя и фамилия 
	cout << "Employee ID: " << id << "\n"; // идентификатор 
}
//-------------------------------------------------------------------------------------------------
// Методы Waiter 
void Waiter::Set()
{
	Worker::Set();
	cout << "Enter waiter's panache rating: ";
	// Ввод индекса элегантности официанта 
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}
//-------------------------------------------------------------------------------------------------
void Waiter::Show() const
{
	cout << "Category: waiter\n"; // категория: официант 
	Worker::Show();
	cout << "Panache rating: " << panache << "\n"; // индекс элегантности 
}
//-------------------------------------------------------------------------------------------------
// Методы Singer 
char * Singer::pv[] = { "other", "alto", "contralto","soprano", "bass", "baritone", "tenor" };
//-------------------------------------------------------------------------------------------------
void Singer::Set()
{
	Worker::Set();
	cout << "Enter number for singer's vocal range:\n";
	// Ввод номера вокального диапазона певца 
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ":" << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "Please enter a value >= 0 and < " << Vtypes << endl;
	while (cin.get() != '\n')
		continue;
}
//-------------------------------------------------------------------------------------------------
void Singer::Show() const
{
	cout << "Category: singer\n"; // категория: певец 
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl; // вокальный диапазон 
}
//-------------------------------------------------------------------------------------------------