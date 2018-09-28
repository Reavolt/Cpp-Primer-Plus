//stock10.h -- объявление класса Stock с добавленными конструкторами и деструктором 
#ifndef STOCK10_H_
#define STOCK10_H_ 
#include <string> 

//-------------------------------------------------------------------------------------------------
class Stock // объявление класса
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	// Два конструктора 
	Stock(); // конструктор по умолчанию 
	Stock(const std::string & со, long n = 0, double pr = 0.0);
	~Stock(); // деструктор 
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};
//-------------------------------------------------------------------------------------------------
#endif // STOCK10_H_