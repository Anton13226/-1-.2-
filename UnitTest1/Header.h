#pragma once
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include <string>

using namespace std;

int NOD(int a, int b);

class type
{
public:
	// �������������, ���������� � ���� ������� �� ������
	static type* In(ifstream &ReadFile);				//��� ����� ����������� ��-��

	virtual void InData(ifstream &ReadFile)=0;					// ���� � ������ ���� �������
	virtual void Out(ofstream &WriteFile)=0;		// ����� � ������ ���� �������
	virtual void OutOnlyShot(ofstream &WriteFile);
	virtual float Count() = 0;
protected:
	type() {};
};

class Node
{
public:
	type *info;
	Node *next;
};

class container
{
public:
	
	void In(ifstream &ReadFile);	//���� ������
	void Out(ofstream &WriteFile);	//����� ������
	void Clear();				//������� ����������
	void Sorting();
	void FiltredOut(ofstream &WriteFile);
	container();				//������������� ����������
	~container() { Clear(); };
private:
	Node *head;
	int len;			//���-�� ���������
};


class complex : public type 
{
private:
	double number1;
	double number2;
	string metric;
public:
	// �������������� ��������� ������
	void InData(ifstream &ReadFile); // ����
	void Out(ofstream &WriteFile); // �����
	float Count();
	complex() {} // �������� ��� �������������.
};

class shot : public type {
private:
	double number1;
	double number2;
	string metric;
public:
	// �������������� ��������� ������
	void InData(ifstream &ReadFile); // ����
	void Out(ofstream &WriteFile); // �����
	float Count();
	void OutOnlyShot(ofstream &WriteFile);
	shot() {} // �������� ��� �������������.
};

class polar : public type
{
private:
	double radius;
	double angle;
	string metric;
public:
	// �������������� ��������� ������
	void InData(ifstream &ReadFile); // ����
	void Out(ofstream &WriteFile); // �����
	float Count();
	polar() {} // �������� ��� �������������.
};
