//use_stui.cpp — использование класса с закрытым наследованием 
//Компилировать вместе с studenti.cpp 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "14.4_studenti.h" 

using std::cin;
using std::cout;
using std::endl;

const int pupils = 3;
const int quizzes = 5;

//-------------------------------------------------------------------------------------------------
void set(Student & sa, int n);
//-------------------------------------------------------------------------------------------------
int main()
{
	Student ada[pupils] =
	{ Student(quizzes), Student(quizzes), Student(quizzes) };
	int i;
	for (i = 0; i < pupils; i++)
		set(ada[i], quizzes);
	cout << "\nStudent List:\n"; // вывод списка студентов 
	for (i = 0; i < pupils; ++i)
		cout << ada[i].Name() << endl;
	cout << "\nResults:"; // вывод оценок 
	for (i = 0; i < pupils; i++)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl; // средняя оценка 
	}
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void set(Student & sa, int n)
{
	cout << "Please enter the student's name: ";		// ввод имени студента 
	getline(cin, sa);
	cout << "Please enter " << n << " quiz scores :\n";	// ввод оценок для студента 
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}
//-------------------------------------------------------------------------------------------------
/*
Please enter the student's name: Gil Bayts
Please enter 5 quiz scores :
92 94 96 93 95
Please enter the student's name: Pat Roone
Please enter 5 quiz scores :
83 89 72 78 95
Please enter the student's name: Fleur О'Day
Please enter 5 quiz scores :
92 89 96 74 64

Student List:
Gil Bayts
Pat Roone
Fleur О'Day

Results:
Scores for Gil Bayts :
92 94 96 93 95
average: 94

Scores for Pat Roone :
83 89 72 78 95
average: 83.4

Scores for Fleur О'Day :
92 89 96 74 64
average: 83
Done.
Для продолжения нажмите любую клавишу . . .
*/