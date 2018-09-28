//tv.cpp - методы для класса Тѵ (методы Remote являются встроенными) 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "tv.h"

//-------------------------------------------------------------------------------------------------
bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
void Tv::chanup()
{
	if (channel < maxchannel)
	{
		channel++;
	}
	else
	{
		channel = 1;
	}
}
//-------------------------------------------------------------------------------------------------
void Tv::chandown()
{
	if (channel > 1)
	{
		channel--;
	}
	else
	{
		channel = maxchannel;
	}
}
//-------------------------------------------------------------------------------------------------
void Tv::settings() const
{
	std::cout << "TV is " << (state == Off ? "Off" : "On") << std::endl;	// выключен или включен 
	
	if (state == On)
	{
		std::cout << "Volume setting = " << volume << std::endl;			// уровень громкости 
		std::cout << "Channel setting = " << channel << std::endl;			// номер канала 
		std::cout << "Mode = ";
		std::cout << (mode == Antenna ? "antenna" : "cable") << std::endl;	// антенна или кабель 
		std::cout << "Input = ";
		std::cout << (input == TV ? "TV" : "DVD") << std::endl;				// вход: TV или DVD 
	}
}
//-------------------------------------------------------------------------------------------------
void Tv::toggleRemoteMode(Remote & r) const
{
	if (On == state && r.mode_i == Remote::Interactive)
	{
		r.mode_i = Remote::Normal; // это нормально?
	}
	else 
	if (On == state && r.mode_i == Remote::Normal)
	{
		r.mode_i = Remote::Interactive;
	}
	else
	{
		return;
	}
}
//-------------------------------------------------------------------------------------------------
void Remote::settings() const
{
	std::cout << "Remote is set to the ";
	std::cout << (mode_d == Tv::TV ? "TV" : "VCR");
	std::cout << " and is in ";
	std::cout << (mode_i == Normal ? "Normal" : "Interactive") << " mode" << std::endl;
}
//-------------------------------------------------------------------------------------------------