//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <string>

//-------------------------------------------------------------------------------------------------
void check(std::ifstream & infile, std::string filename);
void check(std::ofstream & infile, std::string filename);
bool stringComp(std::string s1, std::string s2); 
bool stringEqual(std::string s1, std::string s2);
//-------------------------------------------------------------------------------------------------
int main()
{
	std::ifstream patfile("pat.dat");
	std::ifstream matfile("mat.dat");
	std::ofstream patnmat("matnpat.dat");
	
	check(patfile, "pat.dat");
	check(matfile, "mat.dat");
	check(patnmat, "matnpat.dat");
	
	std::string name;
	std::vector<std::string> patlist;
	std::vector<std::string> matlist;

	while (getline(patfile, name) && name != "")
	{
		patlist.push_back(name);
	}
	
	while (getline(matfile, name) && name != "")
	{
		matlist.push_back(name);
	}

	std::vector<std::string> matnpat_list;
	std::back_insert_iterator<std::vector<std::string>> iiter(matnpat_list);
	
	copy(patlist.begin(), patlist.end(), iiter);
	copy(matlist.begin(), matlist.end(), iiter);
	
	sort(matnpat_list.begin(), matnpat_list.end(), stringComp);
	std::vector<std::string>::iterator iv = unique(matnpat_list.begin(), matnpat_list.end(), stringEqual);
	matnpat_list.erase(iv, matnpat_list.end());
	
	std::ostream_iterator<std::string> os_iter(std::cout, "\n");
	std::ostream_iterator<std::string> os_iter_file(patnmat, "\n");

	std::cout << "Here is your list of guests: " << std::endl;
	copy(matnpat_list.begin(), matnpat_list.end(), os_iter);

	patnmat << "Here is your list of guests: " << std::endl;
	copy(matnpat_list.begin(), matnpat_list.end(), os_iter_file);

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void check(std::ifstream & infile, std::string filename)
{
	if (!infile.is_open())
	{
		std::cerr << "Error, cannot open " << filename << std::endl;
		exit(EXIT_FAILURE);
	}
}
//-------------------------------------------------------------------------------------------------
void check(std::ofstream & infile, std::string filename)
{
	if (!infile.is_open())
	{
		std::cerr << "Error, cannot open " << filename << std::endl;
		exit(EXIT_FAILURE);
	}
}
//-------------------------------------------------------------------------------------------------
bool stringComp(std::string s1, std::string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}
//-------------------------------------------------------------------------------------------------
bool stringEqual(std::string s1, std::string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 == s2;
}
//-------------------------------------------------------------------------------------------------