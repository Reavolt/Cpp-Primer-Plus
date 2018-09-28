//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "Complex0.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	Complex a(3.0, 4.0); // инициализация значением (3,4і) 
	Complex c;
	
	std::cout << "Enter a complex number (q to quit) :\n";
	// Ввод комплексного числа (q для завершения)
	
	while (std::cin >> c)
	{
		std::cout << "с is " << c << '\n'; // значение с 
		std::cout << "complex conjugate is " << ~c << '\n';
		// значение сопряженного числа 
		
		std::cout << "a is " << a << '\n';
		std::cout << "a + с is " << a + c << '\n'; // значение а + с 
		std::cout << "a — с is " << a - c << '\n'; // значение а — с 
		std::cout << "a * с is " << a * c << '\n'; // значение а * с 
		std::cout << "2 * с is " << 2 * c << '\n'; // значение 2 * с 
		std::cout << "Enter a complex number (q to quit) :\n";
	}
	std::cout << "Done!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------