#### Глава - 16, Задание - 10 ####

Измените код в листинге ```16.9``` (vect3.срр) следующим образом.

***A*** - Добавьте член price в структуру ```Review```.

***B*** - Для хранения вводимых данных используйте вектор ```(vector)``` объектов
```shared_ptr<Review>``` вместо вектора объектов ```Review```. Помните, что
```shared_ptr``` должен быть инициализирован указателем, возвращенным
операцией ```new```.

***C*** - Вслед за этапом ввода данных реализуйте цикл, который предоставляет
пользователю следующие варианты отображения книг: в исходном порядке, в
алфавитном порядке, в порядке возрастания рейтинга, в порядке возрастания
цены, в порядке уменьшения цены и возможность завершения программы.

Один из возможных подходов может быть таким. После получения  
первоначальных введенных данных создайте еще один вектор указателей ```shared_ptr```,
инициализированный исходным массивом. Определите функцию ```operator < ()```,
которая сравнивает указанные структуры, и примените ее для сортировки
второго вектора так, чтобы ```shared_ptr``` были упорядочены по названиям книг,
сохраненных в указанных объектах. Повторите процесс, чтобы получить вектор
объектов ```shared_ptr```, отсортированных по ```rating``` и ```price```. Обратите
внимание, что ```rbegin()``` и ```rend()``` избавляют от необходимости создания векторов с
обратным порядком следования элементов.

=================================================================================
#### Вывод ####
```objectivec
Enter book price: 1324
Enter book title (quit to quit): Awakening of the Ancients
Enter book rating: 8
Enter book price: 9
Enter book title (quit to quit): C++
Enter book rating: 10
Enter book price: 10000
Enter book title (quit to quit): quit
Please select the sort:
t.sort by title       r.sort by rating
p.sort by price       f.sort by title reserve
q.quit
t
Sort by title:
Rating  Title   Price
8       Awakening of the Ancients       9
10      C++     10000
5       Demon Defenders 1324
Please select the sort:
t.sort by title       r.sort by rating
p.sort by price       f.sort by title reserve
q.quit
r
Sort by rating:
Rating  Title   Price
5       Demon Defenders 1324
8       Awakening of the Ancients       9
10      C++     10000
Please select the sort:
t.sort by title       r.sort by rating
p.sort by price       f.sort by title reserve
q.quit
p
Sort by price:
Rating  Title   Price
8       Awakening of the Ancients       9
5       Demon Defenders 1324
10      C++     10000
Please select the sort:
t.sort by title       r.sort by rating
p.sort by price       f.sort by title reserve
q.quit
f
Title reserve output:
Rating  Title   Price
10      C++     10000
5       Demon Defenders 1324
8       Awakening of the Ancients       9
Please select the sort:
t.sort by title       r.sort by rating
p.sort by price       f.sort by title reserve
q.quit
q
```