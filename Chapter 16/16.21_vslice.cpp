//vslice.срр -- Для использование срезов valarray 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <valarray>
#include <cstdlib>

const int SIZE = 12;
typedef std::valarray<int> vint;  // для упрощени¤ объявлений 
//-------------------------------------------------------------------------------------------------
void show(const vint & v, int cols);
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::slice;                // из <valarray> 
	using std::cout;
	vint valint(SIZE);               // представл¤ет 4 строки по 3 элемента 

	int i;
	for (i = 0; i < SIZE; ++i)
		valint[i] = std::rand() % 10;
	cout << "Original array:\n";	// исходный массив
	show(valint, 3);                 // отображение в виде 3 столбцов 
	vint vcol(valint[slice(1, 4, 3)]); // отображение в виде 3 столбцов 
	cout << "Second column:\n";
	show(vcol, 1);                  // отображение в 1 столбце 
	vint vrow(valint[slice(3, 3, 1)]); // извлечение 2-ой строки 
	cout << "Second row:\n";
	show(vrow, 3);
	valint[slice(2, 4, 3)] = 10;      // присваивание 2-му столбцу 
	cout << "Set last column to 10:\n";
	show(valint, 3);
	cout << "Set first column to sum of next two:\n";
	// операции + не определена для slice, поэтому преобразуем в valarray<int>
	valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)])
		+ vint(valint[slice(2, 4, 3)]);
	show(valint, 3);

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void show(const vint & v, int cols)
{
	using std::cout;
	using std::endl;

	int lim = v.size();
	for (int i = 0; i < lim; ++i)
	{
		cout.width(3);
		cout << v[i];
		if (i % cols == cols - 1)
			cout << endl;
		else
			cout << ' ';
	}
	if (lim % cols != 0)
		cout << endl;
}
//-------------------------------------------------------------------------------------------------
/*
Original array:
1   7   4
0   9   4
8   8   2
4   5   5
Second column:
7
9
8
5
Second row:
0   9   4
Set last column to 10:
1   7  10
0   9  10
8   8  10
4   5  10
Set first column to sum of next two:
17   7  10
19   9  10
18   8  10
15   5  10
*/