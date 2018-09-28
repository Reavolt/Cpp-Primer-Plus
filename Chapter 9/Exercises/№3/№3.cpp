//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <new>

const int STRUCTSIZE = 2;
const int BUFFSIZE = 512;
char buffer[BUFFSIZE];
//-------------------------------------------------------------------------------------------------
struct chaff
{
	char dross[20];
	int slag;
};
//-------------------------------------------------------------------------------------------------
void show_chaff(const chaff & chf);
void set_chaff(chaff & chf, const char* name, int qlty);
//-------------------------------------------------------------------------------------------------
int main()
{
	chaff* pchaff = new (buffer) chaff[STRUCTSIZE];
	char name[100];
	int quantity = 0;

	for (size_t i = 0; i < STRUCTSIZE; i++)
	{
		std::cout << "Enter name: ";
		std::cin.get(name, 100);
		std::cout << "Enter the quantity: ";
		(std::cin >> quantity).get();
		set_chaff(pchaff[i], name, quantity);
	}

	for (size_t i = 0; i < STRUCTSIZE; i++)
	{
		std::cout << "Структура: " << i + 1 << std::endl;
		show_chaff(pchaff[i]);
	}
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void show_chaff(const chaff & chf) 
{
	std::cout << "Значение 1: " << chf.dross << std::endl;
	std::cout << "Значение 2: " << chf.slag << std::endl;
}
//-------------------------------------------------------------------------------------------------
void set_chaff(chaff & chf, const char* name, int qlty)
{
	strcpy(chf.dross, name);
	chf.slag = qlty;
}
//-------------------------------------------------------------------------------------------------