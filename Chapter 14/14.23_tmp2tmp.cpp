//tmp2tmp.cpp -- шаблонные друзья для шаблонного класса 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using std::cout;
using std::endl;

//-------------------------------------------------------------------------------------------------
// Прототипы шаблонов 
template <typename T> void counts();
template <typename T> void report(T &);
//-------------------------------------------------------------------------------------------------
// Шаблонный класс 
template <typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT & i) : item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void counts<TT>();
	friend void report<>(HasFriendT<TT> &);
};
//-------------------------------------------------------------------------------------------------
template <typename T>
int HasFriendT<T>::ct = 0;
//-------------------------------------------------------------------------------------------------
// Определения дружественных функций для шаблона 
template <typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriendT<T>) << "; ";	// размер шаблона 
	cout << "template counts(): " << HasFriendT<T>::ct << endl;	// counts() из шаблона 
}
//-------------------------------------------------------------------------------------------------
template <typename T>
void report(T & hf)
{
	cout << hf.item << endl;
}
//-------------------------------------------------------------------------------------------------
int main()
{
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);
	report(hfi1);  // генерирует report(HasFriendT<int> &) 
	report(hfi2);  // генерирует report(HasFriendT<int> &) 
	report(hfdb);  // генерирует report(HasFriendT<double> &) 
	cout << "counts<int>() output:\n";	// вывод из counts<int> () 
	counts<int>();
	cout << "counts<double>() output:\n";	// вывод из counts<double> () 
	counts<double>();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
template size: 4; template counts(): 0
10
20
10.5
counts<int>() output:
template size: 4; template counts(): 2
counts<double>() output:
template size: 8; template counts(): 1
*/