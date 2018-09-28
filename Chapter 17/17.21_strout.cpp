//strout.cpp -- внутреннее форматирование (вывод) 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	
#include <sstream>
#include <string>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	ostringstream outstr;  // управляет строковым потоком 

	string hdisk;
	cout << "What's the name of your hard disk? ";
	getline(cin, hdisk);
	int cap;
	cout << "What's its capacity in GB? ";
	cin >> cap;
	// Запись форматированной информации в строковый поток 
	outstr << "The hard disk " << hdisk << " has a capacity of "
		<< cap << " gigabytes.\n";
	string result = outstr.str();  // сохранение результата 
	cout << result;                // отображение содержимого 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
What's the name of your hard disk? Datarapture
What's its capacity in GB? 2000
The hard disk Datarapture has a capacity of 2000 gigabytes.
*/