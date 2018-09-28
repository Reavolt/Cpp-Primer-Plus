//strctfun.cpp -- функции с аргументами-структурами 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------------------------
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
//------------------------------------------------------------------------------------------------
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
	while (cin >> rplace.x >> rplace.y) // ловкое использование сіп 
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers (q to quit) : ";
		// Ввод следующих двух чисел (q для завершения) 
	}
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
// Преобразование прямоугольных координат в полярные 
polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;
	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer; // возврат структуры polar 
}
//------------------------------------------------------------------------------------------------
// Отображение полярных координат с преобразованием радиан в градусы 
void show_polar(polar dapos)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;
	cout << "distance = " << dapos.distance;
	cout << ", angle = " << dapos.angle * Rad_to_deg;
	cout << " degrees\n";
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