//valvect.cpp -- сравнение vector и valarray 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	vector<double> data;
	double temp;

	cout << "Enter numbers (<=0 to quit):\n";	// запрос на ввод положительных чисел 
	while (cin >> temp && temp > 0)
		data.push_back(temp);
	sort(data.begin(), data.end());
	int size = data.size();
	valarray<double> numbers(size);
	int i;
	for (i = 0; i < size; i++)
		numbers[i] = data[i];
	valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);
	valarray<double> results(size);
	results = numbers + 2.0 * sq_rts;
	cout.setf(ios_base::fixed);
	cout.precision(4);
	for (i = 0; i < size; i++)
	{
		cout.width(8);
		cout << numbers[i] << ": ";
		cout.width(8);
		cout << results[i] << endl;
	}
	cout << "done\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter numbers (<=0 to quit):
3.3 1.8 5.2 10 14.4 21.6 26.9 0
1.8000:   4.4833
3.3000:   6.9332
5.2000:   9.7607
10.0000:  16.3246
14.4000:  21.9895
21.6000:  30.8952
26.9000:  37.2730
done
*/