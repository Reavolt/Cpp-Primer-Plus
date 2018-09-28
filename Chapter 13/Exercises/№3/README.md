#### Глава - 13, Задание - 3 ####

Перепишите иерархию классов ```base DMA-lacks DMA-has DMA``` таким образом,
чтобы все три класса были порождены от абстрактного базового класса.
Протестируйте результат с помощью программы, подобной приведенной в
листинге ```13.10```. То есть она должна использовать массив указателей на абстрактный
базовый класс и позволять пользователю принимать во время работы
программы решения о том, объекты какого типа создавать. Добавьте в определения
классов виртуальные методы ```View()``` для управления выводом данных.

=================================================================================
#### Вывод ####
```objectivec
For element 1, enter the label: LABEL
Enter the rating: 10
Enter 1 if this is to be a baseDMA object
Enter 2 if this is to be a hasDMA object
Enter 3 if this is to be a lacksDMA object
2
Enter the style: STYLE
For element 2, enter the label: LABEL
Enter the rating: 12
Enter 1 if this is to be a baseDMA object
Enter 2 if this is to be a hasDMA object
Enter 3 if this is to be a lacksDMA object
2
Enter the style: STYLE2
For element 3, enter the label: LABEL3
Enter the rating: 13
Enter 1 if this is to be a baseDMA object
Enter 2 if this is to be a hasDMA object
Enter 3 if this is to be a lacksDMA object
3
Enter color: RED
Here's what you entered:
Element 1:
hasDMA object
Label: LABEL
Rating: 10
Style: STYLE
Element 2:
hasDMA object
Label: LABEL
Rating: 12
Style: STYLE2
Element 3:
lacksDMA object
Label: LABEL3
Rating: 13
Color: RED
```