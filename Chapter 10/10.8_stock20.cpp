//stock20.cpp -- дополненная версия 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "10.7_stock20.h"

//-------------------------------------------------------------------------------------------------
// Конструкторы (версии с выводом сообщений) 
Stock::Stock() // конструктор по умолчанию 
{
	std::cout << "Default constructor called\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
//-------------------------------------------------------------------------------------------------
Stock::Stock(const std::string & со, long n, double pr)
{
	company = со;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
				  << company << " shares set to 0.\n";
		shares = 0;
	}
	else
	shares = n;
	
	share_val = pr;
	set_tot();
}

//-------------------------------------------------------------------------------------------------
// Деструктор класса 
Stock::~Stock() // деструктор, не выводящий сообщений 
{

}
//-------------------------------------------------------------------------------------------------
// Другие методы
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		//Количество приобретаемых пакетов не может быть отрицательным. Транзакция прервана. 
		std::cout << "Number of shares purchased can't be negative. "
				  << "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
//-------------------------------------------------------------------------------------------------
void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		// Количество продаваемых пакетов не может быть отрицательным. Транзакция прервана, 
		cout << "Number of shares sold can't be negative. "
			 << "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		// Нельзя продать больше того, чем находится во владении. Транзакция прервана, 
		cout << "You can't sell more than you have! "
			 << "Transaction is aborted.\n";
	}
	else
	{
	shares -= num;
	share_val = price;
	set_tot();
	}
}
//-------------------------------------------------------------------------------------------------
void Stock::update(double price)
{
	share_val = price;
	set_tot();
}
//-------------------------------------------------------------------------------------------------
void Stock::show() const
{
	using std::cout;
	using std::ios_base;
	// Установка формата в #.### 
	ios_base::fmtflags orig =
	cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	cout << "Company: " << company
		 << " Shares: " << shares << '\n';
	cout << " Share Price: $" << share_val;
	// Установка формата в #.## 
	cout.precision(2);
	cout << " Total Worth: $" << total_val << '\n';
	// Восстановление исходного формата 
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);

}
//-------------------------------------------------------------------------------------------------
const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}
//-------------------------------------------------------------------------------------------------