// ��������1(�.2).cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Header.h"


int main()
{
	ifstream ReadFile("input.txt");  // ����� ��� ����� � ������
	ofstream WriteFile("output.txt"); // � ���� ���� ������� ��������
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
