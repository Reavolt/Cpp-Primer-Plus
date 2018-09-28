//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <ctime>
#include <random>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::vector <int> vi0(100000);
	
	for (int i = 0; i < 100000; i++)
	{
		vi0[i] = rand();
	}
	
	std::vector<int> vi = vi0;
	std::list<int> li(100000);
	copy(vi0.begin(), vi0.end(), li.begin());
	
	clock_t start = clock();
	sort(vi.begin(), vi.end());
	
	clock_t end = clock();
	std::cout << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

	start = clock();
	li.sort();
	end = clock();
	std::cout << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

	copy(vi0.begin(), vi0.end(), li.begin());
	
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	
	std::cout << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------