#pragma once
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include <string>

using namespace std;

int NOD(int a, int b);

class Type
{
public:
	// �������������, ���������� � ���� ������� �� ������
	static Type* In(ifstream &ReadFile);				//��� ����� ����������� ��-��

	virtual void InData(ifstream &ReadFile)=0;					// ���� � ������ ���� �������
	virtual void Out(ofstream &WriteFile)=0;		// ����� � ������ ���� �������
	virtual void OutOnlyShot(ofstream &WriteFile);
	virtual double Count() = 0;
protected:
    Type() {};
};

class Node
{
public:
	Type *info;
	Node *next;
};

class Container
{
public:
	
	void In(ifstream &ReadFile);	//���� ������
	void Out(ofstream &WriteFile);	//����� ������
	void Clear();				//������� ����������
	void Sorting();
	void FiltredOut(ofstream &WriteFile);
	Container();				//������������� ����������
	~Container() { Clear(); };
private:
	Node *head;
	int len;			//���-�� ���������
};


class Complex : public Type 
{
private:
	double number1;
	double number2;
	string metric;
public:
	// �������������� ��������� ������
	void InData(ifstream &ReadFile); // ����
	void Out(ofstream &WriteFile); // �����
	double Count();
	Complex() {} // �������� ��� �������������.
};

class Shot : public Type {
private:
	double number1;
	double number2;
	string metric;
public:
	// �������������� ��������� ������
	void InData(ifstream &ReadFile); // ����
	void Out(ofstream &WriteFile); // �����
	double Count();
	void OutOnlyShot(ofstream &WriteFile);
	Shot() {} // �������� ��� �������������.
};

class Polar : public Type
{
private:
	double radius;
	double angle;
	string metric;
public:
	// �������������� ��������� ������
	void InData(ifstream &ReadFile); // ����
	void Out(ofstream &WriteFile); // �����
	double Count();
	Polar() {} // �������� ��� �������������.
};

