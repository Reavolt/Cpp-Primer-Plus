//modulus.cpp -- использует операцию % для преобразования фунтов в стоуны
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	const int Lbs_per_stn = 14;
	int lbs;

	cout << "Enter your weight in pounds: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn; //Количество целых стоунов
	int pounds = lbs % Lbs_per_stn; //Остаток в фунтах
	cout << lbs << " pounds are " << stone
		 << " stone, " << pounds << " pound(s).\n";
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter your weight in pounds: 181
181 pounds are 12 stone, 13 pound(s).
*/