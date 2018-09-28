//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cctype>

//----------------------------------------------------------------------------------------------------
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
//----------------------------------------------------------------------------------------------------
void print_box(const box details);
void set_volume(box* address);
//----------------------------------------------------------------------------------------------------
int main()
{
	box details;
	cout << "Enter maker - ";
	cin.get(details.maker, 40);
	
	while (std::cin.get() != '\n')
	{
		continue;
	}
	
	std::cout << "Enter height - ";
	std::cin >> details.height;
	std::cout << "Enter width - ";
	std::cin >> details.width;
	std::cout << "Enter length - ";
	std::cin >> details.length;

	set_volume(&details);
	print_box(details);

	std::cin.get();
	std::cin.get();
	return 0;
}
//----------------------------------------------------------------------------------------------------
void print_box(const box details) 
{
	 std::cout << std::endl;
	 std::cout << "maker - " << details.maker << std::endl;
	 std::cout << "height - " << details.height << std::endl;
	 std::cout << "width - " << details.width << std::endl;
	 std::cout << "length - " << details.length << std::endl;
	 std::cout << "volume - " << details.volume << std::endl;
}
//----------------------------------------------------------------------------------------------------
void set_volume(box* address) 
{
	 address->volume = address->height + address->length + address->width;
}
//----------------------------------------------------------------------------------------------------