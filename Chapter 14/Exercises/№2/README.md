#### Глава - 14, Задание - 2 ####

Выполните еще раз упражнение ```1```, но вместо включения используйте закрытое
наследование. Здесь также могут пригодиться несколько объявлений typedef.
Подумайте, как можно применить следующие операторы:

```objectivec
PairArray::operator = (PairArray(Arraylnt(), Arraylnt()));
cout << (const string &)(*this);
```

Полученный класс должен работать с тестовой программой, приведенной в
упражнении ```1```.

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