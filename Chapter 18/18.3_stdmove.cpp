//stdmove.срр -- использование std::move() 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <utility> 

//--------------------------------------------------------------------------------------------------
// Интерфейс 
class Useless
{
private:
	int n;			 // количество элементов 
	char* pc;		 // указатель на данные 
	static int ct;   // количество объектов 
	void ShowObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless & f); // обычный конструктор копирования 
	Useless(Useless && f);		// конструктор переноса 
	~Useless();
	Useless operator+(const Useless & f) const;
	Useless & operator=(const Useless & f); // операция присваивания с копированием 
	Useless & operator=(Useless && f);		// операция присваивания с переносом 
	void ShowData() const;
};
//--------------------------------------------------------------------------------------------------
// Реализация 
int Useless::ct = 0;
Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
}
//--------------------------------------------------------------------------------------------------
Useless::Useless(int k) : n(k)
{
	++ct;
	pc = new char[n];
}
//--------------------------------------------------------------------------------------------------
Useless::Useless(int к, char ch) : n(к)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = ch;
}
//--------------------------------------------------------------------------------------------------
Useless::Useless(const Useless & f) : n(f.n)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
}
//--------------------------------------------------------------------------------------------------
Useless::Useless(Useless && f) : n(f.n)
{
	++ct;
	pc = f.pc; // заимствовать адрес 
	f.pc = nullptr; // установить старый объект в нулевой указатель 
	f.n = 0;
}
//--------------------------------------------------------------------------------------------------
Useless::~Useless()
{
	delete[] pc;
}
//--------------------------------------------------------------------------------------------------
Useless & Useless::operator=(const Useless & f) // операция присваивания с копированием 
{
	std::cout << "copy assignment operator called:\n";
	// вызов операции присваивания с копированием 
	if (this == &f)
		return *this;
	delete[] pc;
	n = f.n;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	return *this;
}
//--------------------------------------------------------------------------------------------------
Useless & Useless::operator=(Useless && f) // операция присваивания с переносом 
{
	std::cout << "move assignment operator called:\n";
	// вызов операции присваивания с переносом 
	if (this == &f)
		return *this;
	delete[] pc;
	n = f.n;
	pc = f.pc;
	f.n = 0;
	f.pc = nullptr;
	return *this;
}
//--------------------------------------------------------------------------------------------------
Useless Useless::operator+(const Useless & f) const
{
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];
	return temp;
}
//--------------------------------------------------------------------------------------------------
void Useless::ShowObject() const
{
	std::cout << "Number of elements: " << n; // количество элементов 
	std::cout << " Data address: " << (void *) pc << std::endl; // адрес данных 
}
//--------------------------------------------------------------------------------------------------
void Useless::ShowData() const
{
	if (n == 0)
		std::cout << " (object empty)"; // объект пуст 
	else
		for (int i = 0; i < n; i++)
			std::cout << pc[i];
	std::cout << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	{
		Useless one(10, 'x');
		Useless two = one + one; // вызов конструктора с переносом 
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		Useless three, four;
		cout << "three = one\n";
		three = one; // автоматическое присваивание с копированием 
		cout << "now object three = ";
		three.ShowData();
		cout << "and object one = ";
		one.ShowData();
		cout << "four = one + two\n";
		four = one + two; // автоматическое присваивание с переносом 
		cout << "now object four = ";
		four.ShowData();
		cout << "four = move(one)\n";
		four = std::move(one); // принудительное присваивание с переносом 
		cout << "now object four = ";
		four.ShowData();
		cout << "and object one = ";
		one.ShowData();
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------
/*
object one: xxxxxxxxxx
object two: xxxxxxxxxxxxxxxxxxxx
three = one
copy assignment operator called:
now object three = xxxxxxxxxx
and object one = xxxxxxxxxx
four = one + two
move assignment operator called:
now object four = xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
four = move(one)
move assignment operator called:
now object four = xxxxxxxxxx
and object one =  (object empty)
*/