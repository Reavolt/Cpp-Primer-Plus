//switch.ерр -- использование оператора switch 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
void showmenu();   // прототипы функций 
void report();
void comfort();
//-------------------------------------------------------------------------------------------------
int main()
{
	showmenu();
	int choice;
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:   cout << "\a\n";
			break;
		case 2:   report();
			break;
		case 3:   cout << "The boss was in all day.\n";
			break;
		case 4:   comfort();
			break;
		default:   cout << "That's not a choice.\n";
		}
		showmenu();
		cin >> choice;
	}
	cout << "Bye!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void showmenu()
{
	cout << "Please enter 1, 2, 3, 4, or 5:\n"
		"1) alarm           2) report\n"
		"3) alibi           4) comfort\n"
		"5) quit\n";
}
//-------------------------------------------------------------------------------------------------
void report()
{
	cout << "It's been an excellent week for business.\n"
		"Sales are up 120%. Expenses are down 35%.\n";
}
void comfort()
{
	cout << "Your employees think you are the finest CEO\n"
		"in the industry. The board of directors think\n"
		"you are the finest CEO in the industry.\n";
}
//-------------------------------------------------------------------------------------------------
/*
Please enter 1, 2, 3, 4, or 5:
1) alarm           2) report
3) alibi           4) comfort
5) quit
4
Your employees think you are the finest CEO
in the industry. The board of directors think
you are the finest CEO in the industry.
Please enter 1, 2, 3, 4, or 5:
1) alarm           2) report
3) alibi           4) comfort
5) quit
2
It's been an excellent week for business.
Sales are up 120%. Expenses are down 35%.
Please enter 1, 2, 3, 4, or 5:
1) alarm           2) report
3) alibi           4) comfort
5) quit
6
That's not a choice.
Please enter 1, 2, 3, 4, or 5:
1) alarm           2) report
3) alibi           4) comfort
5) quit
5
Bye!
*/