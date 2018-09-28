//constcast.cpp -- использование const_cast<> 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using std::cout;
using std::endl;

//-------------------------------------------------------------------------------------------------
void change(const int * pt, int n);
//-------------------------------------------------------------------------------------------------
int main()
{
	int pop1 = 38383;
	const int pop2 = 2000;

	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void change(const int * pt, int n)
{
	int * pc;

	pc = const_cast<int *>(pt);
	*pc += n;

}
//-------------------------------------------------------------------------------------------------
/*
pop1, pop2: 38383, 2000
pop1, pop2: 38280, 2000
Для продолжения нажмите любую клавишу . . .
*/