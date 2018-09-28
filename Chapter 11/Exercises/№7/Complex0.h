// stonewt.h — определение класса Stonewt 
#ifndef COMPLEX0_H_ 
#define COMPLEX0_H_
#include <iostream>

//-------------------------------------------------------------------------------------------------
class Complex
{
private:
	double m_real;
	double m_imag;
public:
	Complex();
	Complex(double n1, double n2);	
	~Complex();
	friend Complex operator + (const Complex & n1, const Complex & n2);
	friend Complex operator - (const Complex & n1, const Complex & n2);
	friend Complex operator * (const Complex & n1, const Complex & n2);
	friend Complex operator * (double num, const Complex & n);
	friend Complex operator * (const Complex & n, double num);
	friend Complex operator ~ (const Complex & c);
	friend std::istream & operator>>(std::istream & is, Complex & c);
	friend std::ostream & operator<<(std::ostream & os, const Complex & c);
};
//-------------------------------------------------------------------------------------------------
#endif // COMPLEX0_H_