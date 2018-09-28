#ifndef CD_H_     
#define CD_H_     
#include <iostream> 
#include <cstring>

//-------------------------------------------------------------------------------------------------
// Базовый класс 
class Cd 
{ // представляет компакт-диск 
private:
	char* performers;
	char* label;
	int selections; // количество сборников 
	double playtime; // время воспроизведения в минутах 
public:
	Cd();
	Cd(const char* perf, const char* leb, int sel, double playt);
	Cd(const Cd & d);
	virtual ~Cd();
	virtual void Report() const; // выводит все данные о компакт-диске 
	Cd & operator = (const Cd & d);
};
//-------------------------------------------------------------------------------------------------
class Classic : public Cd
{
private:
	char* cdname;
public:
	Classic();
	Classic(const char* name, Cd & cd);
	Classic(const char* name, const char* perf, const char* leb, int sel, double playt);
	Classic(const Classic & c);
	~Classic();
	virtual void Report() const; // выводит все данные о компакт-диске
	Classic & operator = (const Classic & c);
};
//-------------------------------------------------------------------------------------------------
#endif //CD_H_