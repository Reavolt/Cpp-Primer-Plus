// use_tv.cpp — использование классов Тѵ и Remote 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "15.1_tv.h"

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	Tv s42;
	cout << "Initial settings for 42\" TV:\n";		// начальные настройки телевизора 42 
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";		// отрегулированные настройки телевизора 42 

	s42.settings();					

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";	// настройки телевизора 42 после использования пульта 

	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:\n";		// настройки телевизора 58 
	s58.settings();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Initial settings for 42" TV:
TV is Off

Adjusted settings for 42" TV:
TV is On
Volume setting = 5
Channel setting = 3
Mode = cable
Input = TV

42" settings after using remote:
TV is On
Volume setting = 7
Channel setting = 10
Mode = cable
Input = TV

58" settings:
TV is On
Volume setting = 5
Channel setting = 28
Mode = antenna
Input = TV
Для продолжения нажмите любую клавишу . . .
*/