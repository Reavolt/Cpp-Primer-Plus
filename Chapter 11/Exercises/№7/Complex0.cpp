// stonewt.срр -- методы класса Stonewt 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "Complex0.h"

//-------------------------------------------------------------------------------------------------
Complex::Complex()
{
	m_real = 0;
	m_imag = 0;
}
//-------------------------------------------------------------------------------------------------
Complex::Complex(double n1, double n2)
{
	m_real = n1;
	m_imag = n2;
}
//-------------------------------------------------------------------------------------------------
Complex::~Complex()
{

}
//-------------------------------------------------------------------------------------------------
Complex operator + (const Complex & n1, const Complex & n2)
{
	Complex Result(n1.m_imag + n2.m_imag, n1.m_real + n2.m_real);
	return Result;
}
//-------------------------------------------------------------------------------------------------
Complex operator - (const Complex & n1, const Complex & n2)
{
	Complex Result(n1.m_imag - n2.m_imag, n1.m_real - n2.m_real);
	return Result;
}
//-------------------------------------------------------------------------------------------------
Complex operator * (const Complex & n1, const Complex & n2)
{
	Complex Result(n1.m_imag * n2.m_imag, n1.m_real * n2.m_real);
	return Result;
}
//-------------------------------------------------------------------------------------------------
Complex operator * (double num, const Complex & n)
{
	Complex Result(num + n.m_imag, num + n.m_real);
	return Result;
}
//-------------------------------------------------------------------------------------------------
Complex operator * (const Complex & n, double num)
{
	Complex Result(num + n.m_imag, num + n.m_real);
	return Result;
}
//-------------------------------------------------------------------------------------------------
Complex operator ~ (const Complex & c)
{
	Complex Result(c.m_real, -c.m_imag);
	return Result;
}
//-------------------------------------------------------------------------------------------------
std::istream & operator >> (std::istream & is, Complex & c)
{
	std::cout << "real: ";
	is >> c.m_real;
	
	if (c.m_real)
	{
		std::cout << "imaginary: ";
		is >> c.m_imag;
	}
	return is;
}
//-------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const Complex & c)
{
	os << "(" << c.m_real << ", " << c.m_imag << "i)";
	return os;
}
//-------------------------------------------------------------------------------------------------