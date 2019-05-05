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
	// иденитфикация, порождение и ввод объекта из потока
	static type* In(ifstream &ReadFile);				//Для ввода последующих эл-ов

	virtual bool InData(ifstream &ReadFile)=0;					// ввод с учетом типа объекта
	virtual void Out(ofstream &WriteFile)=0;		// вывод с учетом типа объекта
	virtual void OutOnlyShot(ofstream &WriteFile);
	virtual double Count() = 0;
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
	
	void In(ifstream &ReadFile);	//ввод матриц
	void Out(ofstream &WriteFile);	//вывод матриц
	void Clear();				//очистка контейнера
	void Sorting();
	void FiltredOut(ofstream &WriteFile);
	container();				//инициализация контейнера
	~container() { Clear(); };
private:
	Node *head;
	int len;			//кол-во элементов
};


class complex : public type 
{
private:
	double number1;
	double number2;
	string metric;
public:
	// переопределяем интерфейс класса
	bool InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод
	double Count();
	complex() {} // создание без инициализации.
};

class shot : public type {
private:
	double number1;
	double number2;
	string metric;
public:
	// переопределяем интерфейс класса
	bool InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод
	double Count();
	void OutOnlyShot(ofstream &WriteFile);
	shot() {} // создание без инициализации.
};

class polar : public type
{
private:
	double radius;
	double angle;
	string metric;
public:
	// переопределяем интерфейс класса
	bool InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод
	double Count();
	polar() {} // создание без инициализации.
};

