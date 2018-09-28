#### Глава - 6, Задание - 7 ####

Напишите программу, которая читает слова по одному за раз, пока не будет
введена отдельная буква ```q```. После этого программа должна сообщить количество
слов, начинающихся с гласных, количество слов, начинающихся с согласных,
а также количество слов, не попадающих ни в одну из этих категорий. Одним
из возможных подходов может быть применение ```isalpha()``` для различения
слов, начинающихся с букв, и остальных, с последующим применением ```if``` или
```switch``` для идентификации тех слов, прошедших проверку ```isalpha()```,
которые начинаются с гласных. Пример запуска может выглядеть так:

```objectivec
Enter words (q to quit) : 
The 12 awesome oxen ambled 
quietly across 15 meters of lawn, q 
5 words beginning with vowels 
4 words beginning with consonants 
2 others 
```

==================================================================================
#### Вывод ####
```objectivec
Enter words (q to quit):
The 12 awesome oxen ambled
quietly across 15 meters of lawn, q
5 words beginning with vowels.
4 words beginning with consonants.
2 words beginning with any other character.
```