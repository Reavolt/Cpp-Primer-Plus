// usetimeO.срр -- использование первой черновой версии класса Time 
// компилировать usetime0.срр и mytime0.cpp вместе 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "mytime0.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;
	cout << "planning time = "; // время на планирование 
	planning.Show();
	cout << endl;
	cout << "coding time = "; // время на кодирование 
	coding.Show();
	cout << endl;
	cout << "fixing time = "; // время на исправление 
	fixing.Show();
	cout << endl;
	total = coding.Sum(fixing);
	cout << "coding.Sum (fixing) = ";
	total.Show();
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
planning time = 0 hours, 0 minutes
coding time = 2 hours, 40 minutes
fixing time = 5 hours, 55 minutes
coding.Sum (fixing) = 8 hours, 35 minutes
Для продолжения нажмите любую клавишу . . .
*/