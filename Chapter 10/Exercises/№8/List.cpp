//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "List.h"

//-------------------------------------------------------------------------------------------------
List::List() 
{
	for (size_t i = 0; i < MAX; i++)
	{
		items[i] = "NON";
	}
	top = 0;
}
//-------------------------------------------------------------------------------------------------
List::~List() 
{
	std::cout << "Working with the list is complete" << std::endl;
}
//-------------------------------------------------------------------------------------------------
bool List::isempty() const 
{
	if (top == 0)
	{
		std::cout << "The list is empty" << std::endl;
	}
	return top == 0;
}
//-------------------------------------------------------------------------------------------------
bool List::isfull() const 
{
	if (top == MAX)
	{
		std::cout << "The list is full" << std::endl;
	}
	return top == MAX;
}
//-------------------------------------------------------------------------------------------------
bool List::add_element(const std::string & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
void List::visit_element(void(*pf)(std::string &))
{
	for (int i = 0; i < top; ++i)
	{
		(*pf)(items[i]);
	}
}
//-------------------------------------------------------------------------------------------------
void List::show_list()
{
	for (size_t i = 0; i < top; i++)
	{
		std::cout << "Value №" << i + 1 << " added: " << std::endl;
		std::cout << items[i] << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
void List::reset_list()
{
	top = 0;
}
//-------------------------------------------------------------------------------------------------