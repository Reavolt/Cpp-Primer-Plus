//usebrassl.cpp — тестирование классов банковских счетов 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "13.7_brass.h" 

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout; 
	using std::endl; 
	Brass Piggy("Porcelot Pigg", 381299, 4000.00); 
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00); 
	Piggy.ViewAcct (); 
	cout << endl; 
	Hoggy.ViewAcct (); 
	cout << endl; 
	cout << "Depositing $1000 into the Hogg Account:\n"; 
	Hoggy.Deposit(1000.00); 
	cout << "New balance: $" << Hoggy .Balance () << endl; 
	cout << "Withdrawing $4200 from the Pigg Account: \n"; 
	Piggy.Withdraw(4200.00); 
	cout << "Pigg account balance: $" << Piggy .Balance () << endl; 
	cout << "Withdrawing $4200 from the Hogg Account: \n"; 
	Hoggy.Withdraw (4200.00); 
	Hoggy.ViewAcct (); 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------

/*
Client: Porcelot Pigg 
Account Number: 381299 
Balance: $4000.00 
Client: Horatio Hogg 
Account Number: 382288 
Balance: $3000.00 
Maximum loan: $500.00 
Owed to bank: $0.00 
Loan Rate: 11.125% 
Depositing $1000 into the Hogg Account: 
New balance: $4000 
Withdrawing $4200 from the Pigg Account: 
Withdrawal amount of $4200.00 exceeds your balance. 
Withdrawal canceled. 
Pigg account balance: $4000 
Withdrawing $4200 from the Hogg Account: 
Bank advance: $200.00 
Finance charge: $22.25 
Client: Horatio Hogg 
Account Number: 382288 
Balance: $0.00 
Maximum loan: $500.00 
Owed to bank: $222.25 
Loan Rate: 11.125% 

Для продолжения нажмите любую клавишу . . .
*/