//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "workermi.h"
#include "QueueTp.h"

const int SIZE = 5;
//-------------------------------------------------------------------------------------------------
int main()
{
	QueueTp<Worker*> q;
	Worker* pw;

	for (int ct = 0; ct < SIZE; ct++)
	{
		std::cout << "Enter the employee category:\n";
		std::cout << "w: waiter  s: singer  ";
		std::cout << "t: singing waiter  q: quit\n";
		
		char choice = 0;
		std::cin >> choice;
		
		while (std::strchr("wstq", choice) == NULL)
		{
			std::cout << "Please enter a w, s, t, or q: ";
			std::cin >> choice;
		}
		
		if (choice == 'q')
		{
			break;
		}
		
		switch (choice)
		{
			case 'w':   pw = new Waiter;
				break;
			case 's':   pw = new Singer;
				break;
			case 't':   pw = new SingingWaiter;
				break;
		}
		std::cin.get();
		pw->Set();
		q.enqueue(pw);
	}

	std::cout << "\nHere is your staff:\n";

	for (int i = 0; i < ct; i++)
	{
		std::cout << endl;
		q.dequeue(pw);
		pw->Show();
		delete pw;
	}
	std::cout << "Bye." std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------