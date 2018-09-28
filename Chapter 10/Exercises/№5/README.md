#### Глава - 10, Задание - 5 ####

Пусть имеется следующее объявление структуры: 

```objectivec
struct customer 
{ 
	char fullname[35]; 
	double payment; 
};
```

Напишите программу, которая будет добавлять структуры заказчиков в стек и
удалять их из стека, представленного объявлением класса ```Stack```. Всякий раз,
когда заказчик удаляется из стека, его зарплата должна добавляться к
промежуточной сумме и по этой сумме выдаваться отчет. На заметку: вы должны иметь
возможность пользоваться классом ```Stack``` без изменений; просто поменяйте
объявление ```typedef```, чтобы ```Item``` был типом customer вместо ```unsigned long```.

=================================================================================
#### Вывод ####
```objectivec
Type A to add the client,
P to delete the client, and Q to exit
A
Enter the customer name: Alex
Enter payment amount: 200

Type A to add the client,
P to delete the client, and Q to exit
A
Enter the customer name: Julia
Enter payment amount: 350

Type A to add the client,
P to delete the client, and Q to exit
p
Client Julia was deleted

Type A to add the client,
P to delete the client, and Q to exit
p
Client Alex was deleted

Type A to add the client,
P to delete the client, and Q to exit
p
Stack is empty

Type A to add the client,
P to delete the client, and Q to exit
q
See you later.
```