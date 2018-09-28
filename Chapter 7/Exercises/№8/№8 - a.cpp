//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <array> 
#include <string> 

const int Seasons = 4;
//-------------------------------------------------------------------------------------------------
const char* Snames[Seasons] = 
{ 
	"Spring", "Summer", "Fall", "Winter" 
};
//-------------------------------------------------------------------------------------------------
void fill(double expenses[], const int Seasons);
void show(double expenses[], const int Seasons);
//-------------------------------------------------------------------------------------------------
int main()
{	
	double expenses[Seasons];
	fill(expenses, Seasons);
	show(expenses, Seasons);
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void fill(double expenses[], const int Seasons)
{
	for (int i = 0; i < Seasons; i++)
	{
		 std::cout << "Enter " << Snames[i] << " expenses: ";
		 std::cin >> expenses[i];
	}
}
//-------------------------------------------------------------------------------------------------
void show(double expenses[], const int Seasons)
{
	double total = 0.0;
	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		 std::cout << Snames[i] << ": $" << expenses[i] << std::endl;
		 total += expenses[i];
	}
	std::cout << "Total Expenses: $" << total << std::endl;
}
//-------------------------------------------------------------------------------------------------