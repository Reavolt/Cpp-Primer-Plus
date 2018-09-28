//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "bank_account.h"

//-------------------------------------------------------------------------------------------------
void print_menu();
void transactions_menu();
//-------------------------------------------------------------------------------------------------
int main()
{
	Bank_account Acc;
	std::string name_depositor;
	std::string account_number;
	double balance = 0;
	int menu = 0;

	print_menu();

	while ((std::cin >> menu).get()) 
	{
		switch (menu)
		{
		case 1:
			std::cout << "================================" << std::endl;
			std::cout << "Enter the name of the account holder: " << std::endl;
			std::cin.sync();
			std::getline(std::cin, name_depositor);

			std::cout << "Enter the account number: " << std::endl;
			std::cin.sync();
			std::getline(std::cin, account_number);

			std::cout << "Enter the current balance: " << std::endl;
			std::cin.sync();
			std::cin >> balance;
			std::cout << "================================" << std::endl;

			Acc = Bank_account(name_depositor, account_number, balance);

			print_menu();
			break;
		case 2:
			transactions_menu();
			(std::cin >> menu).get();
			
			switch (menu)
			{
			case 1:
				std::cout << "Enter the amount to be credited to the balance: ";
				std::cin.sync();
				std::cin >> balance;
				Acc.add_balance(balance);
				break;
			case 2:
				std::cout << "Enter the amount to be withdrawn from the balance: ";
				std::cin.sync();
				std::cin >> balance;
				Acc.cash_withdrawal(balance);
				break;
			case 3:
				Acc.show_account();
				break;
			default:
				print_menu();
				break;
			}
			print_menu();
		}
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void print_menu()
{
	std::cout << "[1] - Create an account" << std::endl;
	std::cout << "[2] - Account Operations" << std::endl;
}
//-------------------------------------------------------------------------------------------------
void transactions_menu() 
{
	std::cout << "[1] - To contribute" << std::endl;
	std::cout << "[2] - Withdraw cash" << std::endl;
	std::cout << "[3] - Display Information" << std::endl;
}
//-------------------------------------------------------------------------------------------------