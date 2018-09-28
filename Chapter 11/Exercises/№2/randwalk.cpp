//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <cstdlib>  // прототипы rand(), srand() 
#include <ctime> 	// прототип time() 
#include "vect.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using VECTOR::Vector;
	
	std::srand(std::time(0)); // начальное значение для генератора случайных чисел 

	std::cout << "Enter target distance (q to quit): ";
	// Ввод заданного расстояния (q для завершения) 
	
	double direction = 0.0;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned int steps = 0;
	
	double target = 0.0;
	double dstep = 0.0;

	while (std::cin >> target)
	{
		std::cout << "Enter step length: ";
		if (!(std::cin >> dstep))
		{
			break;
		}
		
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		
		std::cout << "After " << steps << " steps, the subject ";
		std::cout << "has the following location:\n";
		std::cout << result << std::endl; // вывод позиции после steps шагов 
		
		result.polar_mode();
		
		std::cout << " or\n" << result << std::endl;
		std::cout << "Average outward distance per step = ";
		std::cout << result.magval() / steps << std::endl; // вывод среднего расстояния на один шаг 
		
		steps = 0;
		result.reset(0.0, 0.0);
		
		std::cout << "Enter target distance (q to quit): ";
		// Ввод заданного расстояния (q для завершения) 
	}
	std::cout << "Bye!\n";
	std::cin.clear();
	
	while (std::cin.get() != ' \n ')
	{
		continue;
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------