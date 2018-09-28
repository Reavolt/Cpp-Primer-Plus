#### Глава - 6, Задание - 3 ####

Напишите предшественник программы, управляемой меню. Она должна
отображать меню из четырех пунктов, каждый из них помечен буквой. Если
пользователь вводит букву, отличающуюся от четырех допустимых, программа
должна повторно приглашать его ввести правильное значение до тех пор, пока
он этого не сделает. Затем она должна выполнить некоторое простое действие
на основе пользовательского выбора. Работа программы должна выглядеть 
примерно так:

```objectivec
Please enter one of the following choices: 
c) carnivore p) pianist 
t) tree g) game 
f 
Please enter a c, p, t, or g: q 
Please enter a c, p, t, or g: t 
A maple is a tree. 
```

==================================================================================
#### Вывод ####
```objectivec
Please enter one of the following choices:
c) carnivore p) pianist
t) tree g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
Your choise t, this is a lenth of your word: 4
```