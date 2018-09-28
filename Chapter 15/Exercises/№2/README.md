#### Глава - 15, Задание - 2 ####

Измените код в листинге ```15.11``` так, чтобы два типа исключений были классами,
производными от класса ```logicerror```, определенного в заголовочном файле
```<stdexcept>```. Сделайте так, чтобы каждый метод ```what()``` сообщал имя функции
и суть проблемы. Объекты исключений не должны содержать значение ошибки,
они должны просто поддерживать метод ```what()```.

=================================================================================
#### Вывод ####
```objectivec
Enter two numbers: 4 12
Harmonic mean of 4 and 12 is 6
Geometric mean of 4 and 12 is 6.9282
Enter next set of numbers <q to quit>: 5 -5

Error in hmean() : values are equal
Try again.
5 -2
Harmonic mean of 5 and -2 is -6.66667
Error in gmean(): both values must be positive
Sorry, you don't get to play any more.
Bye!
```