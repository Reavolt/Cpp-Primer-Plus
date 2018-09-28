#ifndef PERSON_CLASS_H_
#define PERSON_CLASS_H_
#include <string>

//-------------------------------------------------------------------------------------------------
class Person 
{
private:
	static const int LIMIT = 25;
	std::string lname; 			// фамилия 
	char fname[LIMIT]; 			// имя 
public:
	Person() { lname = "-"; fname[0] = '\0'; } 					// #1
	Person(const std::string & In, const char * fn = "Heyyou"); // #2
	~Person();
	
	// Следующие методы отображают lname и fname 
	void Show() const; 			// формат: имя фамилия 
	void FormalShow() const; 	// формат: фамилия, имя 
};
//-------------------------------------------------------------------------------------------------
#endif //PERSON_CLASS_H_