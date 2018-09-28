#### Глава - 13, Задание - 1 ####

Начните со следующего объявления класса:

```objectivec
// Базовый класс 
class Cd  // представляет компакт-диск 
{
private: 
	char performers[50]; 
	char label[20]; 
	int selections; // количество сборников 
	double playtime; // время воспроизведения в минутах 
public: 
	Cd(char* si, char* s2, int n, double x); 
	Cd(const Cd & d); 
	Cd(); 
	~Cd(); 
	void Report() const; // выводит все данные о компакт-диске 
	Cd & operator= (const Cd & d); 
};
```

Породите класс ```Classic```, добавив массив членов ```char```, которые будут хранить
строку с названием основного произведения на компакт-диске. Если
необходимо, чтобы какие-то функции в базовом классе были виртуальными, измените
объявление базового класса. Если объявленный метод не нужен, удалите его из
определения. Протестируйте результат с помощью следующей программы:

```objectivec
#include <iostream> 
#include "classic.h" // будет содержать #include cd.h 

using namespace std; 

void Bravo(const Cd & disk); 

int main () 
{ 
	Cd cl("Beatles", "Capitol", 14, 35.5); 
	Classic c2 = Classic("Piano Sonata in В flat, Fantasia in C", 
	"Alfred Brendel", "Philips", 2, 57.17); 
	Cd *pcd = &cl; 
	// Непосредственное использование объектов 
	cout << "Using object directly:\n"; 
	cl.Report(); // использование метода Cd 
	c2.Report(); // использование метода Classic 
	// Использование указателя на объекты типа cd * 
	cout << "Using type cd * pointer to objects: \n" ; 
	pcd->Report(); // использование метода Cd для объекта cd 
	pcd = &c2; 
	pcd->Report (); // использование метода Classic для объекта classic 
	// Вызов функции с аргументом-ссылкой на Cd 
	cout << "Calling a function with a Cd reference argument:\n"; 
	Bravo(cl); 
	Bravo(c2); 
	// Тестирование присваивания 
	cout << "Testing assignment: "; 
	Classic copy; 
	copy = c2; 
	copy.Report() 
	return 0; 
}
 
void Bravo (const Cd & disk) 
{ 
	disk.Report(); 
} 
```

=================================================================================
#### Вывод ####
```objectivec
Using object directly:

Performers: Beatles
label: Capitol
Selections: 14
Play time: 35.5

Performers: Alfred Brendel
label: Phillips
Selections: 2
Play time: 57.17

Primary Work: Piano sonata in b flat, Fantasia in C
Using type cd * pointer to objects:

Performers: Beatles
label: Capitol
Selections: 14
Play time: 35.5

Performers: Alfred Brendel
label: Phillips
Selections: 2
Play time: 57.17

Primary Work: Piano sonata in b flat, Fantasia in C
Calling a function with a Cd reference argument:

Performers: Beatles
label: Capitol
Selections: 14
Play time: 35.5

Performers: Alfred Brendel
label: Phillips
Selections: 2
Play time: 57.17

Primary Work: Piano sonata in b flat, Fantasia in C
Testing assignment:
 
Performers: Alfred Brendel
label: Phillips
Selections: 2
Play time: 57.17
```
