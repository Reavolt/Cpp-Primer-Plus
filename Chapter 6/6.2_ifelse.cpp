//ifelse.срр -- использование оператора if else 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main() 
{
	char ch;
	std::cout << "Type, and I shall repeat.\n"; // запрос на ввод строки 
	std::cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
			std::cout << ch;   // выполнение в случае символа новой строки 
		else
			std::cout << ++ch; // выполнение в противном случае 
		std::cin.get(ch);
	}
	// попробуйте ch + 1 вместо ++ch, чтобы увидеть интересный эффект 
	std::cout << "\nPlease excuse the slight confusion.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Type, and I shall repeat.
An ineffable joy suffused me as I beheld
Bo!jofggbcmf!kpz!tvggvtfe!nf!bt!J!cfifme
the wonders of modern computing.
uifixpoefst!pg!npefso!dpnqvujoh
Please excuse the slight confusion.
*/