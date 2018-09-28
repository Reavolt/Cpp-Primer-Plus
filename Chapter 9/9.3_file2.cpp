//file2.cpp -- содержит функции, вызываемые в file1.срр 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream> 
#include <cmath> 
#include "coordin.h" // шаблоны структур, прототипы функций 

//-------------------------------------------------------------------------------------------------
// преобразование прямоугольных координат в полярные 
polar rect_to_polar(rect xypos)
{
	polar answer;
	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer; // возврат структуры polar 
}
//-------------------------------------------------------------------------------------------------
// отображение полярных координат с преобразованием радиан в градусы 
void show_polar(polar dapos)
{
	const double Rad_to_deg = 57.29577951;
	std::cout << "distance = " << dapos.distance;
	std::cout << ", angle = " << dapos.angle * Rad_to_deg;
	std::cout << " degrees\n";
}
//-------------------------------------------------------------------------------------------------