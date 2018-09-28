//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "cd.h"

//-------------------------------------------------------------------------------------------------
void Bravo(const Cd & disk);
//-------------------------------------------------------------------------------------------------
int main()
{
	Cd cl("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano sonata in b flat, Fantasia in C", "Alfred Brendel", "Phillips", 2, 57.17);
	Cd* pcd = &cl;
	
	// Непосредственное использование объектов 
	std::cout << "Using object directly: " << std::endl;
	std::cout << std::endl;
	cl.Report(); // использование метода Cd 
	c2.Report(); // использование метода Classic 
				 // Использование указателя на объекты типа cd* 
	
	std::cout << "Using type cd* pointer to objects: " << std::endl;;
	std::cout << std::endl;
	pcd->Report(); // использование метода Cd для объекта cd 
	pcd = &c2;
	pcd->Report(); // использование метода Classic для объекта classic 
	
	// Вызов функции с аргументом-ссылкой на Cd 
	std::cout << "Calling a function with a Cd reference argument: " << std::endl;;
	std::cout << std::endl;
	Bravo(cl);
	Bravo(c2);
	
	// Тестирование присваивания 
	std::cout << "Testing assignment: " << std::endl;
	Classic copy;
	copy = c2;
	copy.Report();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void Bravo(const Cd & disk)
{
	disk.Report();
}
//-------------------------------------------------------------------------------------------------