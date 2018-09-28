#include "stdafx.h"
#include <iostream>
#include <cstring> 
#include "VintagePort.h"

//-------------------------------------------------------------------------------------------------
VintagePort::VintagePort() : Port("The Noble", "Vintage")
{
	nickname = nullptr;
	year = 1900;
}
//-------------------------------------------------------------------------------------------------
VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "Vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}
//-------------------------------------------------------------------------------------------------
VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}
//-------------------------------------------------------------------------------------------------
VintagePort & VintagePort::operator = (const VintagePort & vp)
{
	if (this == &vp)
	{
		return *this;
	}
	else
	{
		Port::operator=(vp);
		delete[] nickname;
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy(nickname, vp.nickname);
		year = vp.year;
	}
	return *this;
}
//-------------------------------------------------------------------------------------------------
void VintagePort::Show() const
{
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Year: " << year << std::endl;
}
//-------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
{
	os << (const Port &)vp;

	if (nullptr == vp.nickname)
	{
		os << ", " << vp.year;
	}
	else
	{
		os << ", " << vp.nickname << ", " << vp.year;
	}
	return os;
}
//-------------------------------------------------------------------------------------------------