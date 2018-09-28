//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <cmath> // или math.h, пользователям UNIX может потребоваться флаг -lm 
#include <iostream>
#include <stdexcept>
#include <typeinfo> // for typeid()

//-------------------------------------------------------------------------------------------------
// Прототипы функций 
double hmean(double a, double b) throw (std::logic_error);
double gmean(double a, double b) throw (std::logic_error);
//-------------------------------------------------------------------------------------------------
class bad_hmean : public std::invalid_argument
{
private:
	int arg1;
	int arg2;
public:
	bad_hmean(int a, int b, const std::string & s = "")
		: std::invalid_argument(s), arg1(a), arg2(b) {}
	void display() const;
};
//-------------------------------------------------------------------------------------------------
void bad_hmean::display() const
{
	std::cout << "For function hmean(): " << std::endl;
	std::cout << "Invalid arguments: \"a\" and \"b\" must be equal." << std::endl;
	std::cout << "You entered a = " << arg1 << ", b = " << arg2 << std::endl;
}
//-------------------------------------------------------------------------------------------------
class bad_gmean : std::domain_error
{
private:
	int arg1;
	int arg2;
public:
	bad_gmean(int a, int b, const std::string & s = "")
		: std::domain_error(s), arg1(a), arg2(b) {}
	void display() const;
};
//-------------------------------------------------------------------------------------------------
void bad_gmean::display() const
{
	std::cout << "For function gmean(): " << std::endl;
	std::cout << "Invalid arguments: \"a\" and \"b\" ";
	std::cout << "must be nonnegative." << std::endl;
	std::cout << "You entered a = " << arg1 << ", b = " << arg2 << std::endl;
}
//-------------------------------------------------------------------------------------------------
int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";	// запрос на ввод двух чисел 
	while (std::cin >> x >> y)
	{
		try 
		{// начало блока try 
			z = hmean(x, y);
			std::cout << "Harmonic mean of " << x << " and " << y;
			std::cout << " is " << z << std::endl;					// вывод среднего гармонического 
			std::cout << "Geometric mean of " << x << " and " << y;
			std::cout << " is " << gmean(x, y) << std::endl;		// вывод среднего геометрического 
			std::cout << "Enter next set of numbers <q to quit>: ";	// ввод следующей пары чисел ' 
		}// конец блока try 
		catch (std::exception & e)
		{// начало блока catch 
			if (typeid(bad_hmean &) == typeid(e))
			{
				bad_hmean & bhm = dynamic_cast<bad_hmean &>(e);
				bhm.display();
			}
			else 
			if(typeid(bad_gmean &) == typeid(e))
			{
				bad_gmean & bgm = dynamic_cast<bad_gmean &>(e);
				bgm.display();
			}
			std::cout << "Sorry, you don't get to play any more.\n";
			break;
		} // конец блока catch 
	}
	std::cout << "Bye!\n";

	std::cin.get();
	std::cin.get();	
	return 0;
}
//-------------------------------------------------------------------------------------------------
double hmean(double a, double b) throw(std::logic_error)
{
	if (a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}
//-------------------------------------------------------------------------------------------------
double gmean(double a, double b) throw(std::logic_error)
{
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	}
	return std::sqrt(a * b);
}
//-------------------------------------------------------------------------------------------------