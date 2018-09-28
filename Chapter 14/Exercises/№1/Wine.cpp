//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "Wine.h"

//-------------------------------------------------------------------------------------------------
Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	label = l;
	years = y;
	data.first.resize(years);
	data.second.resize(years);
	
	for (int i = 0; i < years; i++)
	{
		data.first[i] = yr[i];
		data.second[i] = bot[i];
	}
}
//-------------------------------------------------------------------------------------------------
Wine::Wine(const char* l, int y)
{
	label = l;
	years = y;
	data.first.resize(years);
	data.second.resize(years);
}
//-------------------------------------------------------------------------------------------------
Wine::~Wine()
{

}
//-------------------------------------------------------------------------------------------------
void Wine::Show() const
{
	std::cout << "Wine: " << label << std::endl;
	std::cout << "\tYear\tBottles" << std::endl;
	
	for (int i = 0; i < years; i++)
	{
		std::cout << "\t" << data.first[i] << "\t";
		std::cout << data.second[i] << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
const std::string & Wine::Label() const
{
	return label;
}
//-------------------------------------------------------------------------------------------------
void Wine::GetBottles()
{
	std::cout << "Enter " << label << " data for " << years << " year(s):\n";
	
	int input = 0;
	for (int i = 0; i < years; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> input;
		data.first[i] = input;
		std::cout << "Enter bottles for that year: ";
		std::cin >> input;
		data.second[i] = input;
		
		std::cout << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
int Wine::sum() const
{
	int sum = 0;
	for (int i = 0; i < years; i++)
	{
		sum += data.second[i];
	}
	return sum;
}
//-------------------------------------------------------------------------------------------------