//multimap.срр -- использование multimap 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string> 
#include <map> 
#include <algorithm> 

//-------------------------------------------------------------------------------------------------
typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	MapCode codes;

	codes.insert(Pair(415, "San Francisco"));
	codes.insert(Pair(510, "Oakland"));
	codes.insert(Pair(718, "Brooklyn"));
	codes.insert(Pair(718, "Staten Island"));
	codes.insert(Pair(415, "San Rafael"));
	codes.insert(Pair(510, "Berkeley"));

	cout << "Number of cities with area code 415: "
		<< codes.count(415) << endl;
	cout << "Number of cities with area code 718: "
		<< codes.count(718) << endl;
	cout << "Number of cities with area code 510: "
		<< codes.count(510) << endl;
	cout << "Area Code   City\n";
	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); ++it)
		cout << "    " << (*it).first << "     "
		<< (*it).second << endl;

	pair<MapCode::iterator, MapCode::iterator>;
		auto range = codes.equal_range(718);
	cout << "Cities with area code 718:\n";
	for (it = range.first; it != range.second; ++it)
		cout << (*it).second << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Number of cities with area code 415: 2
Number of cities with area code 718: 2
Number of cities with area code 510: 2
Area Code   City
415     San Francisco
415     San Rafael
510     Oakland
510     Berkeley
718     Brooklyn
718     Staten Island
Cities with area code 718:
Brooklyn
Staten Island
Для продолжения нажмите любую клавишу . . .
*/