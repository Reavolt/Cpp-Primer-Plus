// strtref.cpp -- использование структурных ссылок
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
struct sysop
{
    char name[26];
    char quote[64];
    int used;
};
//-------------------------------------------------------------------------------------------------
const sysop & use(sysop & sysopref);  // функция со ссылочным типом возврата
//-------------------------------------------------------------------------------------------------
int main()
{
	//ПРИМЕЧАНИЕ. В некоторых реализациях требуется использование ключевого слова static
	// в двух объявлениях структуры для инициализации
    sysop looper =
    {
        "Rick \"Fortran\" Looper",
        "I'm a goto kind of guy.",
        0
    };

    use(looper);            // looper - это тип sysop
    cout << "Looper: " << looper.used << " use(s)\n";
    sysop copycat;
    copycat = use(looper);
    cout << "Looper: " << looper.used << " use(s)\n";
    cout << "Copycat: " << copycat.used << " use(s)\n";
    cout << "use(looper): " << use(looper).used << " use(s)\n";
	
	std::cin.get();
	std::cin.get();
    return 0;
}
//-------------------------------------------------------------------------------------------------
// use () возвращает переданную ему ссылку
const sysop & use(sysop & sysopref)
{
    cout << sysopref.name << " says:\n";
    cout << sysopref.quote << endl;
    sysopref.used++;
    return sysopref; 
}
//-------------------------------------------------------------------------------------------------	