// stone.срр — определенные пользователем преобразования 
// Компилировать вместе с stonewt.срр 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "11.16_stonewt.h"

using std::cout;

//-------------------------------------------------------------------------------------------------
void display(const Stonewt & st, int n);
//-------------------------------------------------------------------------------------------------
int main()
{
	Stonewt incognito = 275; // использование конструктора для инициализации 
	Stonewt wolfe(285.7); // то же, что и Stonewt wolfe = 285.7; 
	Stonewt taft(21, 8);
	cout << "The celebrity weighed ";
	incognito.show_stn();
	cout << "The detective weighed ";
	wolfe.show_stn();
	cout << "The President weighed ";
	taft.show_lbs();
	incognito = 276.8; // использование конструктора для преобразования 
	taft = 325; // то же, что и taft = Stonewt (325) ; 
	cout << "After dinner, the celebrity weighed ";
	incognito.show_stn();
	cout << "After dinner, the President weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		st.show_stn();
	}
}
//-------------------------------------------------------------------------------------------------
/*
The celebrity weighed 19 stone, 9 pounds
The detective weighed 20 stone, 5.7 pounds
The President weighed 302 pounds
After dinner, the celebrity weighed 19 stone, 10.8 pounds
After dinner, the President weighed 325 pounds
Wow! 23 stone, 3 pounds
Wow! 23 stone, 3 pounds
The wrestler weighed even more.
Wow! 30 stone, 2 pounds
Wow! 30 stone, 2 pounds
No stone left unearned
Для продолжения нажмите любую клавишу . . .
*/