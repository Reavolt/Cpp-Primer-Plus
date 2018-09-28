//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//--------------------------------------------------------------------------------------------------
class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv &&mv);
	~Cpmv();

	Cpmv & operator = (const Cpmv & cp);
	Cpmv & operator = (Cpmv && mv);
	Cpmv operator + (const Cpmv & obj) const;
	void Display() const;
};
//--------------------------------------------------------------------------------------------------
Cpmv::Cpmv()
{
	pi = new Info;
	std::cout << "Default ctor\n";
	std::cout << "Address " << (void*)pi << std::endl << std::endl;
}
//--------------------------------------------------------------------------------------------------
Cpmv::Cpmv(std::string q, std::string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	std::cout << "q and z constructor called\n";
	std::cout << "Address " << (void*)pi << std::endl << std::endl;
}
//--------------------------------------------------------------------------------------------------
Cpmv::Cpmv(const Cpmv & cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	std::cout << "Copy constructor called\n";
	std::cout << "Address " << (void*)pi << std::endl << std::endl;
}
//--------------------------------------------------------------------------------------------------
Cpmv::Cpmv(Cpmv && mv)
{
	pi = new Info;
	pi = mv.pi;
	mv.pi = nullptr;
	std::cout << "Move constructor called\n";
	std::cout << "Address " << (void*)pi << std::endl << std::endl;
}
//--------------------------------------------------------------------------------------------------
Cpmv Cpmv::operator + (const Cpmv & obj) const
{
	std::cout << "Entering operator +()\n";
	Cpmv temp;
	temp.pi->qcode = pi->qcode + obj.pi->qcode;
	temp.pi->zcode = pi->zcode + obj.pi->zcode;

	std::cout << "Leaving operator+()\n";
	return temp;
}
//--------------------------------------------------------------------------------------------------
Cpmv & Cpmv::operator = (const Cpmv & cp)
{
	std::cout << "Entering operator=(const Cpmv & cp)\n";
	
	if (this == &cp)
	{
		return *this;
	}
	
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;

	std::cout << "Leaving operator=()\n";
	return *this;
}
//--------------------------------------------------------------------------------------------------
Cpmv & Cpmv::operator = (Cpmv && mv)
{
	std::cout << "Entering operator=(Cpmv && mv)\n";

	if (this == &mv)
	{
		return *this;
	}
	
	delete pi;
	pi = mv.pi;
	mv.pi = nullptr;
	
	std::cout << "Address " << (void*)pi << std::endl << std::endl;
	return *this;
}
//--------------------------------------------------------------------------------------------------
Cpmv::~Cpmv()
{
	std::cout << "Destructor called\n";
	std::cout << "Address " << (void*)pi << std::endl << std::endl;

	delete pi;
}
//--------------------------------------------------------------------------------------------------
void Cpmv::Display() const
{
	if (pi == nullptr)
	{
		std::cout << "Empty object\n";
	}
	else
	{
		std::cout << " " << pi->qcode << ", ";
		std::cout << pi->zcode << std::endl;
	}
}
//--------------------------------------------------------------------------------------------------
int main()
{
	{
		Cpmv one("Hi ", "Sunny");
		Cpmv two = one;

		Cpmv three("Hello", "World!");
		Cpmv four(one + three);

		Cpmv five;
		five = one;

		Cpmv six;
		six = five + three;

		std::cout << "\nobject 1";
		one.Display();

		std::cout << "\nobject 2";
		two.Display();

		std::cout << "\nobject 3";
		three.Display();

		std::cout << "\nobject 4";
		four.Display();

		std::cout << "\nobject 5";
		five.Display();

		std::cout << "\nobject 6";
		six.Display();
	}
	std::cout << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------