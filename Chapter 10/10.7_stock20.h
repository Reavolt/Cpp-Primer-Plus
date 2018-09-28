// stock20.h -- дополненная версия 
#ifndef STOCK20_H_
#define STOCK20_H_ 
#include <string> 

//-------------------------------------------------------------------------------------------------
class Stock // объявление класса
{
private:
	std::string company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock(); // конструктор по умолчанию 
	Stock(const std::string & со, long n = 0, double pr = 0.0);
	~Stock(); // деструктор 
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show()const;
	const Stock & topval(const Stock & s) const;
};
//-------------------------------------------------------------------------------------------------
#endif // STOCK20_H_