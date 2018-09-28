//useless.срр — класс с семантикой переноса 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------------------
// Интерфейс 
class Useless
{
private:
	int n;				// количество элементов 
	char* pc;			// указатель на данные 
	static int ct;		// количество объектов 
	void ShowObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless & f); // обычный конструктор копирования 
	Useless(Useless && f);		// конструктор переноса 
	~Useless();
	Useless operator+(const Useless & f) const;

	// В версиях копирования и переноса необходима operator=() 
	void ShowData() const;
};
//--------------------------------------------------------------------------------------------------
// Реализация 
int Useless::ct = 0;
//--------------------------------------------------------------------------------------------------
Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
	// Вызов конструктора по умолчанию; вывод количества объектов 
	cout << "default constructor called; number of objects: " << ct << endl;
	ShowObject();
}
//--------------------------------------------------------------------------------------------------
Useless::Useless(int k) : n(k)
{
	++ct;
	// Вызов конструктора int; вывод количества объектов 
	cout << "int constructor called; number of objects: " << ct << endl;
	pc = new char[n];
	ShowObject();
}
//--------------------------------------------------------------------------------------------------
Useless::Useless(int k, char ch) : n(k)
{
	++ct;
	// Вызов конструктора int, char; вывод количества объектов 
	cout << "int, char constructor called; number of objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = ch;
	ShowObject();
}
//--------------------------------------------------------------------------------------------------
Useless::Useless(const Useless & f) : n(f.n)
{
	++ct;
	// Вызов конструктора копирования; вывод количества объектов 
	cout << "copy const called; number of objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	ShowObject();
}
//--------------------------------------------------------------------------------------------------
Useless::Useless(Useless && f) : n(f.n)
{
	++ct;
	// Вызов конструктора переноса; вывод количества объектов 
	cout << "move constructor called; number of objects: " << ct << endl;
	pc = f.pc; // заимствовать адрес 
	f.pc = nullptr; // установить старый объект в нулевой указатель 
	f.n = 0;
	ShowObject();

}
//--------------------------------------------------------------------------------------------------
Useless::~Useless()
{
	// Вызов деструктора; вывод количества объектов 
	cout << "destructor called; objects left: " << --ct << endl;
	cout << "deleted object:\n";
	ShowObject();
	delete[] pc;
}
//--------------------------------------------------------------------------------------------------
Useless Useless::operator+(const Useless & f)const
{
	cout << "Entering operator+()\n";	// начало operator+() 
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];
	cout << "temp object:\n";	// временный объект 
	cout << "Leaving operator+()\n";	// конец operator+() 
	return temp;
}
//--------------------------------------------------------------------------------------------------
void Useless::ShowObject() const
{
	cout << "Number of elements: " << n;	// количество элементов 
	cout << " Data address: " << (void *)pc << endl; // адрес данных 
}
//--------------------------------------------------------------------------------------------------
void Useless::ShowData() const
{
	if (n == 0)
		cout << "(object empty)";
	else
		for (int i = 0; i < n; i++)
			cout << pc[i];
	cout << endl;
}
//--------------------------------------------------------------------------------------------------
int main()
{
	{
		Useless one(10, 'x');
		Useless two = one;			// вызов конструктора копирования 
		Useless three(20, 'o');
		Useless four(one + three);	// вызов operator+(), конструктора переноса 
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		cout << "object three: ";
		three.ShowData();
		cout << "object four: ";
		four.ShowData();
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------
/*
int, char constructor called; number of objects: 1
Number of elements: 10 Data address: 02F3DA30
copy const called; number of objects: 2
Number of elements: 10 Data address: 02F3DA68
int, char constructor called; number of objects: 3
Number of elements: 20 Data address: 02F347F8
Entering operator+()
int constructor called; number of objects: 4
Number of elements: 30 Data address: 02F34838
temp object:
Leaving operator+()
move constructor called; number of objects: 5
Number of elements: 30 Data address: 02F34838
destructor called; objects left: 4
deleted object:
Number of elements: 0 Data address: 00000000
object one: xxxxxxxxxx
object two: xxxxxxxxxx
object three: oooooooooooooooooooo
object four: xxxxxxxxxxoooooooooooooooooooo
destructor called; objects left: 3
deleted object:
Number of elements: 30 Data address: 02F34838
destructor called; objects left: 2
deleted object:
Number of elements: 20 Data address: 02F347F8
destructor called; objects left: 1
deleted object:
Number of elements: 10 Data address: 02F3DA68
destructor called; objects left: 0
deleted object:
Number of elements: 10 Data address: 02F3DA30
*/