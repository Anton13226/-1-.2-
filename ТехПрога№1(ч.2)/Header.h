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
	// иденитфикация, порождение и ввод объекта из потока
	static Type* In(ifstream &ReadFile);				//Для ввода последующих эл-ов

	virtual void InData(ifstream &ReadFile)=0;					// ввод с учетом типа объекта
	virtual void Out(ofstream &WriteFile)=0;		// вывод с учетом типа объекта
	virtual void OutOnlyShot(ofstream &WriteFile);
	virtual void MultiMethod(Type *other, ofstream &WriteFile) = 0;
	virtual void MMComplex(ofstream &WriteFile) = 0;
	virtual void MMShot(ofstream &WriteFile) = 0;
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
	
	void In(ifstream &ReadFile);	//ввод матриц
	void Out(ofstream &WriteFile);	//вывод матриц
	void Clear();				//очистка контейнера
	void Sorting();
	void FiltredOut(ofstream &WriteFile);
	void MultiMethod(ofstream &WriteFile);
	Container();				//инициализация контейнера
	~Container() { Clear(); };
private:
	Node *head;
	int len;			//кол-во элементов
};


class Complex : public Type 
{
private:
	double number1;
	double number2;
	string metric;
public:
	// переопределяем интерфейс класса
	void InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод
	void MultiMethod(Type *other, ofstream &WriteFile);
	void MMComplex(ofstream &WriteFile);
	void MMShot(ofstream &WriteFile);
	double Count();
	Complex() {} // создание без инициализации.
};

class Shot : public Type {
private:
	double number1;
	double number2;
	string metric;
public:
	// переопределяем интерфейс класса
	void InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод
	double Count();
	void OutOnlyShot(ofstream &WriteFile);
	void MultiMethod(Type *other, ofstream &WriteFile);
	void MMComplex(ofstream &WriteFile);
	void MMShot(ofstream &WriteFile);
	Shot() {} // создание без инициализации.
};