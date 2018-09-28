//callable.срр — вызываемые типы и шаблоны 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "18.6_somedefs.h" 

//--------------------------------------------------------------------------------------------------
double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }
//--------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	double y = 1.21;
	cout << "Function pointer dub:\n"; // указатель на функцию dub 
	cout << " " << use_f(y, dub) << endl;
	cout << "Function pointer square:\n"; // указатель на функцию square 
	cout << " " << use_f(y, square) << endl;
	cout << "Function object Fp:\n"; // функциональный объект Fp 
	cout << " " << use_f(y, Fp(5.0)) << endl;
	cout << "Function object Fq:\n"; // функциональный объект Fq 
	cout << " " << use_f(y, Fq(5.0)) << endl;
	cout << "Lambda expression l:\n"; // лямбда-выражение 1 
	cout << " " << use_f(y, [](double u) {return u * u; }) << endl;
	cout << "Lambda expression 2:\n"; // лямбда-выражение 2 
	cout << " " << use_f(y, [](double u) {return u + u / 2.0; }) << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------
/*
Function pointer dub:
use_f count = 1, &count = 001BC144
2.42
Function pointer square:
use_f count = 2, &count = 001BC144
1.4641
Function object Fp:
use_f count = 1, &count = 001BC148
6.05
Function object Fq:
use_f count = 1, &count = 001BC14C
6.21
Lambda expression l:
use_f count = 1, &count = 001BC150
1.4641
Lambda expression 2:
use_f count = 1, &count = 001BC154
1.815
*/