// string1.срр — методы класса String 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "strng1.h"

//-------------------------------------------------------------------------------------------------
// Инициализация статического члена класса 
int String::num_strings = 0;
//-------------------------------------------------------------------------------------------------
// Статический метод 
int String::HowMany()
{
	return num_strings;
}
//-------------------------------------------------------------------------------------------------
// Создание String из С-строки 
String::String(const char* s)
{
	len = std::strlen(s);						// установка размера 
	str = new char[len + 1];					// выделение памяти 
	std::strcpy(str, s);						// инициализация указателя 
	num_strings++;								// корректировка счетчика объектов 
}
//-------------------------------------------------------------------------------------------------
// конструктор по умолчанию 
String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';								// строка по умолчанию 
	num_strings++;
}
//-------------------------------------------------------------------------------------------------
String::String(const String & st)
{
	num_strings++;								// обработка обновления статического члена 
	len = st.len;								// длина та же 
	str = new char[len + 1];					// выделение памяти 
	std::strcpy(str, st.str);					// копирование строки в новое место 
}
//-------------------------------------------------------------------------------------------------
// необходимый деструктор 
String::~String()
{
	--num_strings;
	delete[] str;  
}
//-------------------------------------------------------------------------------------------------
// Методы перегруженных операций 
// Присваивание объекта String объекту String 
String & String::operator = (const String & st)
{
	if (this == &st)
	}
		return *this;
	}
	delete[] str;
	
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	
	return *this;
}
//-------------------------------------------------------------------------------------------------
// Присваивание С-строки объекту String 
String & String::operator = (const char* s)
{
	delete[] str;
	
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	
	return *this;
}
//-------------------------------------------------------------------------------------------------
// Доступ для чтения и записи отдельных символов в неконстантном объекте String 
char & String::operator [] (int i)
{
	return str[i];
}
//-------------------------------------------------------------------------------------------------
// Доступ только для чтения отдельных символов в константном объекте String 
const char & String::operator [] (int i) const
{
	return str[i];
}
//-------------------------------------------------------------------------------------------------
// Дружественные функции перегруженных операций 
bool operator < (const String & stl, const String & st2)
{
	return (std::strcmp(stl.str, st2.str) < 0);
}
//-------------------------------------------------------------------------------------------------
bool operator > (const String & stl, const String & st2)
{
	return st2.str < stl.str;
}
//-------------------------------------------------------------------------------------------------
bool operator == (const String & stl, const String & st2)
{
	return (std::strcmp(stl.str, st2.str) == 0);
}
//-------------------------------------------------------------------------------------------------
String operator + (const String & st, const String & st2)
{
	String temp;
	delete temp.str;
	
	temp.len = strlen(st.str) + strlen(st2.str);
	temp.str = new char[temp.len + 1];
	strcat(strcpy(temp.str, st.str), st2.str);
	
	return temp;
}
//-------------------------------------------------------------------------------------------------
String operator+(const char* st, const String & st2)
{
	String temp;
	delete[] temp.str;
	
	temp.len = strlen(st) + st2.len;
	temp.str = new char[temp.len + 1];
	strcat(strcpy(temp.str, st), st2.str);
	
	return temp;
}
//-------------------------------------------------------------------------------------------------
int String::has(char ch)
{
	int count = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == ch)
		{
			count++;
		}
	}
	return count;
}
//-------------------------------------------------------------------------------------------------
void String::stringup()
{
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		str[i] = toupper(str[i]);
	}
}
//-------------------------------------------------------------------------------------------------
void String::stringlow()
{
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		str[i] = tolower(str[i]);
	}
}
//-------------------------------------------------------------------------------------------------
// Простой вывод String 
std::ostream & operator << (std::ostream & os, const String & st)
{
	os << st.str;
	return os;
}
//-------------------------------------------------------------------------------------------------
// Простой ввод String 
std::istream & operator>>(std::istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	
	if (is)
	{
		st = temp;
	}
	
	while (is && is.get() != '\n')
	{
		continue;
	}
	
	return is;
}
//-------------------------------------------------------------------------------------------------