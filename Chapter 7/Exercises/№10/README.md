#### Глава - 7, Задание - 10 ####

Спроектируйте функцию ```calculate()```, которая принимает два значения типа
```double``` и указатель на функцию, принимающую два аргумента ```double``` и
возвращающую значение ```double```. Функция ```calculate()``` также должна иметь тип
```double``` и возвращать значение, вычисленное функцией, которая задана
указателем, используя аргумент ```double``` функции ```calculate()```. Например,
предположим, что имеется следующее определение функции ```add()```:

```objectivec
double add(double x, double y) 
{ 
	return x + y; 
}
```

Приведенный ниже вызов функции должен заставить ```calculate()``` передать
значения ```2.5``` и ```10.4``` функции ```add()``` и вернуть ее результат ```(12.9)```:

```objectivec
double q = calculate (2.5, 10.4, add);
```

Используйте в программе эти функции и еще хотя бы одну дополнительную,
которая подобна ```add()```. В программе должен быть организован цикл,
позволяющий пользователю вводить пары чисел. Для каждой пары ```calculate()``` должна
вызвать ```add()``` и хотя бы еще одну функцию такого рода. Если вы чувствуете
себя уверенно, попробуйте создать массив указателей на функции, подобные
```add()```, и организуйте цикл, применяя ```calculate()``` для вызова этих функций
по их указателям. 
Подсказка: вот как можно объявить массив из трех таких указателей:

```objectivec
double (*pf[3])(double, double);
```
Инициализировать такой массив можно с помощью обычного синтаксиса
инициализации массивов и имен функций в качестве адресов.

=================================================================================
#### Вывод ####
```objectivec
Choose the action of the calculator:
[1] - Multiplication:
[2] - Division:
[3] - Subtraction:
[4] - Addition:
[Q/q] - Exit:
1
Multiplication: Enter x and y -> 2 2
2 * 2 = 4
Choose the action of the calculator:
[1] - Multiplication:
[2] - Division:
[3] - Subtraction:
[4] - Addition:
[Q/q] - Exit:
2
Division: Enter x and y -> 10 5
10 / 5 = 2
Choose the action of the calculator:
[1] - Multiplication:
[2] - Division:
[3] - Subtraction:
[4] - Addition:
[Q/q] - Exit:
3
Subtraction: Enter x and y -> 4 5
4 - 5 = -1
Choose the action of the calculator:
[1] - Multiplication:
[2] - Division:
[3] - Subtraction:
[4] - Addition:
[Q/q] - Exit:
4
Addition: Enter x and y -> 10 5
10 + 5 = 15
Choose the action of the calculator:
[1] - Multiplication:
[2] - Division:
[3] - Subtraction:
[4] - Addition:
[Q/q] - Exit:
q
```