//newplace.cpp -- использование операции new с размещением 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <new> // для операции new с размещением 

using namespace std;

const int BUF = 512;
const int N = 5;
char buffer[BUF]; // блок памяти 
//-------------------------------------------------------------------------------------------------
int main() 
{
	double *pdl, *pd2;
	int i;

	// Вызов обычной и операции new с размещением 
	cout << "Calling new and placement new:\n";
	pdl = new double[N]; // использование кучи 
	pd2 = new (buffer) double[N]; // использование массива buffer 
	for (i = 0; i < N; i++)
		pd2[i] = pdl[i] = 1000 + 20.0 * i;
	cout << "Memory addresses: \n" << "heap: " << pdl
		 << " static: " << (void *) buffer << endl;// вывод адресов памяти 
	cout << "Memory contents:\n"; // вывод содержимого памяти 
	for (i = 0; i < N; i++)
	{
		cout << pdl[i] << " at " << &pdl[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}

	// Вызов обычной и операции new с размещением во второй раз 
	cout << "\nCalling new and placement new a second time:\n";
	double *pd3, *pd4;
	pd3 = new double[N]; // нахождение нового адреса 
	pd4 = new (buffer) double[N]; // перезаписывание старых данных 
	for (i = 0; i < N; i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << "; ";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}

	// Вызов обычной и операции new с размещением в третий раз 
	cout << "\nCalling new and placement new a third time:\n";
	delete[] pdl;
	pdl = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++)
		pd2[i] = pdl[i] = 1000 + 60.0 * i;
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pdl[i] << " at " << &pdl[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	delete[] pdl;
	delete[] pd3;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Calling new and placement new:
Memory addresses:
heap: 001EC5E0 static: 013DC2E0
Memory contents:
1000 at 001EC5E0; 1000 at 013DC2E0
1020 at 001EC5E8; 1020 at 013DC2E8
1040 at 001EC5F0; 1040 at 013DC2F0
1060 at 001EC5F8; 1060 at 013DC2F8
1080 at 001EC600; 1080 at 013DC300

Calling new and placement new a second time:
Memory contents:
1000 at 001FDD60; 1000 at 013DC2E0
1040 at 001FDD68; 1040 at 013DC2E8
1080 at 001FDD70; 1080 at 013DC2F0
1120 at 001FDD78; 1120 at 013DC2F8
1160 at 001FDD80; 1160 at 013DC300

Calling new and placement new a third time:
Memory contents:
1000 at 001FD838; 1000 at 013DC308
1060 at 001FD840; 1060 at 013DC310
1120 at 001FD848; 1120 at 013DC318
1180 at 001FD850; 1180 at 013DC320
1240 at 001FD858; 1240 at 013DC328
*/