// stack.срр -- функции-члены класса Stack 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "Stack_class.h" 

//-------------------------------------------------------------------------------------------------
Stack::Stack() 
{
	top = 0;
}
//-------------------------------------------------------------------------------------------------
bool Stack::isempty() const
{
	return top == 0;
}
//-------------------------------------------------------------------------------------------------
bool Stack::isfull() const
{
	return top == MAX;
}
//-------------------------------------------------------------------------------------------------
bool Stack::push(const Items & item)
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
bool Stack::pop(Items & item) 
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------