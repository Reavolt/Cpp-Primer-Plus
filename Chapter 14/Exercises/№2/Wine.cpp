//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "Wine.h"

//-------------------------------------------------------------------------------------------------
Wine::Wine(const char * l, int y) : 
	PairArray(ArrayInt(y), ArrayInt(y)), std::string(l)
{
	years = y;
}
//-------------------------------------------------------------------------------------------------
Wine::Wine(const char * l, int y, const int yr[], const int bot[]) :
	PairArray(ArrayInt(y), ArrayInt(y)), std::string(l)
{
	years = y;
	for (int i = 0; i < years; i++)
	{
		PairArray::first()[i] = yr[i];
		PairArray::second()[i] = bot[i];
	}
}
//-------------------------------------------------------------------------------------------------
Wine::~Wine()
{

}
//-------------------------------------------------------------------------------------------------
const std::string & Wine::Label() const
{
	return (const std::string &)(*this);
}
//-------------------------------------------------------------------------------------------------
void Wine::Show() const
{
	std::cout << "Wine: " << Label() << std::endl;
	std::cout << "\tYear\tBottles" << std::endl;
	
	for (int i = 0; i < years; i++)
	{
		std::cout << "\t" << PairArray::first()[i] << "\t";
		std::cout << PairArray::second()[i] << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
void Wine::GetBottles()
{
	std::cout << "Enter " << Label() << " data for " << years << " year(s):\n";
	
	int input;
	for (int i = 0; i < years; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> input;
		PairArray::first()[i] = input;
		std::cout << "Enter bottles for that year: ";
		std::cin >> input;
		PairArray::second()[i] = input;
		
		std::cout << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
int Wine::sum() const
{
	int sum = 0;
	for (int i = 0; i < years; i++)
	{
		sum += PairArray::second()[i];
	}
	return sum;
}
//-------------------------------------------------------------------------------------------------