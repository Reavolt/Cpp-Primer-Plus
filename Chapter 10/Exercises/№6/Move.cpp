//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "Move_class.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	Move test_1(5, 10);
	test_1.show_move();

	test_1.add(test_1);
	test_1.show_move();

	test_1.reset();
	test_1.show_move();

	test_1.reset(10.0, 20.0);
	test_1.show_move();

	Move test_2(25.0, 25.0);
	test_2.show_move();

	test_2.add(test_1);
	test_2.show_move();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------