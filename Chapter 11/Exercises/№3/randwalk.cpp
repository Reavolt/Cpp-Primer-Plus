//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <cstdlib> 		// прототипы rand(), srand() 
#include <ctime> 		// прототип time() 
#include <vector>
#include <algorithm>    // min_element(), max_element()
#include <numeric>      // accumulate()
#include "vect.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using VECTOR::Vector;
	
	std::srand(std::time(0)); // начальное значение для генератора случайных чисел
	
	std::vector <unsigned long> stepsResult;

	std::cout << "Enter number of attempts: ";
	int attempt = 0;
	std::cin >> attempt;

	double direction = 0.0;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned int steps = 0;
	double target = 0.0;
	double dstep = 0.0;
	
	while (attempt)
	{

		std::cout << "Enter target distance: ";
		std::cin >> target;

		std::cout << "Enter step length: ";
		if (!(std::cin >> dstep))
		{
			break;
		}
		
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, VECTOR::Vector::POL);
			result = result + step;
			steps++;
		}
		stepsResult.push_back(steps);
		result.reset(0, 0);
		--attempt;
	}

	std::cout << "The smallest number of steps is ";
	std::cout << *std::min_element(stepsResult.begin(), stepsResult.end());
	std::cout<< '\n';
	
	std::cout << "The average number of steps is ";
	std::cout << std::accumulate(stepsResult.begin(), stepsResult.end(), 0) / stepsResult.size();
	std::cout << '\n';
	
	std::cout << "The largest number of steps is ";
	std::cout << *std::max_element(stepsResult.begin(), stepsResult.end());
	std::cout<< '\n';
	
	std::cout << "Bye!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------