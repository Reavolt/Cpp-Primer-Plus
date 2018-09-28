//setf2.cpp — использование setf () с двумя аргументами для управления 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	// Использовать выравнивание влево, показать знак плюс, 
	// показать завершающие нули с точностью, равной 3 
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3);
	// Использовать экспоненциальную запись и сохранить старые установки формата 
	ios_base::fmtflags old = cout.setf(ios_base::scientific,
		ios_base::floatfield);
	cout << "Left Justification:\n";
	long n;
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	// Переключиться на внутреннее выравнивание 
	cout.setf(ios_base::internal, ios_base::adjustfield);
	// Восстановить стиль отображения значений с плавающей точкой, заданный по умолчанию 
	cout.setf(old, ios_base::floatfield);

	cout << "Internal Justification:\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	// Использовать выравнивание по правому краю и форму записи с фиксированной точкой 
	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Right Justification:\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Left Justification:
+1  |+1.000e+00  |
+11 |+3.317e+00  |
+21 |+4.583e+00  |
+31 |+5.568e+00  |
+41 |+6.403e+00  |
Internal Justification:
+  1|+       1.00|
+ 11|+       3.32|
+ 21|+       4.58|
+ 31|+       5.57|
+ 41|+       6.40|
Right Justification:
+1|      +1.000|
+11|      +3.317|
+21|      +4.583|
+31|      +5.568|
+41|      +6.403|
*/