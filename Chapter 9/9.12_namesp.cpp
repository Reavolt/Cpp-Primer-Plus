//namesp.cpp -- пространства имен 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "namesp.h" 

//-------------------------------------------------------------------------------------------------
namespace pers
{
	using std::cout;
	using std::cin;
	void getPerson(Person & rp)
	{
		cout << "Enter first name: "; // ввод имени 
		cin >> rp.fname;
		cout << "Enter last name: "; // ввод фамилии 
		cin >> rp.lname;
	}
	void showPerson(const Person & rp)
	{
		std::cout << rp.lname << ", " << rp.fname;
	}
}
//-------------------------------------------------------------------------------------------------
namespace debts
{
	void getDebt(Debt & rd)
	{
		getPerson(rd.name);
		std::cout << "Enter debt: "; // ввод суммы задолженности 
		std::cin >> rd.amount;
	}
	void showDebt(const Debt & rd)
	{
		showPerson(rd.name);
		std::cout << ": $" << rd.amount << std::endl;
	}
	double sumDebts(const Debt ar[], int n)
	{
		double total = 0;
		for (int i = 0; i < n; i++)
			total += ar[i].amount;
		return total;
	}
}
//-------------------------------------------------------------------------------------------------