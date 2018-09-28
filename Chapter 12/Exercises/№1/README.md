#### Глава - 12, Задание - 1 ####

Имеется следующее объявление класса:

```objectivec
class Cow 
{ 
	char name[2 0]; 
	char* hobby; 
	double weight; 
public: 
	Cow (); 
	Cow (const char* nm, const char * ho, double wt) ; 
	Cow(const Cow & c); 
	~Cow() ;
	Cow & operator = (const Cow & c) ; 
	void ShowCow() const;
};
```

Напишите реализацию для этого класса и короткую программу, использующую
все функции-члены.

=================================================================================
#### Вывод ####
```objectivec
Cow №1:
--- Default constructor called
Cow №2:
--- Сonstructor with parameters was called
Cow №3:
--- Copy Constructor called
Cow №4:
--- Default constructor called
--- Assignment operator called

---------------------

Cow №1:
Name:
Hobby:
Weight: 0

Cow №2:
Name: Cow2
Hobby: HOBBY
Weight: 89

Cow №3:
Name: Cow2
Hobby: HOBBY
Weight: 89

Cow №4:
Name: Cow2
Hobby: HOBBY
Weight: 89

---------------------
End!

--- Called the destructor
--- Called the destructor
--- Called the destructor
--- Called the destructor
```
