// travel.срр -- использование структур с функциями 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

const int Mins_per_hr = 60;
//------------------------------------------------------------------------------------------------
travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);
//------------------------------------------------------------------------------------------------
struct travel_time
{
	int hours;
	int mins;
};
//------------------------------------------------------------------------------------------------
int main() {

	using namespace std;
	travel_time day1 = { 5, 45 };		// 5 часов 45 минут 
	travel_time day2 = { 4, 55 };		// 4 часов 55 минут 
	travel_time trip = sum(day1, day2);		
	cout << "Two-day total: ";			// итог за два дня 
	show_time(trip);
	travel_time day3 = { 4, 32 };
	cout << "Three-day total: ";		// итог за три дня 
	show_time(sum(trip, day3));

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
travel_time sum(travel_time t1, travel_time t2)
{
	travel_time total;
	total.mins = (t1.mins + t2.mins) % Mins_per_hr;
	total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;
	return total;
}
//------------------------------------------------------------------------------------------------
void show_time(travel_time t)
{
		cout << t.hours << " hours, "
			 << t.mins << " minutes\n"; // часов, минут 
}
//------------------------------------------------------------------------------------------------
/*
Two-day total: 10 hours, 40 minutes
Three-day total: 15 hours, 12 minutes
*/