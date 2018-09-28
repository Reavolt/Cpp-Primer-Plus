//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "cd.h"

//-------------------------------------------------------------------------------------------------
Cd::Cd()
{
	performers = nullptr;
	label = nullptr;
	selections = 0;
	playtime = 0;
}
//-------------------------------------------------------------------------------------------------
Cd::Cd(const char* perf, const char* leb, int sel, double playt)
{
	if (perf == nullptr)
	{
		performers = nullptr;
	}
	else
	{
		performers = new char[strlen(perf) + 1];
		strcpy(performers, perf);
	}

	if (leb == nullptr)
	{
		label = nullptr;
	}
	else
	{
		label = new char[strlen(leb) + 1];
		strcpy(label, leb);
	}

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
	if (d.performers == nullptr)
	{
		performers = nullptr;
	}
	else
	{
		performers = new char[strlen(d.performers) + 1];
		strcpy(performers, d.performers);
	}

	if (d.label == nullptr)
	{
		label = nullptr;
	}
	else
	{
		label = new char[strlen(d.label) + 1];
		strcpy(label, d.label);
	}
	selections = d.selections;
	playtime = d.playtime;
}
//-------------------------------------------------------------------------------------------------
Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}
//-------------------------------------------------------------------------------------------------
Cd & Cd::operator = (const Cd & d)
{
	if (this == &d)
	{
		return *this;
	}
	else
	{
		delete[] performers;
		delete[] performers;

		if (d.performers == nullptr)
		{
			performers = nullptr;
		}
		else
		{
			performers = new char[strlen(d.performers) + 1];
			strcpy(performers, d.performers);
		}

		if (d.label == nullptr)
		{
			label = nullptr;
		}
		else
		{
			label = new char[strlen(d.label) + 1];
			strcpy(label, d.label);
		}
	}

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
}
//-------------------------------------------------------------------------------------------------
Classic::Classic()
{
	cdname = nullptr;
}
//-------------------------------------------------------------------------------------------------
Classic::Classic(const char* name, Cd & cd) : Cd(cd)
{
	if (name == nullptr)
	{
		cdname = nullptr;
	}
	else
	{
		cdname = new char[strlen(name) + 1];
		strcpy(cdname, name);
	}
}
//-------------------------------------------------------------------------------------------------
Classic::Classic(const char* name, const char* perf, const char* leb, int sel, double playt) 
		: Cd(perf, leb, sel, playt)
{
	if (name == nullptr)
	{
		cdname = nullptr;
	}
	else
	{
		cdname = new char[strlen(name) + 1];
		strcpy(cdname, name);
	}
}
//-------------------------------------------------------------------------------------------------
Classic::Classic(const Classic & c) : Cd(c)
{
	if (c.cdname == nullptr)
	{
		cdname = nullptr;
	}
	else
	{
		cdname = new char[strlen(c.cdname) + 1];
		strcpy(cdname, c.cdname);
	}
}
//-------------------------------------------------------------------------------------------------
Classic::~Classic()
{
	delete[] cdname;
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
	if (this == &c)
	{
		return *this;
	}
	else
	{
		Cd::operator=(c);
		delete[] cdname;

		if (c.cdname == nullptr)
		{
			cdname = nullptr;
		}
		else
		{
			cdname = new char[strlen(c.cdname) + 1];
			strcpy(cdname, c.cdname);
		}
	}
	return *this;
}
//-------------------------------------------------------------------------------------------------