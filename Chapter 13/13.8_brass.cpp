//brass.срр — методы классов банковских счетов 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "13.7_brass.h"

using std::cout;
using std::endl;
using std::string;

//-------------------------------------------------------------------------------------------------
// Для целей форматирования 
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);
//-------------------------------------------------------------------------------------------------
// Методы Brass 
Brass::Brass(const string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}
//-------------------------------------------------------------------------------------------------
void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; "
		<< "deposit is cancelled.\n"; // отрицательный вклад не допускается 
	else
		balance += amt;
}
//-------------------------------------------------------------------------------------------------
void Brass::Withdraw(double amt)
{
	// Установка формата ###.## 
	format initialState = setFormat();
	precis prec = cout.precision(2);
	if (amt < 0)
		cout << "Withdrawal amount must be positive; "
		<< "withdrawal canceled.\n"; // снимаемая сумма должна быть положительной 
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amount of $" << amt
		<< " exceeds your balance.\n"
		<< "Withdrawal canceled.\n"; // снимаемая сумма превышает текущий баланс 
	restore(initialState, prec);

}
//-------------------------------------------------------------------------------------------------
double Brass::Balance() const
{
	return balance;
}
//-------------------------------------------------------------------------------------------------
void Brass::ViewAcct() const
{
	// Установка формата ###.## 
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullName << endl; // клиент 
	cout << "Account Number: " << acctNum << endl; // номер счета 
	cout << "Balance: $" << balance << endl; // баланс 
	restore(initialState, prec); // восстановление исходного формата 
}
//-------------------------------------------------------------------------------------------------
// Методы BrassPlus 
BrassPlus::BrassPlus(const string & s, long an, double bal,
	double ml, double r) : Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
//-------------------------------------------------------------------------------------------------
BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
	: Brass(ba) // используется неявный конструктор копирования 
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
//-------------------------------------------------------------------------------------------------
// Переопределение реализации метода ViewAcctO 
void BrassPlus::ViewAcct() const
{
	// Установка формата ###.## 
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::ViewAcct();								// отображение базовой части 
	cout << "Maximum loan: $" << maxLoan << endl;	// максимальный заем 
	cout << "Owed to bank: $" << owesBank << endl;	// долг банку 
	cout.precision(3);								// формат ###.### 
	cout << "Loan Rate: " << 100 * rate << "%\n";	// процент на заем 
	restore(initialState, prec);
}
//-------------------------------------------------------------------------------------------------
// Переопределение реализации метода Withdraw() 
void BrassPlus::Withdraw(double amt)
{
	// Установка формата ###.## 
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal = Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance: $" << advance << endl; // аванс банка 
		cout << "Finance charge: $" << advance * rate << endl; // долг банку 
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled.\n"; //предел кредита превышен 
	restore(initialState, prec);
}
//-------------------------------------------------------------------------------------------------
format setFormat()
{
	// Установка формата ###.## 
	return cout.setf(std::ios_base::fixed,
		std::ios_base::floatfield);
}
//-------------------------------------------------------------------------------------------------
void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}
//-------------------------------------------------------------------------------------------------