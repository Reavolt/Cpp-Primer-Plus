//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

#if 0
//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------
#endif
int main()
{
	//TooBig<int> f100(100); // предельное значение = 100 
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	std::list<int> yadayada(vals, vals + 10); // конструктор диапазона 
	std::list<int> etcetera(vals, vals + 10);

	//  место этого в C++11 можно использовать следующий код: 
	//  list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	//  list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

	auto outint = [](int n) {std::cout << n << " "; };
	std::cout << "Original lists:\n";	// исходные списки 
	std::for_each(yadayada.begin(), yadayada.end(), outint);
	std::cout << std::endl;
	std::for_each(etcetera.begin(), etcetera.end(), outint);
	std::cout << std::endl;

	yadayada.remove_if([](int x) {return x > 100; });
	etcetera.remove_if([](int x) {return x > 200; });
	//yadayada.remove_if(f100);              // использование именованного функционального объекта 
	//etcetera.remove_if(TooBig<int>(200));  // конструирование функционального объекта 
	
	std::cout << "Trimmed lists:\n";			   // усеченные списки 
	std::for_each(yadayada.begin(), yadayada.end(), outint);
	std::cout << std::endl;
	std::for_each(etcetera.begin(), etcetera.end(), outint);
	std::cout << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------