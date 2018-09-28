// stonewtl.h -- усовершенствованное определение класса Stonewt 
#ifndef STONEWT1_H_ 
#define STONEWT1_H_

//-------------------------------------------------------------------------------------------------
class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };		// фунтов на стоун 
	int stone;						// полных стоунов 
	double pds_left;				// дробное число фунтов 
	double pounds;					// общий вес в фунтах 
public:
	Stonewt(double lbs);			// конструктор для значения double фунтов 
	Stonewt(int stn, double lbs);	// конструктор для значения в стоунах и фунтах 
	Stonewt();						// конструктор по умолчанию 
	~Stonewt();
	void show_lbs() const;			// отображение веса в формате фунтов 
	void show_stn() const;			// отображение веса в формате стоунов 
	
	// Функции преобразования 
	operator int() const;
	operator double() const;
};
//-------------------------------------------------------------------------------------------------
#endif // STONEWT1_H_