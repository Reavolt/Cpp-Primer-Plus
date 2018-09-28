//frnd2tmp.cpp — шаблонный класс с нешаблонными друзьями 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using std::cout;
using std::endl;

//-------------------------------------------------------------------------------------------------
template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i) : item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts();
	friend void reports(HasFriend<T> &); // параметр шаблона
};
//-------------------------------------------------------------------------------------------------
// Каждая специализация имеет собственный статический член данных 
template <typename T>
int HasFriend<T>::ct = 0;
//-------------------------------------------------------------------------------------------------
// Нешаблонный друг для всех классов HasFriend<T> 
void counts()
{
	cout << "int count: " << HasFriend<int>::ct << "; ";
	cout << "double count: " << HasFriend<double>::ct << endl;
}
//-------------------------------------------------------------------------------------------------
// Нешаблонный друг для класса HasFriend<int> 
void reports(HasFriend<int> & hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}
//-------------------------------------------------------------------------------------------------
// Нешаблонный друг для класса HasFriend<double> 
void reports(HasFriend<double> & hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}
//-------------------------------------------------------------------------------------------------
int main()
{
	cout << "No objects declared: ";	// объекты пока не объявлены 
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared: ";	// объекты пока не объявлены hfi1
	counts();
	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared: ";	// после объявления hfi2 
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "After hfdb declared: ";	// после объявления hfdb 
	counts();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
No objects declared: int count: 0; double count: 0
After hfi1 declared: int count: 1; double count: 0
After hfi2 declared: int count: 2; double count: 0
After hfdb declared: int count: 2; double count: 1
HasFriend<int>: 10
HasFriend<int>: 20
HasFriend<double>: 10.5
*/