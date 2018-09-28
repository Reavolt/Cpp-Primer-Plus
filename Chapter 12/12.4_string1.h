// string1.h — исправленное и расширенное объявление строкового класса 
#ifndef STRNG1_H_ 
#define STRNG1_H_ 
#include <iostream>

using std::ostream;
using std::istream;

//-------------------------------------------------------------------------------------------------
class String
{
private:
	char* str;						// указатель на строку 
	int len;						// длина строки 
	static int num_strings;			// количество объектов 
	static const int CINLIM = 80;	// предел ввода для сіп 
public:
	// Конструкторы и другие методы 
	String(const char * s);			// конструктор 
	String();						// конструктор по умолчанию 
	String(const String &);			// конструктор копирования 
	~String();						// деструктор 
	int length() const { return len; }
	
	// Методы перегруженных операций 
	String & operator=(const String &);
	String & operator=(const char *);
	char & operator [] (int i);
	const char & operator [] (int i) const;
	
	// Дружественные функции перегруженных операций 
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &stl, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream & os, const String & st);
	friend istream & operator>>(istream & is, String & st);
	
	// Статическая функция 
	static int HowMany();
};
//-------------------------------------------------------------------------------------------------
#endif // STRNG1_H_