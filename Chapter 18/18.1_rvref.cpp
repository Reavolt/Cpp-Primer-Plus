//rvref.срр — простое использование ссылок rvalue 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//--------------------------------------------------------------------------------------------------
inline double f(double tf) { return 5.0*(tf - 32.0) / 9.0; };
//--------------------------------------------------------------------------------------------------
int main()
{
	double tc = 21.5;
	double && rdl = 7.07;
	double && rd2 = 1.8 * tc + 32.0;
	double && rd3 = f(rd2);

	// Вывод значений и адресов tc, rdl, rd2 и rd3 
	std::cout << " tc value and address: " << tc << ", " << &tc << std::endl;
	std::cout << "rdl value and address: " << rdl << ", " << &rdl << std::endl;
	std::cout << "rd2 value and address: " << rd2 << ", " << &rd2 << std::endl;
	std::cout << "rd3 value and address: " << rd3 << ", " << &rd3 << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------
/*
tc value and address: 21.5, 012FF7EC
rdl value and address: 7.07, 012FF7D0
rd2 value and address: 70.7, 012FF7B4
rd3 value and address: 21.5, 012FF798
*/