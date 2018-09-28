//studenti.срр — класс Student, использующий закрытое наследование 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring> 
#include "14.4_studenti.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

//-------------------------------------------------------------------------------------------------
// Открытые методы 
double Student::Average() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}
//-------------------------------------------------------------------------------------------------
const string & Student::Name() const
{
	return (const string &)*this;
}
//-------------------------------------------------------------------------------------------------
double & Student::operator[](int i)
{
	return ArrayDb::operator[](i); // использование ArrayDb::operator[] () 
}
//-------------------------------------------------------------------------------------------------
double Student::operator[] (int i) const
{
	return ArrayDb::operator[] (i);
}
//-------------------------------------------------------------------------------------------------
// Закрытый метод 
ostream & Student::arr_out(ostream & os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << " empty array ";
	return os;
}
//-------------------------------------------------------------------------------------------------
// Друзья 
// Использует версию operator>>() из класса string 
istream & operator >> (istream & is, Student & stu)
{
	is >> (string &)stu;
	return is;
}
//-------------------------------------------------------------------------------------------------
// Использует друга string - getline(ostream &, const string &) 
istream & getline(istream & is, Student & stu)
{
	getline(is, (string &)stu);
	return is;
}
//-------------------------------------------------------------------------------------------------
// Использует версию operator«() из класса string 
ostream & operator << (ostream & os, const Student & stu)
{
	os << "Scores for " << (const string &) stu << " :\n";
	stu.arr_out(os); // использование закрытого метода для scores 
	return os;
}
//-------------------------------------------------------------------------------------------------