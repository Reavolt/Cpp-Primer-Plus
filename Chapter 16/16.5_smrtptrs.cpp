//smrtptrs.cpp — использование трех видов интеллектуальных указателей 
//требуется поддержка shared_ptr и unique_ptr из С++11 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include <memory>

//-------------------------------------------------------------------------------------------------
class Report
{
private:
	std::string str;
public:
	Report(const std::string s) : str(s) { std::cout << "Object created!\n"; }
	~Report() { std::cout << "Object deleted!\n"; }
	void comment() const { std::cout << str << "\n"; }
};
//-------------------------------------------------------------------------------------------------
int main()
{
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment();  // использование операции -> для вызова функции-члена 
	}
	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Object created!
using auto_ptr
Object deleted!
Object created!
using shared_ptr
Object deleted!
Object created!
using unique_ptr
Object deleted!
*/