#### Глава - 16, Задание - 5 ####

Решите ту же задачу, что и в упражнении 4, но с помощью шаблонной функции:

```objectivec
template <class T>
int reduce (T ar[] , int n);
```
 
Протестируйте функцию в короткой программе, используя экземпляры с ```long```
и ```string```.

=================================================================================
#### Вывод ####
```objectivec
Would you like to enter strings or integers? (s for strings, i for integers)
s
Enter up to 15 strings (quit to quit):
apiary beetle cereal danger ensign
florid garage health insult jackal
keeper loaner manage nonce onset
plaid

You entered 

apiary beetle cereal danger ensign 
florid garage health insult jackal 
keeper loaner manage nonce onset

Here's your sorted array, without duplicates:
apiary beetle cereal danger ensign florid garage health insult jackal keeper loaner manage nonce onset
```