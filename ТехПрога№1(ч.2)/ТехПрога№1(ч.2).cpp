// ТехПрога№1(ч.2).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"


int main()
{
	ifstream ReadFile("input.txt");  // файлы для ввода и вывода
	ofstream WriteFile("output.txt"); // с ними было удобнее работать
	cout << "Start" << endl;
	Container c;
	c.In(ReadFile);
	c.Out(WriteFile);
	WriteFile << "================================================" << endl;
	c.MultiMethod(WriteFile);
	c.Clear();
	cout << "Stop" << endl;
	return 0;
}
