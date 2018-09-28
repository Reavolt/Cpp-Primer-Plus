//manyfrnd.cpp — не связанная шаблонная функция, дружественная шаблонному классу 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using std::cout;
using std::endl;

//-------------------------------------------------------------------------------------------------
template <typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T & i) : item(i) {}
	template <typename C, typename D> friend void show2(C &, D &);
};
//-------------------------------------------------------------------------------------------------
template <typename C, typename D> void show2(C & c, D & d)
{
	cout << c.item << ", " << d.item << endl;
}
//-------------------------------------------------------------------------------------------------
int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	cout << "hfi1, hfi2: ";
	show2(hfi1, hfi2);
	cout << "hfdb, hfi2: ";
	show2(hfdb, hfi2);

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
hfi1, hfi2: 10, 20
hfdb, hfi2: 10.5, 20
*/