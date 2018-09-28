// stkoptrl.cpp — тестирование стека указателей 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstdlib>     // для rand(), srand() 
#include <ctime>       // для time() 
#include "14.15_stcktp1.h"

const int Num = 10;
//-------------------------------------------------------------------------------------------------
int main()
{
	std::srand(std::time(0)); // рандомизация rand() 
	std::cout << "Please enter stack size: "; // ввод размера стека 
	int stacksize = 0;
	std::cin >> stacksize;
	
	// Создание пустого стека размером stacksize 
	Stack<const char*> st(stacksize);

	// Входной ящик 
	const char* in[Num] = {
		" 1: Hank Gilgamesh", " 2: Kiki Ishtar",
		" 3: Betty Rocker", " 4: Ian Flagranti",
		" 5: Wolfgang Kibble", " 6: Portia Koop",
		" 7: Joy Almondo", " 8: Xaverie Paprika",
		" 9: Juan Moore", "10: Misha Mache"
	};
	
	// Выходной ящик 
	const char* out[Num];

	int processed = 0;
	int nextin = 0;

	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num)   // шансы 50 на 50 
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
		std::cout << out[i] << std::endl;

	std::cout << "Bye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Please enter stack size: 5
5: Wolfgang Kibble
4: Ian Flagranti
3: Betty Rocker
2: Kiki Ishtar
6: Portia Koop
7: Joy Almondo
1: Hank Gilgamesh
10: Misha Mache
9: Juan Moore
8: Xaverie Paprika
Bye
Для продолжения нажмите любую клавишу . . .
*/