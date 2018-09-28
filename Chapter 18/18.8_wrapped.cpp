//wrapped.срр -- использование оболочки function в качестве аргумента 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <functional>
#include "18.6_somedefs.h" 

//--------------------------------------------------------------------------------------------------
double dub(double x) { return 2.0*x; }
double square(double x) { return x * x; }
//--------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	using std::function;
	double y = 1.21;
	function<double(double)> efl = dub;
	function<double(double)> ef2 = square;
	function<double(double)> ef3 = Fq(10.0);
	function<double(double)> ef4 = Fp(10.0);
	function<double(double)> ef5 = [](double u) {return u * u; };
	function<double(double)> ef6 = [](double u) {return u + u / 2.0; };
	cout << "Function pointer dub:\n"; // указатель на функцию dub 
	cout << " " << use_f(y, efl) << endl;
	cout << "Function pointer square:\n"; // указатель на функцию square 
	cout << " " << use_f(y, ef2) << endl;
	cout << "Function object Fp:\n"; // функциональный объект Fp 
	cout << " " << use_f(y, ef3) << endl;
	cout << "Function object Fq:\n"; // функциональный объект Fq 
	cout << " " << use_f(y, ef4) << endl;
	cout << "Lambda expression l:\n"; // лямбда-выражение 1 
	cout << " " << use_f(y, ef5) << endl;
	cout << "Lambda expression 2:\n"; // лямбда-выражение 2 
	cout << " " << use_f(y, ef6) << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------
/*
Function pointer dub:
use_f count = 1, &count = 011914E4
2.42
Function pointer square:
use_f count = 2, &count = 011914E4
1.4641
Function object Fp:
use_f count = 3, &count = 011914E4
11.21
Function object Fq:
use_f count = 4, &count = 011914E4
12.1
Lambda expression l:
use_f count = 5, &count = 011914E4
1.4641
Lambda expression 2:
use_f count = 6, &count = 011914E4
1.815
*/