#ifndef WINE_H_
#define WINE_H_
#include "pair.h"

//-------------------------------------------------------------------------------------------------
using ArrayInt = std::valarray<int>;
using PairArray = std::pair<ArrayInt, ArrayInt>;
//-------------------------------------------------------------------------------------------------
class Wine : private std::string, private PairArray
{
private: 
	int years; // Год в который была произведена бутылка
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int у);
	~Wine();
	
	void Show() const;
	void GetBottles();
	const std::string & Label() const;
	int sum() const;
};
//-------------------------------------------------------------------------------------------------
#endif // WINE_H_