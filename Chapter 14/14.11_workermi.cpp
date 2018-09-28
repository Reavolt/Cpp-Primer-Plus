//worker0.cpp --методы классов работников 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring> 
#include "14.10_workermi.h"

using std::cout;
using std::cin;
using std::endl;

//-------------------------------------------------------------------------------------------------
// Методы Worker 
Worker::~Worker() { }
//-------------------------------------------------------------------------------------------------
// Защищенные методы 
void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}
//-------------------------------------------------------------------------------------------------
void Worker::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
//-------------------------------------------------------------------------------------------------
// Методы Waiter 
void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}
//-------------------------------------------------------------------------------------------------
void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Data();
	Data();
}
//-------------------------------------------------------------------------------------------------
// Защищенные методы 
void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}
//-------------------------------------------------------------------------------------------------
void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}
//-------------------------------------------------------------------------------------------------
// Методы Singer 
char * Singer::pv[Singer::Vtypes] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };
//-------------------------------------------------------------------------------------------------
void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}
//-------------------------------------------------------------------------------------------------
void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Data();
	Data();
}
//-------------------------------------------------------------------------------------------------
// Защищенные методы 
void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}
//-------------------------------------------------------------------------------------------------
void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << "   ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "Please enter a value >= 0 and < " << Vtypes << endl;
	while (cin.get() != '\n')
		continue;
}
//-------------------------------------------------------------------------------------------------
// Методы SingingWaiter 
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}
//-------------------------------------------------------------------------------------------------
void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}
//-------------------------------------------------------------------------------------------------
void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}
//-------------------------------------------------------------------------------------------------
void SingingWaiter::Show() const
{
	cout << "Category: singing waiter\n";
	Worker::Data();
	Data();
}
//-------------------------------------------------------------------------------------------------