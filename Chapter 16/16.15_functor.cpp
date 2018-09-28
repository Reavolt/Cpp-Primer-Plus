//functor.срр -- Для использование класса functor 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

//-------------------------------------------------------------------------------------------------
template<class T>  // класс функтора определ¤ет operator()() 
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t) : cutoff(t) {}
	bool operator()(const T & v) { return v > cutoff; }
};
//-------------------------------------------------------------------------------------------------
void outint(int n) { std::cout << n << " "; }
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::list;
	using std::cout;
	using std::endl;
	using std::for_each;
	using std::remove_if;

	TooBig<int> f100(100); // предельное значение = 100 
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10); // конструктор диапазона 
	list<int> etcetera(vals, vals + 10);

	//  место этого в C++11 можно использовать следующий код: 
	//  list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	//  list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

	cout << "Original lists:\n";	// исходные списки 
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if(f100);              // использование именованного функционального объекта 
	etcetera.remove_if(TooBig<int>(200));  // конструирование функционального объекта 
	cout << "Trimmed lists:\n";			   // усеченные списки 
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Original lists:
50 100 90 180 60 210 415 88 188 201
50 100 90 180 60 210 415 88 188 201
Trimmed lists:
50 100 90 60 88
50 100 90 180 60 88 188
Для продолжени¤ нажмите любую клавишу . . .
*/