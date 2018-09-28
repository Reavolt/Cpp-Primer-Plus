//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

const int SLEN = 30;
//-------------------------------------------------------------------------------------------------
struct student 
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
//-------------------------------------------------------------------------------------------------
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);
//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter class size: ";
	int class_size = 0;
	std::cin >> class_size;

	while (std::cin.get() != '\n')
	{
		continue;
	}

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);

	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);

	delete[] ptr_stu;
	std::cout << "Done\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
int getinfo(student pa[], int class_size)
{
	int enteredCount = 0;

	for (size_t i = 0; i < class_size; i++) 
	{
		std::cout << "№ " << i + 1 << std::endl;
		std::cout << "Enter name: ";

		std::cin.getline(pa[i].fullname, SLEN);
	
		if (strlen(pa[i].fullname) != 0)
		{
			std::cout << "Enter hobby: ";
			std::cin.getline(pa[i].hobby, SLEN);

			std::cout << "Enter ooplevel: ";
			(std::cin >> pa[i].ooplevel).get();
		}
		else 
		{
			break;
		}
		++enteredCount;
		std::cout << std::endl;
	}
	return enteredCount;
}
//-------------------------------------------------------------------------------------------------
void display1(student st)
{
	std::cout << "Name: ";
	std::cout << st.fullname << std::endl;
	std::cout << "Hobby: ";
	std::cout << st.hobby << std::endl;
	std::cout << "Ooplevel: ";
	std::cout << st.ooplevel << std::endl;
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------
void display2(const student* ps)
{
	std::cout << "Name: ";
	std::cout << ps->fullname << std::endl;
	std::cout << "Hobby: ";
	std::cout << ps->hobby << std::endl;
	std::cout << "Ooplevel: ";
	std::cout << ps->ooplevel << std::endl;
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------
void display3(const student pa[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Name: ";
		std::cout << pa[i].fullname << std::endl;
		std::cout << "Hobby: ";
		std::cout << pa[i].hobby << std::endl;
		std::cout << "Ooplevel: ";
		std::cout << pa[i].ooplevel << std::endl;
		std::cout << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------