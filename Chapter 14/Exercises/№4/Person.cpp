//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "Person.h"

//-------------------------------------------------------------------------------------------------
//Методы Person
void Person::Data() const
{
	std::cout << "First name: " << firstname << std::endl;
	std::cout << "Last name: " << lastname << std::endl;
}
//-------------------------------------------------------------------------------------------------
Person::Person(const std::string & first, const std::string & last)
{
	firstname = first;
	lastname = last;
}
//-------------------------------------------------------------------------------------------------
void Person::Show() const
{
	std::cout << "Type Person" << std::endl;
	Data();
}
//-------------------------------------------------------------------------------------------------
void Person::Set()
{
	std::cout << "Enter the first name: ";
	getline(std::cin, firstname);
	std::cout << "Enter the last name: ";
	getline(std::cin, lastname);
}
//-------------------------------------------------------------------------------------------------
//Методы Gunslinger
void Gunslinger::Data() const
{
	std::cout << "Draw time: " << drawtime << std::endl;
	std::cout << "Notches: " << notches << std::endl;
}
//-------------------------------------------------------------------------------------------------
void Gunslinger::setData()
{
	std::cout << "Enter the draw time: ";
	std::cin >> drawtime;
	while (!std::cin || drawtime < 0)
	{
		std::cin.clear();
		std::cout << "Draw time must be a positive number.\nTry again: ";
		std::cin >> drawtime;
	}

	std::cout << "Enter the number of notches: ";
	std::cin >> notches;
	while (!std::cin || notches < 0)
	{
		std::cin.clear();
		std::cout << "Draw time must be a positive integer.\nTry again: ";
		std::cin >> notches;
	}
}
//-------------------------------------------------------------------------------------------------
Gunslinger::Gunslinger(const std::string & first, const std::string & last, double d, int n) : 
	Person(first, last)
{
	drawtime = d;
	notches = n;
}
//-------------------------------------------------------------------------------------------------
void Gunslinger::setDrawTime(double d)
{
	if (d < 0)
	{
		std::cerr << "Error, draw time cannot be negative. ";
		std::cerr << "Setting draw time to 0." << std::endl;
		drawtime = 0;
	}
	else
	{
		drawtime = d;
	}
}
//-------------------------------------------------------------------------------------------------
void Gunslinger::setNotches(int n)
{
	if (n < 0)
	{
		std::cerr << "Error, notches cannot be negative. ";
		std::cerr << "Setting notches to 0." << std::endl;
		notches = 0;
	}
	else
	{
		notches = n;
	}
}
//-------------------------------------------------------------------------------------------------
void Gunslinger::Show() const
{
	std::cout << "Type Gunslinger" << std::endl;
	Person::Data();
	Data();
}
//-------------------------------------------------------------------------------------------------
//Методы PokerPlayer
PokerPlayer::PokerPlayer(std::string first, std::string last) : 
	Person(first, last) 
{
		
}
//-------------------------------------------------------------------------------------------------
void PokerPlayer::Show() const
{
	std::cout << "Type Poker Player" << std::endl;
	Person::Data();
}
//-------------------------------------------------------------------------------------------------
//Меитоды BadDude
BadDude::BadDude(std::string first, std::string last, double d, int n) : 
	Person(first, last), Gunslinger(first, last, d, n), PokerPlayer(first, last) 
{
	
}
//-------------------------------------------------------------------------------------------------
void BadDude::Show() const
{
	std::cout << "Type BadDude" << std::endl;
	Person::Data();
	Gunslinger::Data();
	PokerPlayer::Data();
}
//-------------------------------------------------------------------------------------------------
void BadDude::Set()
{
	Person::Set();
	Gunslinger::setData();
}
//-------------------------------------------------------------------------------------------------