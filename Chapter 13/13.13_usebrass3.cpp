//usebrass3.срр - полиморфный пример с использованием абстрактного базового класса 
//Компилировать вместе с acctacb.cpp 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "13.11_acctabc.h" 

const int CLIENTS = 4;

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	AcctABC * p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: "; // ввод имени клиента 
		getline(cin, temp);
		cout << "Enter client's account number: "; // ввод номера счета клиента 
		cin >> tempnum;
		cout << "Enter opening balance: $"; // ввод начального баланса 
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or " // 1 — Brass Account; 
			 << "2 for BrassPlus Account: "; // 2 -- BrassPlus Account 
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $"; // ввод предела овердрафта 
			cin >> tmax;
			cout << "Enter the interest rate "
				 << "as a decimal fraction: "; // ввод процентной ставки 
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i]; // освобождение памяти 
	}
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter client's name: Harry Fishsong
Enter client's account number: 112233
Enter opening balance: $1500
Enter 1 for Brass Account or 2 for BrassPlus Account: 1
Enter client's name: Dinah Otternoe
Enter client's account number: 121213
Enter opening balance: $1800
Enter 1 for Brass Account or 2 for BrassPlus Account: 2
Enter the overdraft limit: $350
Enter the interest rate as a decimal fraction: 0.12
Enter client's name: Brenda Birdherd
Enter client's account number: 212118
Enter opening balance: $5200
Enter 1 for Brass Account or 2 for BrassPlus Account: 2
Enter the overdraft limit: $800
Enter the interest rate as a decimal fraction: 0.10
Enter client's name: Tim Turtletop
Enter client's account number: 233255
Enter opening balance: $688
Enter 1 for Brass Account or 2 for BrassPlus Account: 1

Client: Harry Fishsong
Account Number: 112233
Balance: $1500.00

Client: Dinah Otternoe
Account Number: 121213
Balance: $1800.00
Maximum loan: $350.00
Owed to bank: $0.00
Loan Rate: 12.000%

Client: Brenda Birdherd
Account Number: 212118
Balance: $5200.00
Maximum loan: $800.00
Owed to bank: $0.00
Loan Rate: 10.000%

Client: Tim Turtletop
Account Number: 233255
Balance: $688.00

Done.
Для продолжения нажмите любую клавишу . . .
*/