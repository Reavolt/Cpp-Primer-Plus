#### Глава - 14, Задание - 1 ####

Класс ```Wine (Вино)``` содержит объект-член типа ```string``` (см. главу ```4```) для названия
вина и объект ```Pair``` из объектов ```valarray<int>``` (рассматривались в этой
главе). Первый член каждого объекта ```Pair``` содержит год сбора винограда, а второй
член — количества бутылок с вином урожая этих лет. Например, первый
объект ```valarray``` объекта ```Pair``` содержит годы ```1988, 1992 и 1996```, а второй объект
```valarray``` — количества бутылок: ```24, 48 и 144```. Хорошо бы, чтобы объект ```Wine```
содержал целочисленный член для хранения возраста вина в годах. Для
упрощения кода могут быть полезными следующие объявления ```typedef```(***Заменены using Hitoku***):

```objectivec
typedef std::valarray<int> Arraylnt; 
typedef Pair<ArrayInt, Arraylnt> PairArray; 

using ArrayInt = std::valarray<int>;
using PairArray = std::pair<ArrayInt, ArrayInt>;
```

Таким образом, тип ```PairArray``` представляет тип ```Pair<std::valarray<int>,
std::valarray<int>>```. Реализуйте класс ```Wine```, используя включение. Этот
класс должен иметь конструктор по умолчанию и, как минимум, следующие
конструкторы:

```objectivec
// Инициализация label значением 1, количество лет - у,
// годы урожая - yr[], количество бутылок - bot[]
Wine(const char* 1, int у, const int yr[], const int bot[]);
// Инициализация label значением 1, количество лет - у,
// создаются объекты массива размером у
Wine(const char* 1, int у);
```

Класс ```Wine``` должен содержать метод ```GetBottles()```, который для объекта Wine
заданного возраста предлагает пользователю ввести соответствующие значения
для года урожая и количества бутылок. Метод ```Label()``` должен возвращать
ссылку на название вина, а метод ```sum()``` — общее количество бутылок во втором
объекте ```valarray<int>``` из объекта ```Pair```.

Программа должна предлагать пользователю ввести название вина, количество
элементов в массиве, а также год и количество бутылок для каждого элемента
массива. Программа должна использовать эти данные для создания объекта
```Wine``` и вывода информации, хранимой в объекте. Для справки ниже приведен
пример тестовой программы:

```objectivec
// ре14-1.срр — класс Wine с использованием включения 
int main(void) 
{ 
	using std::cin; 
	using std::cout; 
	using std::endl; 
	cout << "Enter name of wine: "; // ввод названия вина 
	char lab[50]; 
	cin.getline(lab, 50); 
	cout << "Enter number of years: "; // ввод количества годов сбора винограда 
	int yrs; 
	cin >> yrs; 
	Wine holding(lab, yrs); // сохранение названия, лет, 
	// создание массивов из yrs элементов 
	holding.GetBottles (); // предложение ввести год и количество бутылок 
	holding.Show (); // вывод содержимого объекта 
	const int YRS = 3; 
	int y[YRS] = {1993, 1995, 1998}; 
	int b[YRS] = { 48, 60, 72}; 
	// Создание нового объекта, инициализация 
	// с использованием данных из массивов у и b 
	Wine more("Gushing Grape Red",YRS, y, b) ; 
	more.Show(); 
	cout << "Total bottles for " << more.Label() // используется метод Label() 
	<< ": " << more, sum () << endl; // используется метод sum() 
	cout << "Bye\n"; 
	return 0; 
} 
```

А так может выглядеть вывод программы:

```objectivec
Enter name of wine: Gully Wash 
Enter number of years: 4 
Enter Gully Wash data for 4 year(s) : 
Enter year: 1988 
Enter bottles for that year: 42 
Enter year: 1994 
Enter bottles for that year: 58 
Enter year: 1998 
Enter bottles for that year: 122 
Enter year: 2001 
Enter bottles for that year: 144 
Wine: Gully Wash 
Year 	Bottles 
1988 	42 
1994 	58 
1998 	122 
2001 	144 
Wine: Gushing Grape Red 
Year 	Bottles 
1993 	48 
1995 	60 
1998 	72 
Total bottles for Gushing Grape Red: 180 
Bye 
```

=================================================================================
#### Вывод ####
```objectivec
Enter name of wine: Gully Wash

Enter number of years: 4
Enter Gully Wash data for 4 year(s):
Enter year: 1988
Enter bottles for that year: 42

Enter year: 1994
Enter bottles for that year: 58

Enter year: 1998
Enter bottles for that year: 122

Enter year: 2001
Enter bottles for that year: 144

Wine: Gully Wash
Year    Bottles
1988    42
1994    58
1998    122
2001    144
Wine: Gushing Grape Red
Year    Bottles
1993    48
1995    60
1998    72

Total bottles for Gushing Grape Red: 180
Bye
```