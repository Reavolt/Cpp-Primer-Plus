#### Глава - 11, Задание - 2 ####

Модифицируйте заголовок класса ```Vector``` и файлы реализации (листинги ```11.13```
и ```11.14```) так, чтобы модуль и направление вектора больше не хранились в виде
компонентов данных. Вместо этого они должны вычисляться по требованию
при вызове методов ```magval()``` и ```angval()```. Вы должны оставить открытый
интерфейс без изменений (те же открытые методы с теми же аргументами), но
изменить закрытую часть, включая некоторые из закрытых методов и их
реализации. Протестируйте модифицированную версию с помощью программы из
листинга ```11.15```, которая должна остаться неизменной, поскольку открытый
интерфейс класса ```Vector``` не менялся.

=================================================================================
#### Вывод ####
```objectivec
Enter target distance (q to quit) : 50
Enter step length: 1
After 15079 steps, the subject has the following location:
(x,y) = (-20.8167, -46.0696)
or
(m,a) = (50.5544, -114.316 )
Average outward distance per step = 0.00335263
Enter target distance (q to quit): 50
Enter step length: 1
After 1353 steps, the subject has the following location:
(x,y) = (25.0863, -43.6398)
or
(m,a) = (50.3364, -60.1076 )
Average outward distance per step = 0.0372036
Enter target distance (q to quit): 50
Enter step length: 2
After 851 steps, the subject has the following location:
(x,y) = (-34.9686, 36.5892)
or
(m,a) = (50.612, 133.703 )
Average outward distance per step = 0.0594735
Enter target distance (q to quit): q
Bye!
```