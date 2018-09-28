//studentc.срр — класс Student, использующий включение 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring> 
#include "14.1_studentc.h"

//-------------------------------------------------------------------------------------------------
// Открытые методы 
double Student::Average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}
//-------------------------------------------------------------------------------------------------
const std::string & Student::Name() const
{
	return name;
}
//-------------------------------------------------------------------------------------------------
double & Student::operator[](int i)
{
	return scores[i]; // использует valarray<double>::operator[]() 
}
//-------------------------------------------------------------------------------------------------
double Student::operator[](int i) const
{
	return scores[i];
}
//-------------------------------------------------------------------------------------------------
// Закрытый метод 
std::ostream & Student::arr_out(std::ostream & os) const
{
	int i;
	int lim = scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores[i] << " ";
			if (i % 5 == 4)
				os << std::endl;
		}
		if (i % 5 != 0)
			os << std::endl;
	}
	else
		os << " empty array ";
	return os;
}
//-------------------------------------------------------------------------------------------------
// Друзья 
// Использует версию operator»() из класса string 
std::istream & operator>>(std::istream & is, Student & stu)
{
	is >> stu.name;
	return is;
}
//-------------------------------------------------------------------------------------------------
// Использует версию getline(ostream &, const string &) из класса string 
std::istream & getline(std::istream & is, Student & stu)
{
	getline(is, stu.name);
	return is;
}
//-------------------------------------------------------------------------------------------------
// Использует версию operator<<() из класса string 
std::ostream & operator<<(std::ostream & os, const Student & stu)
{
	os << "Scores for " << stu.name << " :\n";
	stu.arr_out(os); // использование закрытого метода для scores 
	return os;
}
//-------------------------------------------------------------------------------------------------