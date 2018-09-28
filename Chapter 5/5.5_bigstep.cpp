//bigstep.срр -- цикл указанным пользователем шагом 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main() 
{
	using std::cout; // объявление using 
	using std::cin;
	using std::endl;

	cout << "Enter an integer: "; // ввод целого числа 
	int by;
	cin >> by;
	cout << "Counting by " << by << "s:\n";
	for (int i = 0; i < 100; i = i + by)
		 cout << i << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter an integer: 17
Counting by 17s:
0
17
34
51
68
85
*/