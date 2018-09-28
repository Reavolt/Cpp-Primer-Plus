// tabtenn0.h — базовый класс для клуба по настольному теннису 
#ifndef TABTENNO_H_  
#define TABTENNO_H_  

//-------------------------------------------------------------------------------------------------
#include <string> 
using std::string;
// Простой базовый класс 
class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string & fn = "none",
		const string & In = "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return hasTable; };
	void ResetTable(bool v) { hasTable = v; };
};
//-------------------------------------------------------------------------------------------------
#endif //TABTENNO_H_