//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "class.h"

// Методы класса Queue 
//-------------------------------------------------------------------------------------------------
Cow::Cow()
{
	std::cout << " --- Default constructor called" << std::endl;
	
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}
//-------------------------------------------------------------------------------------------------
Cow::Cow(const char* nm, const char* ho, double wt)
{
	std::cout << " --- Сonstructor with parameters was called" << std::endl;
	
	strncpy(name, nm, 20);
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}
//-------------------------------------------------------------------------------------------------
Cow::Cow(const Cow & c)
{
	std::cout << " --- Copy Constructor called" << std::endl;
	
	strncpy(name, c.name, 20);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}
//-------------------------------------------------------------------------------------------------
Cow::~Cow()
{
	std::cout << " --- Called the destructor" << std::endl;
	
	delete[] hobby;
}
//-------------------------------------------------------------------------------------------------
Cow & Cow::operator = (const Cow & c)
{
	std::cout << " --- Assignment operator called" << std::endl;
	
	if (this == &c)
	{
		return *this;
	}
	delete[] hobby;
	
	strncpy(name, c.name, 20);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	
	return *this;
}
//-------------------------------------------------------------------------------------------------
void Cow::ShowCow() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Hobby: " << hobby << std::endl;
	std::cout << "Weight: " << weight << std::endl;
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------