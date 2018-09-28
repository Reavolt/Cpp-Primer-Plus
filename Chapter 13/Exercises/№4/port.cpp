//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "port.h"

//-------------------------------------------------------------------------------------------------
Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 20);
	
	if (b < 0)
	{
		std::cout << "Number of bottles must be a positive integer." << std::endl;
		std::cout << "Setting bottles to 0." << std::endl;
		bottles = 0;
	}
	else
	{
		bottles = b;
	}
}
//-------------------------------------------------------------------------------------------------
Port::Port(const Port & p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}
//-------------------------------------------------------------------------------------------------
Port & Port::operator = (const Port & p)
{
	if (this == &p)
	{
		return *this;
	}
	else
	{
		delete[] brand;
		brand = new char[strlen(p.brand) + 1];
		strcpy(brand, p.brand);
		strcpy(style, p.style);
		bottles = p.bottles;
	}
	return *this;
}
//-------------------------------------------------------------------------------------------------
Port & Port::operator += (int b)
{
	bottles += b;
	return *this;
}
//-------------------------------------------------------------------------------------------------
Port & Port::operator -= (int b)
{
	if (b > bottles)
	{
		std::cout << "You cannot subtract more bottles than you have!" << std::endl;
		std::cout << "Subtracting " << bottles << " bottles." << std::endl;
		bottles = 0;
	}
	else
	{
		bottles -= b;
	}
	return *this;
}
//-------------------------------------------------------------------------------------------------
void Port::Show() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
	std::ciut << std::endl;
}
//-------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}
//-------------------------------------------------------------------------------------------------