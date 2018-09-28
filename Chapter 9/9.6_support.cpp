//support.срр -- использование внешних переменных
//Компилировать вместе с external.срр
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream> 

using std::cout;
extern double warming; // использование переменной warming из другого файла 
//-------------------------------------------------------------------------------------------------
// Прототипы функций 
void update(double dt);
void local();
//-------------------------------------------------------------------------------------------------
void update(double dt) // модифицирует глобальную переменную 
{
	extern double warming; // необязательное повторное объявление 
	warming += dt; // использование глобальной переменной warming 
	cout << "Updating global warming to " << warming;
	cout << " degrees.\n";
}
//-------------------------------------------------------------------------------------------------
void local() // использует локальную переменную 
{
	double warming = 0.8; // новая переменная скрывает внешнюю переменную 
	cout << "Local warming = " << warming << " degrees. \n";
	// Доступ к глобальной переменной с помощью операции разрешения контекста 
	cout << "But global warming = " << ::warming;
	cout << " degrees . \n";
}
//-------------------------------------------------------------------------------------------------
/*
Global warming is 0.3 degrees.
Updating global warming to 0.4 degrees.
Global warming is 0.4 degrees.
Local warming = 0.8 degrees.
But global warming = 0.4 degrees .
Global warming is 0.4 degrees.
*/