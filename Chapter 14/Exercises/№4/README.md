#### Глава - 14, Задание - 4 ####

Класс ```Person```(Человек) предназначен для хранения имени и фамилии
человека. Кроме конструкторов он содержит метод ```Show()``` для вывода этих данных.
Класс ```Gunslinger```(Снайпер) виртуально порожден от класса ```Person```. Он
содержит член ```Draw()``` , который возвращает значение типа ```double``` — время,
необходимое снайперу для перехода в боевую готовность. Класс также имеет член типа
```int```, содержащий количество насечек на винтовке. И, наконец, класс содержит
функцию ```Show()```, которая выводит всю эту информацию.

Класс ```PokerPlayer``` (Игрок в покер) виртуально порожден от класса ```Person```. Он
имеет метод ```Draw()```, который возвращает случайное число в диапазоне от ```1 до
52``` — значение карты. (Можно создать класс ```Card``` с членами, определяющими
масть и рубашку карты, чтобы метод ```Draw()``` возвращал значение типа ```Card```).

Класс ```PokerPlayer``` использует функцию ```Show()``` класса ```Person```. 
Класс ```BadDude```(Хулиган) открыто порожден от классов ```Guns linger``` и ```PokerPlayer```. Он
содержит член ```Gdraw()```, возвращающий время вынимания оружия, и член ```Cdraw()```,
возвращающий следующую вытянутую карту. У него есть соответствующая
функция ```Show()```. Определите все упомянутые классы и методы вместе с другими
необходимыми методами (такими как методы для задания значений объекта) и
протестируйте их с помощью простой программы, подобной представленной в
листинге ```14.12```.

=================================================================================
#### Вывод ####
```objectivec
Enter the person category:
p: person  		 g: gunslinger  
k: poker player  b: bad dude
q: quit

p

Enter the first name: Stiv
Enter the last name: Stiven
Type Person
First name: Stiv
Last name: Stiven
ct = 0

Enter the person category:
p: person  		 g: gunslinger  
k: poker player  b: bad dude
q: quit

g

Enter the first name: Killer
Enter the last name: Killer
Enter the draw time: 10
Enter the number of notches: 50
Type Gunslinger
First name: Killer
Last name: Killer
Draw time: 10
Notches: 50
ct = 1

Enter the person category:
p: person  		 g: gunslinger  
k: poker player  b: bad dude
q: quit

k

Enter the first name: Kevin
Enter the last name: Chon
Type Poker Player
First name: Kevin
Last name: Chon
ct = 2

Enter the person category:
p: person  		 g: gunslinger  
k: poker player  b: bad dude
q: quit

b

Enter the first name: Big
Enter the last name: Black
Enter the draw time: 10
Enter the number of notches: 500
Type BadDude
First name: Big
Last name: Black
Draw time: 10
Notches: 500
First name: Big
Last name: Black
ct = 3

Your selection:

Type Person
First name: Stiv
Last name: Stiven

Type Gunslinger
First name: Killer
Last name: Killer
Draw time: 10
Notches: 50

Type Poker Player
First name: Kevin
Last name: Chon

Type BadDude
First name: Big
Last name: Black
Draw time: 10
Notches: 500
First name: Big
Last name: Black
```
