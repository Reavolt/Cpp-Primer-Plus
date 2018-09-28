//realwrld.cpp
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	
#include <cstdio>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	cout << "This system can generate up to " << TMP_MAX
		<< " temporary names of up to " << L_tmpnam
		<< " characters.\n";
	char pszName[L_tmpnam] = { '\0' };
	cout << "Here are ten names:\n";
	for (int i = 0; 10 > i; i++)
	{
		tmpnam(pszName);
		cout << pszName << endl;
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
This system can generate up to 2147483647 temporary names of up to 260 characters.
Here are ten names:
C:\Users\*\AppData\Local\Temp\s858.0
C:\Users\*\AppData\Local\Temp\s858.1
C:\Users\*\AppData\Local\Temp\s858.2
C:\Users\*\AppData\Local\Temp\s858.3
C:\Users\*\AppData\Local\Temp\s858.4
C:\Users\*\AppData\Local\Temp\s858.5
C:\Users\*\AppData\Local\Temp\s858.6
C:\Users\*\AppData\Local\Temp\s858.7
C:\Users\*\AppData\Local\Temp\s858.8
C:\Users\*\AppData\Local\Temp\s858.9
*/