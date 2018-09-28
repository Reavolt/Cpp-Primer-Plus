//strquote.cpp -- различные решения 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string> 

using namespace std;

//-------------------------------------------------------------------------------------------------
string version1(const string & si, const string & s2);
const string & version2(string & si, const string & s2); // имеет побочный эффект 
const string & version3(string & si, const string & s2); // неудачное решение 
//-------------------------------------------------------------------------------------------------
int main()
{
	string input;
	string copy;
	string result;
	cout << "Enter a string: ";
	getline(cin, input); // ввод строки 
	copy = input;
	cout << "Your string as entered: " << input << endl;
	result = version1(input, "***"); // отображение выведенной строки 
	cout << "Your string enhanced: " << result << endl;
	// вывод расширенной строки 
	cout << "Your original string: " << input << endl;
	// вывод исходной строки 
	result = version2(input, "###");
	cout << "Your string enhanced: " << result << endl;
	// вывод расширенной строки 
	cout << "Your original string: " << input << endl;
	// вывод исходной строки 
	cout << "Resetting original string.\n";
	// восстановление исходной строки 
	input = copy;
	result = version3(input, "@@@");
	cout << "Your string enhanced: " << result << endl;
	// вывод расширенной строки 
	cout << "Your original string: " << input << endl; // вывод исходной строки 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
string version1(const string & si, const string & s2)
{
	string temp;
	temp = s2 + si + s2;
	return temp;
}
//-------------------------------------------------------------------------------------------------
const string & version2(string & si, const string & s2) // имеет побочный эффект 
{
	si = s2 + si + s2;
	// Возврат ссылки, переданной функции, безопасен 
	return si;
}
//-------------------------------------------------------------------------------------------------
const string & version3(string & si, const string & s2) // неудачное решение 
{
	string temp;
	temp = s2 + si + s2;
	// Возврат ссылки на локальную переменную небезопасен 
	return temp;
}
//-------------------------------------------------------------------------------------------------
/*
Enter a string: It's not ray fault.
Your string as entered: It's not my fault.
Your string enhanced: ***It's not my fault.***
Your original string: It's not my fault.
Your string enhanced: ###It's not my fault.###
Your original string: ###It's not my fault.### •
Resetting original string.
В этой точке программа дает сбой.
*/