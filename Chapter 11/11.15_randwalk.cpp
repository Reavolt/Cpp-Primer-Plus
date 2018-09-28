// randwalk.срр — использование класса Vector 
// Компилировать вместе с файлом vect.cpp 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstdlib> // прототипы rand(), srand() 
#include <ctime> // прототип time() 
#include "11.13_vect.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0)); // начальное значение для генератора случайных чисел 
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit) : ";
	// Ввод заданного расстояния (q для завершения) 
	while (cin >> target)
	{
		cout << "Enter step length: "; // ввод длины шага 
		if (!(cin >> dstep))
			break;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
		"has the following location:\n";
		cout << result << endl; // вывод позиции после steps шагов 
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			 << result.magval() / steps << endl; // вывод среднего расстояния на один шаг 
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
		// Ввод заданного расстояния (q для завершения) 
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != ' \n ')
		continue;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter target distance (q to quit) : 50
Enter step length: 2
After 228 steps, the subject has the following location:
(x,y) = (29.1429, -41.4273)
or
(m,a) = (50.651, -54.8747 )
Average outward distance per step = 0.222154
Enter target distance (q to quit): 50
Enter step length: 2
After 396 steps, the subject has the following location:
(x,y) = (-16.239, -47.5934)
or
(m,a) = (50.2875, -108.84 )
Average outward distance per step = 0.126989
Enter target distance (q to quit): 50
Enter step length: 1
After 3973 steps, the subject has the following location:
(x,y) = (20.5092, -45.9696)
or
(m,a) = (50.3371, -65.9561 )
Average outward distance per step = 0.0126698
Enter target distance (q to quit): q
Bye!
*/