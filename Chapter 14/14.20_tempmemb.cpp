//tempmemb.срр - шаблоны-члены 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

using std::cout;
using std::endl;

//-------------------------------------------------------------------------------------------------
template <typename T>
class beta
{
private:
	template <typename V> // вложенный член класса шаблона
	class hold
	{
	private:
		V val;
	public:
		hold(V v = 0) : val(v) {}
		void show() const { cout << val << endl; }
		V Value() const { return val; }
	};
	hold<T> q;             // шаблонный объект
	hold<int> n;           // шаблонный объект
public:
	beta(T t, int i) : q(t), n(i) {}
	template<typename U>   // шаблонный метод
	U blab(U u, T t) { return (n.Value() + q.Value()) * u / t; }
	void Show() const { q.show(); n.show(); }
};
//-------------------------------------------------------------------------------------------------
int main()
{
	beta<double> guy(3.5, 3);
	cout << "T was set to double\n";
	guy.Show();
	cout << "V was set to T, which is double, then V was set to int\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U was set to int\n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U was set to double\n";
	cout << "Done\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
T was set to double
3.5
3
V was set to T, which is double, then V was set to int
28
U was set to int
28.2609
U was set to double
Done
*/