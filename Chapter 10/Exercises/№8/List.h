#ifndef LIST_H_
#define LIST_H_
#include <string>

//-------------------------------------------------------------------------------------------------
static const int MAX = 5;
//-------------------------------------------------------------------------------------------------
class List 
{
private:
	std::string items[MAX];
	int top;
public:
	List();
	~List();
	bool isempty() const;
	bool isfull() const;
	bool add_element(const std::string & item);
	void visit_element(void (*pf)(std::string &));
	void show_list();
	void reset_list();
};
//-------------------------------------------------------------------------------------------------
#endif // LIST_H_