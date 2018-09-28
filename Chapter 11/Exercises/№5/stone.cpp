//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "stonewt.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	Stonewt var_a;
	std::cout << "Object var_a constructed by default constructor: " << var_a << std::endl;

	Stonewt var_b(62.52);
	std::cout << "Object var_b constructed from double value: " << var_b << std::endl;

	Stonewt var_c(10, 60.21);
	std::cout << "Object var_c constructed from stone, double values: " << var_c << std::endl;

	var_c.setmode(0);
	std::cout << "Object var_c (Mode set to STONE): " << var_c << std::endl;

	var_c.setmode(1);
	std::cout << "Object var_c (Mode set to iPOUND): " << var_c << std::endl;

	var_c.setmode(2);
	std::cout << "Object var_c (Mode set to dPOUND): " << var_c << std::endl;

	std::cout << "Object var_c (Mode set to incorrect value):\n";
	var_c.setmode(6);
	std::cout << "Object var_c after that: " << var_c << std::endl;

	Stonewt var_d = var_b + var_c;
	std::cout << "\nObject var_d after adding: " << var_d << std::endl;

	var_d.setmode(0);
	std::cout << "Object var_d (Mode set to STONE): " << var_d << std::endl;

	var_d.setmode(1);
	std::cout << "Object var_d (Mode set to iPOUND): " << var_d << std::endl;

	var_d.setmode(2);
	std::cout << "Object var_d (Mode set to dPOUND): " << var_d << std::endl;

	var_d = var_c - var_b;
	std::cout << "\nObject var_d after division: " << var_d << std::endl;

	var_d.setmode(0);
	std::cout << "Object var_d (Mode set to STONE): " << var_d << std::endl;

	var_d.setmode(1);
	std::cout << "Object var_d (Mode set to iPOUND): " << var_d << std::endl;

	var_d.setmode(2);
	std::cout << "Object var_d (Mode set to dPOUND): " << var_d << std::endl;

	var_d = var_c * var_b;
	std::cout << "\nObject var_d after multiplying: " << var_d << std::endl;

	var_d.setmode(0);
	std::cout << "Object var_d (Mode set to STONE): " << var_d << std::endl;

	var_d.setmode(1);
	std::cout << "Object var_d (Mode set to iPOUND): " << var_d << std::endl;

	var_d.setmode(2);
	std::cout << "Object var_d (Mode set to dPOUND): " << var_d << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------