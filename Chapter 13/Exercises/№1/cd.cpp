//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "cd.h"

//-------------------------------------------------------------------------------------------------
Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0;
}
//-------------------------------------------------------------------------------------------------
Cd::Cd(const char* perf, const char* leb, int sel, double playt)
{
	strncpy(performers, perf, 50 - 1);
	performers[50 - 1] = '\0';
	strncpy(label, leb, 20 - 1);
	label[20 - 1] = '\0';

	if (sel < 0)
	{
		std::cout << "Selections must be a positive integer. ";
		std::cout << "Setting selections to 0." << std::endl;
		selections = 0;
	}
	else
	{
		selections = sel;
	}

	if (playt < 0)
	{
		std::cout << "Play time must be a positive real number. ";
		std::cout << "Setting play time to 0." << std::endl;
		playtime = 0;
	}
	else
	{
		playtime = playt;
	}
}
//-------------------------------------------------------------------------------------------------
Cd::Cd(const Cd & d)
{
	strncpy(performers, d.performers, 50 - 1);
	performers[50 - 1] = '\0';
	strncpy(label, d.label, 20 - 1);
	label[20 - 1] = '\0';
	selections = d.selections;
	playtime = d.playtime;
}
//-------------------------------------------------------------------------------------------------
Cd::~Cd()
{

}
//-------------------------------------------------------------------------------------------------
Cd & Cd::operator = (const Cd & d)
{
	strncpy(performers, d.performers, 50 - 1);
	performers[50 - 1] = '\0';
	strncpy(label, d.label, 20 - 1);
	label[20 - 1] = '\0';
	selections = d.selections;
	playtime = d.playtime;
	
	return *this;
}
//-------------------------------------------------------------------------------------------------
void Cd::Report() const
{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Play time: " << playtime << std::endl;
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------
Classic::Classic()
{
	cdname[0] = '\0';
}
//-------------------------------------------------------------------------------------------------
Classic::Classic(const char* name, Cd & cd) : Cd(cd)
{
	strncpy(cdname, name, 40 - 1);
	cdname[40 - 1] = '\0';
}
//-------------------------------------------------------------------------------------------------
Classic::Classic(const char* name, const char* perf, const char* leb, int sel, double playt) \
		: Cd(perf, leb, sel, playt)
{
	strncpy(cdname, name, 40 - 1);
	cdname[40 - 1] = '\0';
}
//-------------------------------------------------------------------------------------------------
Classic::Classic(const Classic & c) : Cd(c)
{
	strncpy(cdname, c.cdname, 40 - 1);
	cdname[40 - 1] = '\0';
}
//-------------------------------------------------------------------------------------------------
Classic::~Classic()
{

}
//-------------------------------------------------------------------------------------------------
void Classic::Report() const
{
	Cd::Report();
	std::cout << "Primary Work: " << cdname << std::endl;
}
//-------------------------------------------------------------------------------------------------
Classic & Classic::operator = (const Classic & c)
{
	Cd::operator=(c);
	strncpy(cdname, c.cdname, 40 - 1);
	cdname[40 - 1] = '\0';
	
	return *this;
}
//-------------------------------------------------------------------------------------------------