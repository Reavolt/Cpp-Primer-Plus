// stonel.срр — определяемые пользователем функции преобразования 
// компилировать вместе с stonewtl.cpp 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "11.19_stonewt1.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	Stonewt poppins(9, 2.8); // 9 стоунов, 2.8 фунта 
	double p_wt = poppins; // неявное преобразование 
	cout << "Convert to double => ";
	cout << "Poppins: " << p_wt << " pounds. \n";
	cout << "Convert to int => ";
	cout << "Poppins: " << int(poppins) << " pounds. \n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Convert to double => Poppins: 128.8 pounds.
Convert to int => Poppins: 129 pounds.
Для продолжения нажмите любую клавишу . . .
*/