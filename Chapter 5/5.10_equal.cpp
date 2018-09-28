//equal.срр -- равенство или присваивание
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int quizscores[10] =
	{ 20, 20, 20, 20, 20, 19, 20, 18, 20, 20 };
	cout << "Doing it right:\n"; // правильно 
	int i;
	for (i = 0; quizscores[i] == 20; i++)
		 cout << "quiz " << i << " is a 20\n";
	// Предупреждение: возможно, лучше почитать об этой программе, 
	// чем в действительности запускать ее. 
	cout << "Doing it dangerously wrong:\n"; // неправильно 
	for (i = 0; quizscores[i] = 20; i++)
		 cout << "quiz " << i << " is a 20\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Doing it right:
quiz 0 is a 20
quiz 1 is a 20
quiz 2 is a 20
quiz 3 is a 20
quiz 4 is a 20
Doing it dangerously wrong:
quiz 0 is a 20
quiz 1 is a 20
quiz 2 is a 20
quiz 3 is a 20
quiz 4 is a 20
quiz 5 is a 20
quiz 6 is a 20
quiz 7 is a 20
quiz 8 is a 20
quiz 9 is a 20
quiz 10 is a 20
quiz 11 is a 20
quiz. 12 is a 20
quiz 13 is a 20
...
*/