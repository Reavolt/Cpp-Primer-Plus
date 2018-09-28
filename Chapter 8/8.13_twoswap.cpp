//twoswap.cpp -- специализация переопределяет шаблон 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;
//-------------------------------------------------------------------------------------------------
struct job
{
	char name[40];
	double salary;
	int floor;
};
//-------------------------------------------------------------------------------------------------
template <typename T>
void Swap(T &a, T &b);
// Явная специализация 
template <> void Swap<job>(job & jl, job & j2);
void Show(job & j);
//-------------------------------------------------------------------------------------------------
int main()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << "\n";
	cout << "Using compiler-generated int swapper \n";
	Swap(i, j); // генерирует void Swap (int &, int &) 
	cout << "Now i, j = " << i << ", " << j << " \n";
	job sue = { "Susan Yaffee", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };
	cout << "Before job swapping \n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney); // использует void Swap (job &, job &) 
	cout << "After job swapping \n";
	Show(sue);
	Show(sidney);

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
void Swap(T & a, T & b) // обобщенная версия 
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
//-------------------------------------------------------------------------------------------------
// Обменивается только содержимым полей salary и floor структуры job 
template <> void Swap<job>(job &jl, job &j2) // специализация 
{
	double tl;
	int t2;
	tl = jl.salary;
	jl.salary = j2.salary;
	j2.salary = tl;
	t2 = jl.floor;
	jl.floor = j2.floor;
	j2.floor = t2;
}
//-------------------------------------------------------------------------------------------------
void Show(job &j)
{
	using namespace std;
	cout << j.name << " : $" << j.salary
		 << " on floor " << j.floor << endl;
}
//-------------------------------------------------------------------------------------------------
/*
i, j = 10, 20
Using compiler-generated int swapper
Now i, j = 20, 10
Before job swapping
Susan Yaffee : $73000.60 on floor 7
Sidney Taffee : $78060.72 on floor 9
After job swapping
Susan Yaffee : $78060.72 on floor 9
Sidney Taffee : $73000.60 on floor 7
*/