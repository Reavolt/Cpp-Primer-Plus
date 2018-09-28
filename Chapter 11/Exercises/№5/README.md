#### Глава - 11, Задание - 5 ####

Перепишите класс ```Stonewt``` (листинги 11.16 и 11.17) так, чтобы он имел член
состояния, который управляет тем, в какой форме интерпретируется объект:
стоуны, целочисленное значение в фунтах или значение в фунтах с плавающей
точкой. Перегрузите операцию ```<<``` для замены методов ```show_stn()``` и ```show_lbs()```. 
Перегрузите операции сложения, вычитания и умножения значений ```Stonewt```.
Протестируйте полученный класс с помощью короткой программы, в которой
используются все методы и друзья класса.

=================================================================================
#### Вывод ####
```objectivec
Object var_a constructed by default constructor: 0 pounds.
Object var_b constructed from double value: 62.52 pounds.
Object var_c constructed from stone, double values: 200.21 pounds.
Object var_c (Mode set to STONE): 10 stone, 60.21 pounds.
Object var_c (Mode set to iPOUND): 200 pounds.
Object var_c (Mode set to dPOUND): 200.21 pounds.
Object var_c (Mode set to incorrect value):

Warning! Invalid argument to the setmode() function
The mode is set to STONE.

Object var_c after that: 10 stone, 60.21 pounds.

Object var_d after adding: 262.73 pounds.
Object var_d (Mode set to STONE): 18 stone, 10.73 pounds.
Object var_d (Mode set to iPOUND): 262 pounds.
Object var_d (Mode set to dPOUND): 262.73 pounds.

Object var_d after division: 137.69 pounds.
Object var_d (Mode set to STONE): 9 stone, 11.69 pounds.
Object var_d (Mode set to iPOUND): 137 pounds.
Object var_d (Mode set to dPOUND): 137.69 pounds.

Object var_d after multiplying: 12517.1 pounds.
Object var_d (Mode set to STONE): 894 stone, 1.1292 pounds.
Object var_d (Mode set to iPOUND): 12517 pounds.
Object var_d (Mode set to dPOUND): 12517.1 pounds.
```