//dma.cpp — методы классов с динамическим выделением памяти 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "13.14_dma.h"

//-------------------------------------------------------------------------------------------------
// Методы baseDMA 
baseDMA::baseDMA(const char * l, int r)
{
	label = new char[std:: strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
//-------------------------------------------------------------------------------------------------
baseDMA::baseDMA(const baseDMA & rs)
{
	label = new char[std:: strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}
//-------------------------------------------------------------------------------------------------
baseDMA::~baseDMA()
{
	delete[] label;
}
//-------------------------------------------------------------------------------------------------
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std:: strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}
//-------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << "Label: " << rs.label << std::endl; // название 
	os << "Rating: " << rs.rating << std::endl; // рейтинг 
	return os;
}
//-------------------------------------------------------------------------------------------------
// Методы lacksDMA 
lacksDMA::lacksDMA(const char * c, const char * l, int r)
	: baseDMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}
//-------------------------------------------------------------------------------------------------
lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
	: baseDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = ' \0 ';
}
//-------------------------------------------------------------------------------------------------
std::ostream & operator<< (std::ostream & os, const lacksDMA & Is)
{
	os << (const baseDMA &) Is;
	os << "Color: " << Is.color << std::endl; // цвет 
	return os;
}
//-------------------------------------------------------------------------------------------------
// Методы hasDMA 
hasDMA::hasDMA(const char * s, const char * l, int r)
	: baseDMA(l, r)
{
	style = new char[std:: strlen(s) + 1];
	std::strcpy(style, s);
}
//-------------------------------------------------------------------------------------------------
hasDMA::hasDMA(const char * s, const baseDMA & rs)
	: baseDMA(rs)
{
	style = new char[std:: strlen(s) + 1];
	std::strcpy(style, s);
}
//-------------------------------------------------------------------------------------------------
hasDMA::hasDMA(const hasDMA & hs)
	: baseDMA(hs) // вызывает конструктор копирования базового класса 
{
	style = new char[std:: strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}
//-------------------------------------------------------------------------------------------------
hasDMA::~hasDMA()
{
	delete[] style;
}
//-------------------------------------------------------------------------------------------------
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs); // копирование базовой части 
	delete[] style; // подготовка к операции new для style 
	style = new char[std:: strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}
//-------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
	os << (const baseDMA &) hs;
	os << "Style: " << hs.style << std::endl; // стиль 
	return os;
}
//-------------------------------------------------------------------------------------------------