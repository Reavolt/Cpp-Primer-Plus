#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>
#include <fstream>

//--------------------------------------------------------------------------------------------------
class abstr_emp
{
private:
	std::string fname;    // abstr_emp's имя
	std::string lname;    // abstr_emp's фамилия
	std::string job;
public:
	enum classkind { Employee, Manager, Fink, Highfink };
	abstr_emp();
	abstr_emp(const std::string & fn, const std::string &  ln,
		const std::string &  j);
	virtual void ShowAll() const;    // показывает все данные
	virtual void SetAll();        	 // запрашивает у пользователя значения
	friend std::ostream & operator <<(std::ostream & os, const abstr_emp & e);
	// просто отображает имя и фамилию
	virtual ~abstr_emp() = 0;         // виртуальный базовый класс
	virtual void writeall(std::ofstream & ofs) const;
	virtual void getall(std::ifstream & ofs);
};
//--------------------------------------------------------------------------------------------------
class employee : public abstr_emp
{
public:
	employee();
	employee(const std::string & fn, const std::string & ln,
		const std::string & j);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeall(std::ofstream & ofs) const;
	virtual void getall(std::ifstream & ofs);
};
//--------------------------------------------------------------------------------------------------
class manager : virtual public abstr_emp
{
private:
	int inchargeof;        //количество управляемых abstr_emps
protected:
	int InChargeOf() const { return inchargeof; } // вывод
	int & InChargeOf() { return inchargeof; }      // ввод
public:
	manager();
	manager(const std::string & fn, const std::string & ln,
		const std::string & j, int ico = 0);
	manager(const abstr_emp & e, int ico);
	manager(const manager & m);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeall(std::ofstream & ofs) const;
	virtual void getall(std::ifstream & ofs);
};
//--------------------------------------------------------------------------------------------------
class fink : virtual public abstr_emp
{
private:
	std::string reportsto;        // кому сообщает
protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string & ReportsTo() { return reportsto; }
public:
	fink();
	fink(const std::string & fn, const std::string & ln,
		const std::string & j, const std::string & rpo);
	fink(const abstr_emp & e, const std::string & rpo);
	fink(const fink & e);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeall(std::ofstream & ofs) const;
	virtual void getall(std::ifstream & ofs);
};
//--------------------------------------------------------------------------------------------------
class highfink : public manager, public fink // управление fink
{
public:
	highfink();
	highfink(const std::string & fn, const std::string & ln,
		const std::string & j, const std::string & rpo,
		int ico);
	highfink(const abstr_emp & e, const std::string & rpo, int ico);
	highfink(const fink & f, int ico);
	highfink(const manager & m, const std::string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeall(std::ofstream & ofs) const;
	virtual void getall(std::ifstream & ofs);
};
//--------------------------------------------------------------------------------------------------
#endif // EMP_H_