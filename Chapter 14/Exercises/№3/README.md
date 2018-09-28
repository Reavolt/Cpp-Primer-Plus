#### Глава - 14, Задание - 3 ####

Определите шаблон ```QueueTp```. Протестируйте его, создав очередь указателей на
Worker (см. листинг ```14.10```), и примените его в программе, такой как
приведенная в листинге ```14.12```.

=================================================================================
#### Вывод ####
```objectivec
Enter the employee category:
w: waiter  s: singer  t: singing waiter  q: quit
w
Enter waiter's name: Elena
Enter worker's ID: 10
Enter waiter's panache rating: 9
Enter the employee category:
w: waiter  s: singer  t: singing waiter  q: quit
s
Enter singer's name: Artur
Enter worker's ID: 11
Enter number for singer's vocal range:
0: other   1: alto   2: contralto   3: soprano
4: bass   5: baritone   6: tenor
4
Enter the employee category:
w: waiter  s: singer  t: singing waiter  q: quit
t
Enter singing waiter's name: Kirill
Enter worker's ID: 12
Enter waiter's panache rating: 10
Enter number for singer's vocal range:
0: other   1: alto   2: contralto   3: soprano
4: bass   5: baritone   6: tenor
0
Enter the employee category:
w: waiter  s: singer  t: singing waiter  q: quit
q

Here is your staff:

Category: waiter
Name: Elena
Employee ID: 10
Panache rating: 9

Category: singer
Name: Artur
Employee ID: 11
Vocal range: bass

Category: singing waiter
Name: Kirill
Employee ID: 12
Vocal range: other
Panache rating: 10
Bye.
```