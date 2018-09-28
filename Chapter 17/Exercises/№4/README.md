#### Глава - 17, Задание - 4 ####

Напишите программу, которая открывает два текстовых файла для ввода и
один для вывода. Программа должна соединять соответствующие строки
входных файлов, используя в качестве разделителя пробел, и записывать
результаты в выходной файл. Если один файл короче второго, остальные строки более
длинного файла также должны копироваться в выходной файл. Например,
предположим, что первый входной файл имеет следующее содержимое:

```objectivec
eggs kites donuts
balloons hammers
stones
```

А второй файл — такое:

```objectivec
zero lassitude
finance drama
```

Результирующий файл должен выглядеть следующим образом:

```objectivec
eggs kites donuts zero lassitude
balloons hammers finance drama
stones
```

=================================================================================
#### Вывод ####
```objectivec
Microsoft Windows [Version 10.0.16299.125]
(c) Корпорация Майкрософт (Microsoft Corporation), 2017. Все права защищены.

C:\Users\Reavolt> cd C:\Users\Reavolt\Desktop\prog\Test\Debug

C:\Users\Reavolt\Desktop\prog\Test\Debug> Test.exe file1.txt file2.txt file3.txt
Warning: this will erase the contents of file2.txt. Proceed? (y/n) y

==============================================
file1.txt
eggs kites donuts
balloons hammers
stones

file2.txt
zero lassitude
finance drama

file3.txt
eggs kites donuts zero lassitude
balloons hammers finance drama
stones
```