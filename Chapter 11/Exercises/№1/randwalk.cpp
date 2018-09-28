//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <cstdlib> 	// прототипы rand(), srand() 
#include <ctime> 	// прототип time() 
#include <fstream>
#include "vect.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using VECTOR::Vector;
	
	std::srand(std::time(0)); // начальное значение для генератора случайных чисел 

	std::ofstream fout;
	fout.open("Vector.txt");

	std::cout << "Enter target distance (q to quit) : ";
	double target = 0.0;
	(std::cin >> target).get();
	
	fout << "Target distance : ";
	fout << target << ",";
	// Ввод заданного расстояния (q для завершения) 

	std::cout << "Enter step length: "; // ввод длины шага 
	double dstep = 0.0;
	(std::cin >> dstep).get();

	fout << " Step length: "; // ввод длины шага 
	fout << dstep << std::endl;

	double direction = 0.0;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned int steps = 0;
	
	while (target)
	{
		if (!dstep)
		{
			break;
		}
		
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;

			fout << steps << ": " << result << std::endl; 		// вывод позиции после step
			std::cout << steps << ": " << result << std::endl;  // вывод позиции после steps шагов 
		}

		std::cout << "After " << steps << " steps, the subject ";
		std::cout << "has the following location:\n";
		
		std::cout << result << std::endl; 						// вывод позиции после steps шагов 
		result.polar_mode();
		
		std::cout << " or\n" << result << std::endl;
		std::cout << "Average outward distance per step = ";
		std::cout << result.magval() / steps << std::endl;		// вывод среднего расстояния на один шаг 

		fout << "After " << steps << " steps, the subject ";
		fout << "has the following location:\n";
		fout << result << std::endl; 							// вывод позиции после steps шагов 
		result.polar_mode();
		fout << " or\n" << result << std::endl;
		fout << "Average outward distance per step = ";
		fout << result.magval() / steps << std::endl; 			// вывод среднего расстояния на один шаг 
		break;
	}
	fout.close();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------