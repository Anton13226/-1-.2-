// ��������1(�.2).cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Header.h"


int main()
{
	ifstream ReadFile("input.txt");  // ����� ��� ����� � ������
	ofstream WriteFile("output.txt"); // � ���� ���� ������� ��������
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
