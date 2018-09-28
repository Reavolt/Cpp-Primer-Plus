//sqrt.cpp -- использование функции sqrt() 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	double area;
	cout << "Enter the floor area, in square feet, of your hone: ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "Thet s the equivalent of a square " << side
		 << " feet to the side." << endl;
	cout << "How fascinating!" << endl;
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter the floor area, in square feet, of your hone: 1536
Thet s the equivalent of a square 39.1918 feet to the side.
How fascinating!
*/
