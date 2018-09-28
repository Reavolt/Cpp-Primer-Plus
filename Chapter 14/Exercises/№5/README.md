#### Глава - 14, Задание - 5 ####

Ниже приведено несколько объявлений классов:

```objectivec
// emp.h — заголовочный файл для класса abstr_emp и его дочерних классов 
#include <iostream> 
#include <string> 
class abstr_emp 
{ 
private: 
	std::string fname; // имяabstr_emp 
	std::string lname; // фамилия abstr_emp 
	std::string job; 
public: 
	abstr_emp(); 
	abstr_emp(const std::string & fn, const std::string & In, 
	const std::string & j); 
	virtual void ShowAll() const; // выводит все данные с именами 
	virtual void SetAll(); // запрашивает значения у пользователя 
	friend std::ostream & operator << (std::ostream & os, const abstr_emp & e); 
	// Выводит только имя и фамилию 
	virtual ~abstr_emp() = 0; // виртуальный базовый класс 
}; 
```

```objectivec
class employee : public abstr_emp 
{ 
public: 
	employee(); 
	employee(const std::string & fn, const std::string & In, 
	const std::string & j); 
	virtual void ShowAll() const; 
	virtual void SetAll(); 
}; 
```

```objectivec
class manager: virtual public abstr_emp 
{ 
private: 
	int inchargeof; // количество управляемых abstr_emp 
protected: 
	int InChargeOf() const { return inchargeof; } // вывод 
	int & InChargeOf() { return inchargeof; } // ввод 
public: 
	manager(); 
	manager(const std::string & fn, const std::string & In, 
	const std::string & j, int ico = 0); 
	manager(const abstr_emp & e, int ico); 
	manager(const manager & m); 
	virtual void ShowAll() const;
	virtual void SetAll();
};
```

```objectivec
class fink: virtual public abstr_emp 
{ 
private: 
	std::string reportsto; // кому выводить отчеты 
protected: 
	const std::string ReportsTo() const { return reportsto; } 
	std::string & ReportsTo() { return reportsto; } 
public: 
	fink(); 
	fink(const std::string & fn, const std::string & In, 
	const std::string & j, const std::string & rpo); 
	fink(const abstr_emp & e, const std::string & rpo); 
	fink(const fink & e); 
	virtual void ShowAll() const; 
	virtual void SetAll();
}; 
```

```objectivec
class highfink: public manager, public fink // надзор за управляющими 
{ 
public: 
	highfink(); 
	highfink(const std::string & fn, const std::string & In, 
	const std::string & j, const std::string & rpo, int ico); 
	highfink(const abstr_emp & e, const std::string & rpo, int ico); 
	highfink(const fink & f, int ico); 
	highfink(const manager & m, const std::string & rpo); 
	highfink(const highfink & h); 
	virtual void ShowAll() const; 
	virtual void SetAll(); 
}; 
```

Здесь в иерархии классов используется множественное наследование с
виртуальным базовым классом. Поэтому не забывайте о специальных правилах для
списков инициализации в конструкторах. Обратите также внимание на наличие
нескольких методов с защищенным доступом. Это упрощает код некоторых
методов ```highfink```. (Например, если метод ```highfink::ShowAll()``` просто
вызывает ```fink::ShowAll()``` и ```manager::ShowAll()```, то это приводит к двукратному
вызову ```abstremp::ShowAll()```.) Реализуйте эти методы и протестируйте классы.
Ниже приведена минимальная тестовая программа:

```objectivec
// ре14-5.срр 
// useempl.cpp — использование классов abstremp 
#include <iostream> 
using namespace std; 
#include "emp.h" 
int main(void) 
{ 
	employee em("Trip", "Harris", "Thumper"); 
	cout << em << endl; 
	em.ShowAll(); 
	manager ma("Amorphia", "Spindragon", "Nuancer", 5); 
	cout << ma << endl; 
	ma.ShowAll (); 
	fink fi("Matt", "Oggs", "Oiler", "JunoBarr"); 
	cout << fi << endl; 
	fi.ShowAHO; 
	highfink hf(ma, "Curly Kew"); // укомплектовано? 
	hf .ShowAlK); 
	cout << "Press a key for next phase:\n"; 
		// Нажать любую клавишу для следующей фазы 
	cin.get (); 
	highfink hf2; 
	hf2.SetAll(); 
	cout << "Using an abstr_emp * pointer:\n"; 
		// Использование указателя abstr_emp * 
	abstr_emp * tri[4] = {&em, &fi, &hf, &hf2}; 
	for (int i = 0; i < 4; i++) 
		tri[i]->ShowAll(); 
	return 0; 
}
```

Почему не определена операция присваивания?

Почему методы ```ShowAll()``` и ```SetAll()``` виртуальные?

Почему класс ```abstr_emp``` является виртуальным базовым классом?

Почему в классе ```highfink``` нет раздела данных?

Почему достаточно только одной версии операции ```operator << ()```?

Что произойдет, если код в конце программы модифицировать следующим
образом:

```objectivec
abstr_emp tri[4] = {em, fi, hf, hf2}; 
for (int i = 0; i < 4; i++) 
	tri[i].ShowAll();
```

=================================================================================
#### Вывод ####
```objectivec
Harris, Trip
Status: Employee
First name: Trip
Last name: Harris
Job: Thumper
Spindragon, Amorphia
Status: Manager
First name: Amorphia
Last name: Spindragon
Job: Nuancer
In charge of 5 people
Oggs, Matt
Status: fink
First name: Matt
Last name: Oggs
Job: Oiler
Reports to Juno Barr
Status: Highfink
First name: Amorphia
Last name: Spindragon
Job: Nuancer
In charge of 5 people
Reports to Curly Kew
Press a key for next phase:
a
Enter first name: Alex
Enter last name: Von
Enter the job: Programmer
Enter the number of people managed: 10
Enter whomever is reported to: Dian
Using an abstr_emp * pointer:
Status: Employee
First name: Trip
Last name: Harris
Job: Thumper
Status: fink
First name: Matt
Last name: Oggs
Job: Oiler
Reports to Juno Barr
Status: Highfink
First name: Amorphia
Last name: Spindragon
Job: Nuancer
In charge of 5 people
Reports to Curly Kew
Status: Highfink
First name: Alex
Last name: Von
Job: Programmer
In charge of 10 people
Reports to Dian
```
