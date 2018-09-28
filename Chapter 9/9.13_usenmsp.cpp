//usenmsp.срр -- использование пространств имен 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "namesp.h" 

//-------------------------------------------------------------------------------------------------
void other(void);
void another(void);
//-------------------------------------------------------------------------------------------------
int main()
{
	using debts::Debt;
	using debts::showDebt;
	Debt golf = { { "Benny", "Goatsnif f" }, 120.0 };
	showDebt(golf);
	other();
	another();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;
	Person dg = { "Doodles", "Glister" };
	showPerson(dg);
	cout << endl;
	Debt zippy[3];
	int i;
	for (i = 0; i < 3; i++)
		getDebt(zippy[i]);
	for (i = 0; i < 3; i++)
		showDebt(zippy[i]);
	cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
	return;
}
//-------------------------------------------------------------------------------------------------
void another(void)
{
	using pers::Person;
	Person collector = { "Milo", "Rightshift" };
	pers::showPerson(collector);
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------
/*
Goatsnif f, Benny: $120
Glister, Doodles
Enter first name: Arabella
Enter last name: Binx
Enter debt: 100
Enter first name: Cleve
Enter last name: Delaproux
Enter debt: 120
Enter first name: Eddie
Enter last name: Fiotox
Enter debt: 200
Binx, Arabella: $100
Delaproux, Cleve: $120
Fiotox, Eddie: $200
Total debt: $420
Rightshift, Milo
*/