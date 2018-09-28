//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "tv.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	Tv tv;
	Remote remote;

	tv.onoff();
	std::cout << "Here are our original settings: " << std::endl;
	tv.settings();
	remote.settings();
	std::cout << std::endl;

	tv.toggleRemoteMode(remote);
	std::cout << "These are our new settings:" << std::endl;
	tv.settings();
	remote.settings();
	std::cout << std::endl;

	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();	
    return 0; 
}
//-------------------------------------------------------------------------------------------------