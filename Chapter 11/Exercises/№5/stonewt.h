// stonewt.h — определение класса Stonewt 
#ifndef STONEWT_H_ 
#define STONEWT_H_
#include <iostream>

//-------------------------------------------------------------------------------------------------
class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };		// фунтов на стоун 
	enum Mode { STONE, iPOUND, dPOUND }; //Методы вывода
	Mode mode;						// Переменная метода вывода
	void setmode();                 // Установка метода вывода
	int stone;						// полных стоунов 
	double pds_left;				// дробное число фунтов 
	double dpounds;                 // весь вес в дробных фунтах
	int ipounds;                    // весь вес целых фунтов
public:
	Stonewt(double lbs);			// конструктор для значения в фунтах 
	Stonewt(int stn, double lbs);	// конструктор для значения в стоунах и фунтах 
	Stonewt();					    // конструктор по умолчанию 
	~Stonewt();
	void setmode(int m);            // Устанеовка метода для пользователя
	
	//Перегрузка операторов
	friend Stonewt operator+(const Stonewt & stn1, const Stonewt & stn2);
	friend Stonewt operator-(const Stonewt & stn1, const Stonewt & stn2);
	friend Stonewt operator*(const Stonewt & stn1, const Stonewt & stn2);
	friend std::ostream & operator<<(std::ostream & os, const Stonewt & stn);
};
//-------------------------------------------------------------------------------------------------
#endif // STONEWT_H_