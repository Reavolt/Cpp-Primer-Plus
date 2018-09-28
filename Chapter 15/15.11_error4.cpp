//error4.cpp — использование классов исключений 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <cmath> // или math.h, пользователям UNIX может потребоваться флаг -lm 
#include <iostream>
#include "15.10_exc_mean.h" 

//-------------------------------------------------------------------------------------------------
// Прототипы функций 
double hmean(double a, double b);
double gmean(double a, double b);
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Enter two numbers: ";	// запрос на ввод двух чисел 
	while (cin >> x >> y)
	{
		try {                 // начало блока try 
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;	// вывод среднего гармонического 
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x, y) << endl;	// вывод среднего геометрического 
			cout << "Enter next set of numbers <q to quit>: ";	// ввод следующей пары чисел ' 
		}// конец блока try 
		catch (bad_hmean & bg)   // начало блока catch 
		{
			bg.mesg();
			cout << "Try again.\n";	// необходимо повторить попытку 
			continue;
		}
		catch (bad_gmean & hg)
		{
			cout << hg.mesg();
			cout << "Values used: " << hg.v1 << ", "
				<< hg.v2 << endl;			// используемые знарчения 
			cout << "Sorry, you don't get to play any more.\n";	// завершение работы 
			break;
		} // конец блока catch 
	}
	cout << "Bye!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}
//-------------------------------------------------------------------------------------------------
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}
//-------------------------------------------------------------------------------------------------
/*
Enter two numbers: 4 12
Harmonic mean of 4 and 12 is 6
Geometric mean of 4 and 12 is 6.9282
Enter next set of numbers <q to quit>: 5 -5
hmean(5, -5): invalid arguments: a = -b
Try again.
5 -2
Harmonic mean of 5 and -2 is -6.66667
gmean() arguments should be >= 0
Values used: 5, -2
Sorry, you don't get to play any more.
Bye!
Для продолжения нажмите любую клавишу . . .
*/