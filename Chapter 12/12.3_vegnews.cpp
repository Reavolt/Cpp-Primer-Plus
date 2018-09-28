// vegnews.срр — использование операций new и delete с классами 
// компилировать вместе с strngbad.cpp 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "12.1_strngbad.h"

using std::cout;

//-------------------------------------------------------------------------------------------------
void callmel(StringBad &); // передача по ссылке 
void callme2(StringBad); // передача по значению 
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::endl;
	{
		cout << "Starting an inner block.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");
		cout << "headlinel: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callmel(headline1);
		cout << "headlinel: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;
		cout << "Initialize one object to another:\n";
		StringBad sailor = sports;
		cout << "sailor: " << sailor << endl;
		cout << "Assign one object to another:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "Exiting the block.\n";
	}
	cout << "End of main()\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void callmel(StringBad & rsb)
{
	cout << "String passed by reference:\n"; // строка, переданная по ссылке 
	cout << " \"" << rsb << "\"\n";
}
//-------------------------------------------------------------------------------------------------
void callme2(StringBad sb)
{
	cout << "String passed by value:\n"; // строка, переданная по значению 
	cout << " \"" << sb << "\"\n";
}
//-------------------------------------------------------------------------------------------------
/*
Starting an inner block.
1: "Celery Stalks at Midnight" object created
2: "Lettuce Prey" object created
3: "Spinach Leaves Bowl for Dollars" object created
headlinel: Celery Stalks at Midnight
headline2: Lettuce Prey
sports: Spinach Leaves Bowl for Dollars
String passed by reference:
"Celery Stalks at Midnight"
headlinel: Celery Stalks at Midnight
String passed by value:
"Lettuce Prey"
"Lettuce Prey" object deleted, 2 left
headline2: Du°
Initialize one object to another:
sailor: Spinach Leaves Bowl for Dollars
Assign one object to another:
3: "C++" default object created
knot: Celery Stalks at Midnight
Exiting the block.
"Celery Stalks at Midnight" object deleted, 2 left
"Spinach Leaves Bowl for Dollars" object deleted, 1 left
"Spinach Leaves Bowl for D0II8" object deleted, 0 left
"@g" object deleted, -1 left
"-Г object deleted, -2 left
End of main ()
*/