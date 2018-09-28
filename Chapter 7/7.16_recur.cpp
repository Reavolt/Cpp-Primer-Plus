//recur.срр -- использование рекурсии 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <array> 
#include <string> 

using namespace std;
//------------------------------------------------------------------------------------------------
void countdown(int n);
//------------------------------------------------------------------------------------------------
int main()
{
	countdown(4); // вызов рекурсивной функции 

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
void countdown(int n)
{
	using namespace std;
	cout << "Counting down ... " << n << endl;
	if (n > 0)
		countdown(n - 1); // функция вызывает сама себя 
	cout << n << " : Kaboom!\n";
}
//------------------------------------------------------------------------------------------------
/*
Counting down ... 4
Counting down ... 3
Counting down ... 2
Counting down ... 1
Counting down ... 0
0 : Kaboom!
1 : Kaboom!
2 : Kaboom!
3 : Kaboom!
4 : Kaboom!
*/