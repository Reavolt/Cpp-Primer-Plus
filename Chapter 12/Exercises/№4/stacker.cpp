//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "stack.h"

//-------------------------------------------------------------------------------------------------
inline void printStack(Stack s) { std::cout << s; }
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;

	std::cout << "setting s1..." << std::endl;
	Stack s1;
	std::cout << "setting s2..." << std::endl;
	Stack s2(5);
	std::cout << "setting s3..." << std::endl;
	Stack s3(-1);
	std::cout << "setting s4..." << std::endl;
	Stack s4 = Stack(10);
	std::cout << "setting s5..." << std::endl;
	Stack s5(s4);
	std::cout << "setting s6..." << std::endl;
	Stack s6 = Stack(s3);
	std::cout << std::endl;
	
	std::cout << "s1.isempty() == " << s1.isempty() << std::endl;
	s1.push(10);
	s1.push(20);
	s1.push(30);

	s2 = s1;
	
	unsigned long int x = 0;
	s2.pop(x);
	
	std::cout << "We pushed 10, 20, and 30 into s1" << std::endl;
	std::cout << "We assigned s2 to s1" << std::endl;
	std::cout << "s2.pop(x), x = " << x << std::endl;
	std::cout << std::endl;
	
	std::cout << "s1: " << std::endl;
	std::cout << std::endl;
	printStack(s1);
	std::cout << "s2: " << std::endl << s2;
	std::cout << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------