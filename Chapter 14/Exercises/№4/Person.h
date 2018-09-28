#ifndef PERSON_H_    
#define PERSON_H_
#include <string>

//-------------------------------------------------------------------------------------------------
class Person
{
private:
	std::string firstname;
	std::string lastname;
protected:
	virtual void Data() const;
public:
	Person(const std::string & first = "", const std::string & last = "");
	virtual ~Person() {};
	void setFirstName(const std::string & s) { firstname = s; }
	void setLastName(const std::string & s) { lastname = s; }
	virtual void Show() const;
	virtual void Set();
};
//-------------------------------------------------------------------------------------------------
class Gunslinger : virtual public Person
{
private:
	double drawtime;
	int notches;
protected:
	void Data() const;
	virtual void setData();
public:
	Gunslinger(const std::string & first = "", const std::string & last = "", double d = 0, int n = 0);
	~Gunslinger() {};
	void setDrawTime(double d);
	void setNotches(int n);
	double Draw() const { return drawtime; }
	int Notches() const { return notches; }
	virtual void Show() const;
	virtual void Set() { Person::Set(); Gunslinger::setData(); }
};
//-------------------------------------------------------------------------------------------------
class PokerPlayer : virtual public Person
{
public:
	PokerPlayer(std::string first = "", std::string last = "");
	~PokerPlayer() {}
	int Draw() const { return rand() % 52; }
	virtual void Show() const;
	virtual void Set() { Person::Set(); }
};
//-------------------------------------------------------------------------------------------------
class BadDude : public Gunslinger, public PokerPlayer
{
private:
public:
	BadDude(std::string first = "", std::string last = "", double d = 0, int n = 0);
	~BadDude() {}
	double Gdraw() const { return Gunslinger::Draw(); } 
	int Cdraw() const { return PokerPlayer::Draw(); }
	virtual void Show() const;
	void Set();
};
//-------------------------------------------------------------------------------------------------
#endif // PERSON_H_