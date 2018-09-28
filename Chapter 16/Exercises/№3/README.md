#### Глава - 16, Задание - 3 ####

Измените программу из листинга ```16.3```, чтобы она получала слова из файла. Один
из возможных подходов предполагает использование объекта ```vector<string>```
вместо массива элементов типа ```string```. Затем можно применить ```push_back()```
для копирования стольких слов, сколько их имеется в файле данных, в объект
```vector<string>```, а с помощью функции-члена ```size()``` определить длину списка
слов. Поскольку программа должна считывать слова из файла по одному,
необходимо использовать операцию ```>>```, а не ```getline()```. Сам файл должен содержать
слова, разделенные пробелами, символами табуляции или символами новой
строки.

=================================================================================
#### Вывод ####
```objectivec
File Text.txt

apiary beetle cereal danger ensign 
florid garage health insult jackal 
keeper loaner manage nonce onset 
plaid quilt remote stolid train 
useful valid whence xenon yearn zippy

=====================================

Will you play a word game? <y/n> y
Guess my secret word. It has 6 letters, and you guess
one letter at a time. You get 6 wrong guesses.
Your word: ------
Guess a letter: v
Oh, bad guess!
Your word: ------
Bad choices: v
5 bad guesses left
Guess a letter: a
Good guess!
Your word: -a--a-
Bad choices: v
5 bad guesses left
Guess a letter: j
Good guess!
Your word: ja--a-
Bad choices: v
5 bad guesses left
Guess a letter: c
Good guess!
Your word: jac-a-
Bad choices: v
5 bad guesses left
Guess a letter: k
Good guess!
Your word: jacka-
Bad choices: v
5 bad guesses left
Guess a letter: l
Good guess!
Your word: jackal
That's right!
Will you play another? <y/n> n
Bye
```