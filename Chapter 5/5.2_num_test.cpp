//num_test.cpp -- использование числовой проверки в цикле 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	cout << "Enter the starting countdown value: "; // ввод начального значения счетчика 
	int limit = 0;
	cin >> limit;
	int i;
	for (i = limit; i; i--) // завершается, когда і равно О- 
	cout << "i = " << i << "\n";
	cout << "Done now that i = " << i << "\n"; // цикл завершен, вывод значения і 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter the starting countdown value: 5
i = 5
i = 4
i = 3
i = 2
i = 1
Done now that i = 0
*/