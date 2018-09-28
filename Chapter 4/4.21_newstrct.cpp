//newstrct.cpp -- использование new со структурой 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream> 

using namespace std;

//-------------------------------------------------------------------------------------------------
struct inflatable // определение структуры 
{
	char name[20];
	float volume;
	double price;
};
//-------------------------------------------------------------------------------------------------
int main()
{
	inflatable * ps = new inflatable;		   // выделение памяти для структуры 
	cout << "Enter name of inflatable item: "; // ввод имени элемента inflatable 
	cin.get(ps->name, 20);					   // первый метод для доступа к членам 
	cout << "Enter volume in cubic feet: ";	   // ввод объема в кубических футах 
	cin >> (*ps).volume;				       // второй метод для доступа к членам 
	cout << "Enter price: $";				   // ввод цены 
	cin >> ps->price;
	cout << "Name: " << (*ps).name << endl;					// второй метод
	cout << "Volume: " << ps->volume << " cubic feet\n";	// первый метод
	cout << "Price: $" << ps->price << endl;				// первый метод
	delete ps;								   // освобождение памяти, использованной структурой 

	std::cin.get();
	std::cin.get();
    return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter name of inflatable item: Fabulous Frodo
Enter volume in cubic feet: 1.4
Enter price: $27.99
Name: Fabulous Frodo
Volume: 1.4 cubic feet
Price: $27.99
*/