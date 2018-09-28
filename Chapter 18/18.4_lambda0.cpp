//lambda0.cpp -- использование лямбда-выражений 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <ctime> 

const long Sizel = 39L;
const long Size2 = 100 * Sizel;
const long Size3 = 100 * Size2;

//--------------------------------------------------------------------------------------------------
bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }
//--------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	std::vector<int> numbers(Sizel);
	std::srand(std::time(0));
	std::generate(numbers.begin(), numbers.end(), std::rand);
	// Использование указателей на функции 
	cout << "Sample size = " << Sizel << '\n'; // размер выборки 
	int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	// количество чисел, кратных 3 
	int countl3 = std::count_if(numbers.begin(), numbers.end(), f13);
	cout << "Count of numbers divisible by 13: " << countl3 << "\n\n";
	// количество чисел, кратных 13 

	// Увеличение размера numbers 
	numbers.resize(Size2);
	std::generate(numbers.begin(), numbers.end(), std::rand);
	cout << "Sample size = " << Size2 << '\n'; // размер выборки 

	// Использование функтора 
	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int d = 1) : dv(d) {}
		bool operator () (int x) { return x % dv == 0; }
	};

	count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << "Count of numbers divisible by 3 : " << count3 << '\n';
	// количество чисел, кратных 3 
	countl3 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
	cout << "Count of numbers divisible by 13: " << countl3 << "\n\n";
	// количество чисел, кратных 13 

	// Повторное увеличение размера numbers 
	numbers.resize(Size3);
	std::generate(numbers.begin(), numbers.end(), std::rand);
	cout << "Sample size = " << Size3 << '\n'; // размер выборки 

	// Использование лямбда 
	count3 = std::count_if(numbers.begin(), numbers.end(),
		[](int x) {return x % 3 == 0; });
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	// количество чисел, кратных 3 
	countl3 = std::count_if(numbers.begin(), numbers.end(),
		[](int x) {return x % 13 == 0; });
	cout << "Count of numbers divisible by 13: " << countl3 << '\n';
	// количество чисел, кратных 13 

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------
/*
Sample size = 39
Count of numbers divisible by 3: 13
Count of numbers divisible by 13: 6

Sample size = 3900
Count of numbers divisible by 3 : 1298
Count of numbers divisible by 13: 296

Sample size = 390000
Count of numbers divisible by 3: 129863
Count of numbers divisible by 13: 29749
*/