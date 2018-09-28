//lexcast.cpp -- простое преобразование из float в string 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string> 
#include "boost/lexical_cast.hpp" 

//--------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	cout << "Enter your weight: "; // запрос на ввод веса 
	float weight;
	cin >> weight;
	string gain = "A 10% increase raises "; // увеличение веса на 10% и вывод результата 
	string wt = boost::lexical_cast<string>(weight);
	gain = gain + wt + " to "; // operator* () для строки 
	weight = 1.1 * weight;
	gain = gain + boost::lexical_cast<string>(weight) + ".";
	cout << gain << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------
/*
Enter your weight: 150
А 10% increase raises 150 to 165.
Enter your weight: 156
A 10% increase raises 156 to 171.600006.
*/