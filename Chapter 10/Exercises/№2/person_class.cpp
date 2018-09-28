//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "person_class.h" 

//-------------------------------------------------------------------------------------------------
Person::Person(const std::string& In, const char* fn) 
{
	lname = In;
	strcpy(fname, fn);
}
//-------------------------------------------------------------------------------------------------
Person::~Person() 
{
	//The body of the destructor
}
//-------------------------------------------------------------------------------------------------
void Person::Show() const 
{
	std::cout << fname << " " << lname << std::endl;
}
//-------------------------------------------------------------------------------------------------
void Person::FormalShow() const 
{
	std::cout << fname << " " << lname << std::endl;
}
//-------------------------------------------------------------------------------------------------