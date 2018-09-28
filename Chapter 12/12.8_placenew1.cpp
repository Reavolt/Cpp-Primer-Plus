// placenew1.срр -- операции new, new с размещением, но без delete 
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
	pc3 = new (buffer) JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);
	cout << "Memory contents : \n"; // вывод содержимого памяти 
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << " : ";
	pc4->Show();
	delete pc2; // освобождение Heapl 
	delete pc4; // освобождение Неар2 
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
buffer: 0328CA20 heap: 0328CC50
Memory contents:
0328CA20: Just Testing, 0
0328CC50: Heapl, 20
Bad Idea constructed
Heap2 constructed
Memory contents :
0328CA20: Bad Idea, 6
03284AC8 : Heap2, 10
Heapl destroyed
Heap2 destroyed
Done
Для продолжения нажмите любую клавишу . . .
*/