#### Глава - 18, Задание - 2 ####

Ниже показано объявление класса Cpmv:

```objectivec
class Cpmv 
{ 
public: 
	struct Info
	{ 
		std::string qcode; 
		std::string zcode; 
	}; 
private: 
	Info* pi; 
public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv (const Cpmv & cp);
	Cpmv (Cpmv && mv);
	~Cpmv();
	Cpmv & operator = (const Cpmv & cp);
	Cpmv & operator = (Cpmv && mv);
	Cpmv operator* (const Cpmv & obj) const;
	void Display() const;
};
```

Функция ```operator* ()``` должна создавать объект, члены ```qcode``` и ```zcode```
которого являются результатом конкатенации соответствующих членов операндов.
Напишите код, который реализует семантику переноса для конструктора
переноса и операции присваивания с переносом. Напишите программу,
использующую все методы класса ```Cpmv```. В целях тестирования обеспечьте выдачу
сообщений в методах, чтобы можно было увидеть, когда они используются.

=================================================================================
#### Вывод ####
```objectivec
q and z constructor called
Address 02D58520

Copy constructor called
Address 02D5E310

q and z constructor called
Address 02D5E378

Entering operator +()
Default ctor
Address 02D5E0A0

Leaving operator+()
Move constructor called
Address 02D5E0A0

Destructor called
Address 00000000

Default ctor
Address 02D5E108

Entering operator=(const Cpmv & cp)
Leaving operator=()
Default ctor
Address 02D5E580

Entering operator +()
Default ctor
Address 02D5E5E8

Leaving operator+()
Move constructor called
Address 02D5E5E8

Destructor called
Address 00000000

Entering operator=(Cpmv && mv)
Address 02D5E5E8

Destructor called
Address 00000000


object 1 Hi , Sunny

object 2 Hi , Sunny

object 3 Hello, World!

object 4 Hi Hello, SunnyWorld!

object 5 Hi , Sunny

object 6 Hi Hello, SunnyWorld!

Destructor called
Address 02D5E5E8

Destructor called
Address 02D5E788

Destructor called
Address 02D5E0A0

Destructor called
Address 02D5E378

Destructor called
Address 02D5E310

Destructor called
Address 02D58520
```