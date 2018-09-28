//arrfun4.срр -- функция с диапазоном массива 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

const int ArSize = 8;
//------------------------------------------------------------------------------------------------
int sum_arr(const int* begin, const int* end);
//------------------------------------------------------------------------------------------------
int main() 
{
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	// Некоторые системы требуют предварить int словом static, 
	// чтобы разрешить инициализацию массива 
	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "Total cookies eaten: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3); // три первых элемента 
	cout << "First three eaters ate " << sum << " cookies. \n";
	sum = sum_arr(cookies + 4, cookies + 8); // четыре последних элемента 
	cout << "Last four eaters ate " << sum << " cookies. \n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
// Возвращает сумму элементов целочисленного массива 
int sum_arr(const int * begin, const int * end)
{
	const int * pt;
	int total = 0;
	for (pt = begin; pt != end; pt++)
		 total = total + *pt;
	return total;
}
//------------------------------------------------------------------------------------------------
/*
Total cookies eaten: 255
First three eaters ate 7 cookies.
Last four eaters ate 240 cookies.
*/