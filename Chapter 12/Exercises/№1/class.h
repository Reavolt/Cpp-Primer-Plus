#ifndef CLASS_H_  
#define CLASS_H_ 
#include <iostream>
#include <cstring>

//-------------------------------------------------------------------------------------------------
class Cow 
{
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator = (const Cow & c);
	void ShowCow() const; // отображение всех данных cow
};
//-------------------------------------------------------------------------------------------------
#endif // CLASS_H_