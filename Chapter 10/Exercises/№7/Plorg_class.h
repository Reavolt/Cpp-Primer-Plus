#ifndef PLORG_CLASS_H_
#define PLORG_CLASS_H_

//-------------------------------------------------------------------------------------------------
class Plorg 
{
private:
	static const int SIZE = 19;
	char name_plorg[SIZE];
	int ci;
public:
	Plorg(const char* name = "Plorga", int index = 50);
	void change_ci(char action, int index);
	void show_data() const;
};
//-------------------------------------------------------------------------------------------------
#endif // PLORG_CLASS_H_