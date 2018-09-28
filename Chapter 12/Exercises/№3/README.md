#### Глава - 12, Задание - 3 ####

Перепишите класс ```Stock```, описанный в листингах ```10.7``` и ```10.8``` в главе ```10```,
чтобы он использовал для хранения названий пакетов акций непосредственно
динамически выделенную память, а не объекты класса ```string```. Кроме того,
замените функцию - член ```show()``` перегруженным определением ```operator<<()```.
Протестируйте новое определение с помощью программы из листинга ```10.9```.

=================================================================================
#### Вывод ####
```objectivec
Stock holdings:
Company: NanoSmart Shares: 12
Share Price: $20.000 Total Worth: $240.00
Company: Boffo Objects Shares: 200
Share Price: $2.000 Total Worth: $400.00
Company: Monolithic Obelisks Shares: 130
Share Price: $3.250 Total Worth: $422.50
Company: Fleep Enterprises Shares: 60
Share Price: $6.500 Total Worth: $390.00

Most valuable holding:
Company: Monolithic Obelisks Shares: 130
Share Price: $3.250 Total Worth: $422.50
```