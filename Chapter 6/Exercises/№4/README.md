#### Глава - 6, Задание - 4 ####

Когда вы вступите в Благотворительный Орден Программистов (БОП), к вам
могут обращаться на заседаниях БОП по вашему реальному имени, по
должности либо секретному имени БОП. Напишите программу, которая может
выводить списки членов по реальным именам, должностям, секретным именам либо
по предпочтению самого члена. В основу положите следующую структуру:

```objectivec
// Структура имен Благотворительного Ордена Программистов (БОП) 
struct bop 
{ 
	char fullname[strsize]; 	// реальное имя 
	char title[strsize]; 		// должность 
	char bopname[strsize]; 		// секретное имя БОП 
	int preference; 		// 0 = полное имя, 1 = титул, 2 = имя БОП 
}; 
```

В этой программе создайте небольшой массив таких структур и
инициализируйте его соответствующими значениями. Пусть программа запустит цикл,
который даст возможность пользователю выбирать разные альтернативы:

```objectivec
a. display by name b. display by title 
c. display by bopname d. display by preference 
q. quit 
```

Обратите внимание, что "display by preference" (отображать по предпочтениям)
не означает, что нужно отобразить член preference; это значит, что
необходимо отобразить член структуры, который соответствует значению preference. 
Например, если preference равно 1, то выбор d должен вызвать отображение
должности данного программиста. Пример запуска этой программы может
выглядеть следующим образом:

```objectivec
Benevolent Order of Programmers Report 
a. display by name b. display by title 
c. display by bopname d. display by preference 
q. quit 
Enter your choice: a 
Wimp Macho 
Raki Rhodes 
Celia Laiter 
Hoppy Hipman 
Pat Hand 
Next choice: d 
Wimp Macho 
Junior Programmer 
MIPS 
Analyst Trainee 
LOOPY 
Next choice: q 
Bye! 
```

=================================================================================
#### Вывод ####
```objectivec
Benevolent Order of Programmers Report
a. display by name
b. display by title
c. display by bopname
d. display by preference
q. quit

a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman

b
Wimp Macho - WM
Raki Rhodes - RR
Celia Laiter - CL
Hoppy Hipman - HH

c
WM
RR
CL
HH

d
Wimp Macho
Raki Rhodes - RR
CL
Hoppy Hipman

q
Bye!
```
