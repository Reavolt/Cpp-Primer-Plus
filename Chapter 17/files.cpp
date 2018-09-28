//files.cpp -- сохранение в файл
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	 // не требуется для многих систем
#include <fstream>
#include <string>
#include <sstream>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	string filename = "file";

	// создать выходной поток объекта для нового файла и называть его fout
	int i;
	for (i = 0; i < 140; i++)
	{
		ostringstream outstr;   // управляет потоком строк
		outstr << filename << i;
		string fname = outstr.str();
		ofstream fout(fname.c_str());
		if (!fout.is_open())
			break;
		fout << "For your eyes only!\n";        // написать в файл
		fout.close();           // закрыть файл
		fout.clear();
	}
	cout << "i: " << i << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
i: 140
//Создает 140 файлов.
*/