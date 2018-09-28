//calling.срр -- определение, прототипирование и вызов функции 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------------------------
void simple(); // прототип функции 
//------------------------------------------------------------------------------------------------
int main() 
{
	cout << "main () will call the simple () function: \n";
	simple(); // вызов функции 
	cout << "main() is finished with the simple () function.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
void simple()
{
	cout << "I'm but a simple function. \n";
}
//------------------------------------------------------------------------------------------------
/*
main () will call the simple () function:
I'm but a simple function.
main() is finished with the simple () function.
*/