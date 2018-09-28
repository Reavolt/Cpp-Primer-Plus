//init.cpp -- type changes on initialization
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;     // int converted to float
    int guess(3.9832);  // double converted to int
    int debt = 7.2E12;  // result not defined in C++
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    
	std::cin.get();
	std::cin.get();
    return 0;
}
//-------------------------------------------------------------------------------------------------
/*
tree = 3.000000
guess = 3
debt = 1634811904
*/