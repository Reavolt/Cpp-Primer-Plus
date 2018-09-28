//stock00.h -- интерфейс класса Stock 
//версия 00 
#ifndef STOCK00_H_
#define STOCK00_H_ 
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
	void acquire(const std::string & со, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
}; // обратите внимание на точку с вап¤той в конце. 
//-------------------------------------------------------------------------------------------------
#endif 