//strctptr.cpp -- функции с аргументами-указателями на структуры 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------------------------
void rect_to_polar(const rect * pxy, polar * pda);
void show_polar(const polar * pda);
//------------------------------------------------------------------------------------------------
// Объявления структур 
struct polar
{
	double distance; // расстояние от исходной точки 
	double angle; // направление от исходной точки 
};
//------------------------------------------------------------------------------------------------
struct rect
{
	double x; // расстояние по горизонтали от исходной точки 
	double y; // расстояние по вертикали от исходной точки 
};
//------------------------------------------------------------------------------------------------
int main()
{
	rect rplace;
	polar pplace;
	cout << "Enter the x and y values: "; // ввод значений х и у 
	while (cin >> rplace.x >> rplace.y)
	{
		rect_to_polar(&rplace, &pplace);  // передача адресов 
		show_polar(&pplace);			  // передача адресов 
		cout << "Next two numbers (q to quit) : ";
		// Ввод следующих двух чисел (q для завершения) 
	}
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
// Отображение полярных координат с преобразованием радиан в градусы 
void show_polar(const polar * pda)
{
	const double Rad_to_deg = 57.29577951;
	cout << "distance = " << pda->distance;
	cout << ", angle = " << pda->angle * Rad_to_deg;
	cout << " degrees\n";
}
//------------------------------------------------------------------------------------------------
// Преобразование прямоугольных координат в полярные 
void rect_to_polar(const rect * pxy, polar * pda)
{
	pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}
//------------------------------------------------------------------------------------------------
/*
Enter the x and y values: 30 40
distance = 50, angle = 53.1301 degrees
Next two numbers (q to quit) : -100 100
distance = 141.421, angle = 135 degrees
Next two numbers (q to quit) : q
Done.
*/