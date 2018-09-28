// string1.h — исправленное и расширенное объявление строкового класса 
#ifndef STRNG1_H_ 
#define STRNG1_H_ 
#include <iostream>
#include <cstring>
#include <cctype>

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
	String(const char* s);			// конструктор 
	String();						// конструктор по умолчанию 
	String(const String &);			// конструктор копирования 
	~String();						// деструктор 
	int length() const { return len; }
	void stringup();
	void stringlow();
	int has(char ch);

	// Методы перегруженных операций 
	String & operator=(const String &);
	String & operator=(const char*);
	char & operator [] (int i);
	const char & operator [] (int i) const;
	
	// Дружественные функции перегруженных операций 
	friend bool operator < (const String & st, const String & st2);
	friend bool operator > (const String & stl, const String & st2);
	friend bool operator == (const String & st, const String & st2);
	friend std::ostream & operator << (std::ostream & os, const String & st);
	friend std::istream & operator >> (std::istream & is, String & st);
	friend String operator + (const String & st, const String & st2);
	friend String operator + (const char* st, const String & st2);
	
	// Статическая функция 
	static int HowMany();
};
//-------------------------------------------------------------------------------------------------
#endif // STRNG1_H_ 