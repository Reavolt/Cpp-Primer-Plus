#### Глава - 6, Задание - 9 ####

Выполните упражнение 6, но измените его так, чтобы данные можно было
получать из файла. Первым элементом файла должно быть количество меценатов,
а остальная часть состоять из пар строк, в которых первая строка содержит
имя, а вторая — сумму пожертвования. То есть файл должен выглядеть
примерно так:

```objectivec
4 
Sam Stone 
2000 
Freida Flass 
100500 
Tammy Tubbs 
5000 
Rich Raptor 
55000 
```

==================================================================================
#### Вывод ####
```objectivec
Number of Patrons: 4
The name of the patron has been entered: Sam Stone
Donation amount entered: 2000

The name of the patron has been entered: Freida Flass
Donation amount entered: 100500

The name of the patron has been entered: Tammy Tubbs
Donation amount entered: 5000

The name of the patron has been entered: Rich Raptor
Donation amount entered: 55000

Grand Patrons:
Freida Flass = 100500$
Rich Raptor = 55000$
Patrons:
Sam Stone = 2000$
Tammy Tubbs = 5000$
```