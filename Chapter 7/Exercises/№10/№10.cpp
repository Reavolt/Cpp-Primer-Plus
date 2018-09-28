//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
double Multiplication(double x, double y);
double Division(double x, double y);
double Subtraction(double x, double y);
double Addition(double x, double y);
double Calculate(double x, double y, double(*pt)(double x, double y), int menu);
void print_menu();
//-------------------------------------------------------------------------------------------------
int main()
{
	print_menu();

	int menu = 0;
	while (std::cin >> menu)
	{
		switch (menu)
		{
		case 1: {
			std::cout << "Multiplication: Enter x and y -> ";
			double x = 0, y = 0, result = 0;
			std::cin >> x >> y;
			result = Calculate(x, y, Multiplication, menu);
			std::cout << x << " * " << y << " = " << result << std::endl;
			break;
		}
		case 2: {
			std::cout << "Division: Enter x and y -> ";
			double x = 0, y = 0, result = 0;
			std::cin >> x >> y;
			result = Calculate(x, y, Division, menu);
			std::cout << x << " / " << y << " = " << result << std::endl;
			break;
		}
		case 3: {
			std::cout << "Subtraction: Enter x and y -> ";
			double x = 0, y = 0, result = 0;
			std::cin >> x >> y;
			result = Calculate(x, y, Subtraction, menu);
			std::cout << x << " - " << y << " = " << result << std::endl;
			break;
		}
		case 4: {
			std::cout << "Addition: Enter x and y -> ";
			double x = 0, y = 0, result = 0;
			std::cin >> x >> y;
			result = Calculate(x, y, Addition, menu);
			std::cout << x << " + " << y << " = " << result << std::endl;
			break;
		}
		default:
			std::cout << "Invalid input" << std::endl;
			break;
		}
		print_menu();
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
double Multiplication(double x, double y)
{
	return x * y;
}
//-------------------------------------------------------------------------------------------------
double Division(double x, double y)
{
	return x / y;
}
//-------------------------------------------------------------------------------------------------
double Subtraction(double x, double y)
{
	return x - y;
}
//-------------------------------------------------------------------------------------------------
double Addition(double x, double y)
{
	return x + y;
}
//-------------------------------------------------------------------------------------------------
double Calculate(double x, double y, double(*pt)(double x, double y), int menu)
{
	double result = 0;
	switch (menu)
	{
	case 1:
		result = Multiplication(x, y);
		break;
	case 2:
		result = Division(x, y);
		break;
	case 3:
		result = Subtraction(x, y);
		break;
	case 4:
		result = Addition(x, y);
		break;
	}
	return result;
}
//-------------------------------------------------------------------------------------------------
void print_menu() 
{
	std::cout << "Choose the action of the calculator: " << std::endl;
	std::cout << "[1] - Multiplication: " << std::endl;
	std::cout << "[2] - Division: " << std::endl;
	std::cout << "[3] - Subtraction: " << std::endl;
	std::cout << "[4] - Addition: " << std::endl;
	std::cout << "[Q/q] - Exit: " << std::endl;
}
//-------------------------------------------------------------------------------------------------