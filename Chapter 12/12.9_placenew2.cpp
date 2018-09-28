// placenew2.срр -- операции new, new с размещением, но без delete 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string> 
#include <new> 

using namespace std;

const int BUF = 512;
//-------------------------------------------------------------------------------------------------
class JustTesting
{
private:
	string words;
	int number;
public:
	JustTesting(const string & s = "Just Testing", int n = 0)
	{
		words = s; number = n; cout << words << " constructed\n";
	}
	~JustTesting() { cout << words << " destroyed\n"; }
	void Show() const { cout << words << ", " << number << endl; }
};
//-------------------------------------------------------------------------------------------------
int main()
{
	char * buffer = new char[BUF]; // получение блока памяти 
	JustTesting *pc1, *pc2;
	pc1 = new (buffer) JustTesting; // размещение объекта в buffer 
	pc2 = new JustTesting("Heapl", 20); // размещение объекта в куче 
	cout << "Memory block addresses:\n" << "buffer: "
		 << (void *) buffer << " heap: " << pc2 << endl; // вывод адресов памяти 
	cout << "Memory contents:\n"; // вывод содержимого памяти 
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();
	JustTesting *pc3, *pc4;
	// Фиксация ячейки, с которой работает new с размещением 
	pc3 = new (buffer + sizeof(JustTesting))
		JustTesting("Better Idea", 6);
	pc4 = new JustTesting("Heap2", 10);
	cout << "Memory contents:\n"; // вывод содержимого памяти 
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();
	delete pc2; // освобождение Heapl 
	delete pc4; // освобождение Неар2 
				// Явное уничтожение объектов, созданных new с размещением 
	pc3->~JustTesting(); // уничтожение объекта, на который указывает рсЗ 
	pc1->~JustTesting(); // уничтожение объекта, на который указывает pel 
	delete[] buffer; // освобождение buffer 
	cout << "Done\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Just Testing constructed
Heapl constructed
Memory block addresses:
buffer: 005DE8E8 heap: 005D6140
Memory contents:
005DE8E8: Just Testing, 0
005D6140: Heapl, 20
Better Idea constructed
Heap2 constructed
Memory contents:
005DE908: Better Idea, 6
005DEB18: Heap2, 10
Heapl destroyed
Heap2 destroyed
Better Idea destroyed
Just Testing destroyed
Done
Для продолжения нажмите любую клавишу . . .
*/