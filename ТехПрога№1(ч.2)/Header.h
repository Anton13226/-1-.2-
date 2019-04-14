#pragma once
#include "stdafx.h"
#include "iostream"
#include "fstream"

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
	int number1;
	int number2;
public:
	// �������������� ��������� ������
	void InData(ifstream &ReadFile); // ����
	void Out(ofstream &WriteFile); // �����

	complex() {} // �������� ��� �������������.
};

class shot : public type {
private:
	int number1;
	int number2;

public:
	// �������������� ��������� ������
	void InData(ifstream &ReadFile); // ����
	void Out(ofstream &WriteFile); // �����
	void OutOnlyShot(ofstream &WriteFile);
	shot() {} // �������� ��� �������������.
}
;



/*
class Base {
public:
	virtual void who() { // ����������� ����������� �������
		cout << *Base\n";
	}
};
class first_d : public Base {
public:
	void who() { // ����������� who() ������������� � first_d
		cout << "First derivation\n";
	}
};
class second_d : public Base {
public:
	void who() { // ����������� who() ������������� � second_d
		cout << "Second derivation\n*";
	}
};
int main()
{
	Base base_obj;
	Base *p;
	first_d first_obj;
	second_d second_obj;
	p = &base_obj;
	p->who(); // ������ � who ������ Base
	p = &first_obj;
	p->who(); // ������ � who ������ first_d
	p = &second_obj;
	p->who(); // ������ � who ������ second_d
	return 0;
}

 ����� ������ �� ������� ����� ������������ ��� ������� � ����������� ������� 

class Base {
public:
	virtual void who() { // ����������� ����������� �������
		cout << "Base\n";
	}
};
class first_d : public Base {
public:
	void who() { // ����������� who() ������������� � first_d
		cout << "First derivation\n";
	}
};
class second_d : public Base {
public:
	void who() { // ����������� who() ������������� � second_d
		cout << "Second derivation\n*";
	}
};
// ������������� � �������� ��������� ������ �� ������� �����
void show_who(Base &r) {
	r.who();
}
int main()
{
	Base base_obj;
	first_d first_obj;
	second_d second_obj;
	show_who(base_obj); // ������ � who ������ Base
	show_who(first_obj); // ������ � who ������ first_d
	show_who(second_obj); // ������ � who ������ second_d
	return 0;
}

class Base {
public:
	virtual void who() {
		cout << "Base\n";
	}
};
class first_d : public Base {
public:
	void who() {
		cout << "First derivation\n";
	}
};
class second_d : public Base {
	// who() �� ������������
};
int main()
{
	Base base_obj;
	Base *p;
	first_d first_obj;
		second_d second_obj;
	p = &base_obj;
	p->who(); // ������ � who ������ Base
	p = &first obj;
	p->who(); // ������ � who ������ first_d
	p = &sepond_obj;
	p->who(); /* ������ � who() ������ Base, ��������� second_d �� �������������� 
	return 0;
}

��� ��������� ������ ��������� ��������� :

Base
First derivation
Base

���� ����� � ����, ��� �������������� ������������ ����� ������������� ��������.
����� ����������������� ���, �����������, ��� � ���������� ������� ����� second_d
�������� �� ������ first_d ������ ������ Base.����� ������� who() ��������,
��������� ��������� �� ������ ���� second_d(� ������� ������� who() �� ������������),
�� ����� ������� ������ ������� who(), ����������� � ������ first_d,
��������� ���� ����� � ��������� � ������ second_d.� ����� ������, ����� �����
�� �������������� ����������� �������, �++ ���������� ������ �� �����������, ������� �� �������,
��� �� �������� � �������.*/