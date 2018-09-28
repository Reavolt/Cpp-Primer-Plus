// studenti.h — определение класса Student через закрытое наследование 
#ifndef STUDENTI_H_ 
#define STUDENTI_H_ 
#include <iostream> 
#include <valarray> 
#include <string> 

//-------------------------------------------------------------------------------------------------
class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	// Закрытый метод для вывода оценок 
	std::ostream & arr_out(std::ostream & os) const;
public:
	Student() : std::string("Null Student"), ArrayDb() {}
	explicit Student(const std::string & s)
		: std::string(s), ArrayDb() {}
	explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}
	Student(const std::string & s, int n)
		: std::string(s), ArrayDb(n) {}
	Student(const std::string & s, const ArrayDb & a)
		: std::string(s), ArrayDb(a) {}
	Student(const char * str, const double * pd, int n)
		: std::string(str), ArrayDb(pd, n) {}
	~Student() {}
	double Average() const;
	double & operator [] (int i);
	double operator [] (int i) const;
	const std::string & Name() const;
	
	// Друзья 
	// Ввод 
	friend std::istream & operator>>(std::istream & is, Student & stu); // 1 слово 
	friend std::istream & getline(std::istream & is, Student & stu); // 1 строка 
	// Вывод 
	friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};
//-------------------------------------------------------------------------------------------------
#endif // STUDENTI_H_