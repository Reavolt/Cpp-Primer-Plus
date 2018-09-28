// strngbad.h -- несовершенное определение класса строки 
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
#include <iostream>

//-------------------------------------------------------------------------------------------------
class StringBad
{
private:
	char* str;					// указатель на строку 
	int len;					// длина строки 
	static int num_strings;		// количество объектов 
public:
	StringBad(const char * s);  // конструктор 
	StringBad();				// конструктор по умолчанию- 
	~StringBad();				//деструктор 
	
	// Дружественная функция 
	friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

//-------------------------------------------------------------------------------------------------
#endif // STRNGBAD_H_