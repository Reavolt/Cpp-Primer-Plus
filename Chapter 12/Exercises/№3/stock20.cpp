// stock20.cpp -- дополненная версия 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "stock20.h"

//-------------------------------------------------------------------------------------------------
// Конструкторы (версии с выводом сообщений) 
Stock::Stock() // конструктор по умолчанию 
{
	std::cout << "Default constructor called\n";
	
	company = new char[8];
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
//-------------------------------------------------------------------------------------------------
Stock::Stock(const char* ch, long n, double pr)
{
	company = new char[strlen(ch) + 1];
	strcpy(company, ch);
	
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; ";
		std::cout << company << " shares set to 0.\n";
		shares = 0;
	}
	else
	{
		shares = n;
	}

	share_val = pr;
	set_tot();
}

//-------------------------------------------------------------------------------------------------
// Деструктор класса 
Stock::~Stock() // деструктор, не выводящий сообщений 
{
	delete[] company;
}
//-------------------------------------------------------------------------------------------------
// Другие методы
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		//Количество приобретаемых пакетов не может быть отрицательным. Транзакция прервана. 
		std::cout << "Number of shares purchased can't be negative. ";
		std::cout << "Transaction is aborted.\n";
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
	if (num < 0)
	{
		// Количество продаваемых пакетов не может быть отрицательным. Транзакция прервана, 
		std::cout << "Number of shares sold can't be negative. ";
		std::cout << "Transaction is aborted.\n";
	}
	else 
	if (num > shares)
	{
		// Нельзя продать больше того, чем находится во владении. Транзакция прервана, 
		std::cout << "You can't sell more than you have! ";
		std::cout << "Transaction is aborted.\n";
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
std::ostream & operator << (std::ostream & os, const Stock & st)
{
	// Установка формата в #.### 
	std::ios_base::fmtflags orig =
	os.setf( std::ios_base::fixed, std::ios_base::floatfield);
	std::streamsize prec = os.precision(3);
	
	os << "Company: " << st.company;
	os << " Shares: " << st.shares << '\n';
	os << " Share Price: $" << st.share_val;
	
	// Установка формата в #.## 
	os.precision(2);
	os << " Total Worth: $" << st.total_val << '\n';
	
	// Восстановление исходного формата 
	os.setf(orig, std::ios_base::floatfield);
	os.precision(prec);
	
	return os;
}
//-------------------------------------------------------------------------------------------------
const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
	{
		return s;
	}
	else
	{
		return *this;
	}
}
//-------------------------------------------------------------------------------------------------