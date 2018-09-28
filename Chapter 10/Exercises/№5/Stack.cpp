//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include "Stack_class.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	Stack st; // создание пустого стека 
	char ch;
	customer po;
	double subtotal = 0.0;

	std::cout << "Type A to add the client,\n";
	std::cout << "P to delete the client, and Q to exit.\n";

	while (std::cin >> ch && toupper(ch) != 'Q')
	{
		while (std::cin.get() != '\n')
		{
			continue;
		}
		
		if (!isalpha(ch))
		{
			std::cout << '\a';
			continue;
		}
		
		switch (ch)
		{
		case 'A':
		case 'a': 
			std::cout << "Введите имя клиента: "; // запрос номера заказа 
			std::cin.getline(po.fullname, 35);
			std::cout << "Введите сумму платеджа: "; // запрос номера заказа 
			(std::cin >> po.payment).get();
			
			if (st.isfull())
			{
				std::cout << "Stack full\n"; // стек уже полон 
			}
			else
			{
				st.push(po);
			}
			break;
		case 'P':
		case 'p': 
			if (st.isempty())
			{
				std::cout << "Stack is empty\n";
			}
			else 
			{
				subtotal += po.payment;
				st.pop(po);
				std::cout << "Client " << po.fullname << " was deleted\n"; // заказ вытолкнут 
			}
			break;
		}
		std::cout << std::endl;
		std::cout << "Type A to add the client,\n";
		std::cout << "P to delete the client, and Q to exit.\n";
	}
	std::cout << "See you later.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------