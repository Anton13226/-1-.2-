// ��������1(�.2).cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Header.h"


int main()
{
	ifstream ReadFile("input.txt");  // ����� ��� ����� � ������
	ofstream WriteFile("output.txt"); // � ���� ���� ������� ��������
	cout << "Start" << endl;
	container c;
	c.In(ReadFile);
	c.Sorting();
	c.Out(WriteFile);
	c.FiltredOut(WriteFile);
	c.Clear();
	cout << "Stop" << endl;
	return 0;
}
