//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

//--------------------------------------------------------------------------------------------------
class Store
{
private:
	std::ofstream* pfout;
public:
	Store(std::ofstream & fout) { pfout = &fout; }
	~Store() {}
	Store & operator()(const std::string & str)
	{
		size_t len = str.length();
		pfout->write((char*)&len, sizeof(size_t));
		pfout->write(str.data(), len);
		return *this;
	}
};
//--------------------------------------------------------------------------------------------------
void ShowStr(const std::string & str);
void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr);
//--------------------------------------------------------------------------------------------------
int main()
{
	std::vector<std::string> vostr;
	std::string temp;

	// Получить строки 
	std::cout << "Enter strings (empty line to quit) :\n"; // запрос на ввод строк 
	while (getline(std::cin, temp) && temp[0] != '\0')
	{
		vostr.push_back(temp);
	}

	std::cout << "Here is your input. \n"; // вывод введенных строк 
	for_each(vostr.begin(), vostr.end(), ShowStr);

	// Сохранить в файле 
	std::ofstream fout("strings.dat", std::ios_base::out | std::ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	// Восстановить содержимое файла 
	std::vector<std::string> vistr;
	std::ifstream fin("strings.dat", std::ios_base::in | std::ios_base::binary);
	if (!fin.is_open())
	{
		std::cerr << "Could not open file for input. \n";
		//не удается открыть файл для ввода 
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	std::cout << "\nHere are the strings read from the file:\n";

	// строки, прочитанные из файла 
	for_each(vistr.begin(), vistr.end(), ShowStr);

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------
void ShowStr(const std::string & str)
{
	std::cout << str << std::endl;
}
//--------------------------------------------------------------------------------------------------
void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr)
{
	size_t len = 0;
	std::string str;
	char ch;

	// убедитесь, что есть что прочитать
	while (fin.peek() && !fin.eof())
	{
		fin.read((char*)&len, sizeof(size_t));
		for (size_t i = 0; i < len; i++)
		{
			fin.read(&ch, sizeof(char));
			str.push_back(ch);
		}
		vistr.push_back(str);
		str.clear();
	}
}
//--------------------------------------------------------------------------------------------------