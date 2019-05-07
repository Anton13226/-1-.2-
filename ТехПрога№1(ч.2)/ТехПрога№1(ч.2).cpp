// ТехПрога№1(ч.2).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"


int main()
{
	ifstream ReadFile("input.txt");  // файлы для ввода и вывода
	ofstream WriteFile("output.txt"); // с ними было удобнее работать
	if (!ReadFile.is_open())
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}
	cout << "Start" << endl;
	container c;
	c.In(ReadFile);
	c.Out(WriteFile);
	WriteFile << "================================================" << endl;
	c.Sorting();
	c.Out(WriteFile);
	c.FiltredOut(WriteFile);
	//c.Clear();
	cout << "Stop" << endl;
	return 0;
}
