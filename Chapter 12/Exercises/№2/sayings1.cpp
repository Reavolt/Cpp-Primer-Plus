//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "strng1.h"

const int ArSize = 10;
const int MaxLen = 81;
//-------------------------------------------------------------------------------------------------
int main()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: "; // ввод имени 
	String s3;
	
	std::cout << s2; 			 // перегруженная операция << 
	std::cin >> s3; 			 // перегруженная операция >> 
	s2 = "My name is " + s3; 	 // перегруженные операции =, + 
	
	std::cout << s2 << "." << std::endl;
	s2 = s2 + s1; 
	
	s2.stringup(); 				 // преобразование строки в верхний регистр 
	
	std::cout << "The string\n" << s2 << "\ncontains " << s2.has('A');
	std::cout << " 'A' characters in it." << std::endl;
	std::cout << std::endl;
	 
	s1 = "red"; // String(const char*) , 
				// тогда String & operator= (const Strings) 
	String rgb[3] = { String(s1), String("green"), String("blue") };
	
	std::cout << "Enter the name of a primary color for mixing light: "; // ввод цвета 
	
	String ans;
	bool success = false;
	
	while (std::cin >> ans)
	{
		ans.stringlow(); 				// преобразование строки в нижний регистр 
		for (size_t i = 0; i < 3; i++)
		{
			if (ans == rgb[i]) 			// перегруженная операция == 
			{
				std::cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
		{
			break;
		}
		else
		{
			std::cout << "Try again! \n";
		}
	}
	std::cout << "Bye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------