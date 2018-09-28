//stack.срр -- функции-члены класса Stack 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "bank_account.h" 

//-------------------------------------------------------------------------------------------------
Bank_account::Bank_account()
{
	name_depositor = "NON";
	account_number = "000 000 000 000";
	balance = 0.0;
}
//-------------------------------------------------------------------------------------------------
Bank_account::Bank_account(const std::string & name_dep, const std::string & acc_num, double bal)
{
	name_depositor = name_dep;
	account_number = acc_num;

	if (bal < 0)
	{
		std::cout << "The balance can not be negative. Your balance will be set to 0 $" << std::endl;
		balance = 0;
	}
	else
	{
		balance = bal;
	}
}
//-------------------------------------------------------------------------------------------------
Bank_account::~Bank_account()
{
	std::cout << "All transactions with " << account_number << " completed." << std::endl;
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------
void Bank_account::show_account()
{
	std::cout << "Name of depositor: " << name_depositor << std::endl;
	std::cout << "Deposit number: " << account_number << std::endl;
	std::cout << "Balance: " << balance << " $" << std::endl;
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------
void Bank_account::add_balance(double bal)
{
	if (bal < 0)
	{
		std::cout << "The value can not be negative. 0$ added" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		balance += bal;
		std::cout << "The balance is credited with " << bal << "$" << std::endl;
		std::cout << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
void Bank_account::cash_withdrawal(double bal)
{
	if (bal > balance)
	{
		std::cout << "Unable to withdraw " << bal << "$.";
		std::cout << " On your balance sheet " << balance << "$." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		balance -= bal;
		std::cout << "Discontinued " << bal << "$";
		std::cout << " On your balance sheet " << balance << "$." << std::endl;
		std::cout << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------