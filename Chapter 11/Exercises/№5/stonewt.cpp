// stonewt.срр -- методы класса Stonewt 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "stonewt.h"

//-------------------------------------------------------------------------------------------------
// Конструирует объект Stonewt из значения типа double 
Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn; // целочисленное деление 
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	dpounds = lbs;
	ipounds = int(lbs);
	setmode();
}
//-------------------------------------------------------------------------------------------------
// Конструирует объект Stonewt из стоунов и значения типа double 
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	dpounds = stn * Lbs_per_stn + lbs;
	ipounds = int(stn * Lbs_per_stn + lbs);
	setmode();
}
//-------------------------------------------------------------------------------------------------
// конструктор по умолчанию, wt = 0 
Stonewt::Stonewt()
{
	stone = ipounds = dpounds = pds_left = 0;
}
//-------------------------------------------------------------------------------------------------
// деструктор
Stonewt::~Stonewt()
{

}
//-------------------------------------------------------------------------------------------------
void Stonewt::setmode()
{
	if (pds_left == 0)
	{
		mode = STONE;
	}
	else 
	if (pds_left - int(pds_left))
	{
		mode = dPOUND;
	}
	else
	{
		mode = iPOUND;
	}
}
//-------------------------------------------------------------------------------------------------
void Stonewt::setmode(int m)
{
	if (m == 0)
	{
		mode = STONE;
	}
	else 	
	if (m == 1)
	{
		mode = iPOUND;
	}
	else 
	if (m == 2)
	{
		mode = dPOUND;
	}
	else
	{
		std::cout << "\n\tWarning! Invalid argument to the setmode() function..";
		std::cout << "\n\tThe mode is set to STONE.\n\n";
		mode = STONE;
	}
}
//-------------------------------------------------------------------------------------------------
Stonewt operator+(const Stonewt & stn1, const Stonewt & stn2)
{
	Stonewt Result = stn1 + stn2;
	return Result;
}
//-------------------------------------------------------------------------------------------------
Stonewt operator-(const Stonewt & stn1, const Stonewt & stn2)
{
	Stonewt Result = stn1 - stn2;
	return Result;
}
//-------------------------------------------------------------------------------------------------
Stonewt operator*(const Stonewt & stn1, const Stonewt & stn2)
{
	Stonewt Result = stn1 * stn2;
	return Result;
}
//-------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const Stonewt & stn)
{
	if (stn.mode == stn.STONE)
	{
		os << stn.stone << " stone, " << stn.pds_left << " pounds.";
	}
	else 
	if (stn.mode == stn.iPOUND)
	{
		os << stn.ipounds << " pounds.";
	}
	else
	{
		os << stn.dpounds << " pounds.";
	}
	return os;
}
//-------------------------------------------------------------------------------------------------