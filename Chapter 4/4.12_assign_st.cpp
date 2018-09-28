//assign_st.срр -- присваивание структур 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
//-------------------------------------------------------------------------------------------------
int main() 
{
	inflatable bouquet =
	{
		"sunflowers",
		0.20,
		12.49
	};

	inflatable choice;
	cout << "bouquet: " << bouquet.name << " for $";
	cout << bouquet.price << endl;
	choice = bouquet; // присваивание одной структуры другой 
	cout << "choice: " << choice.name << " for $";
	cout << choice.price << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
bouquet: sunflowers for $12.49
choice: sunflowers for $12.49
*/