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

	virtual void InData(ifstream &ReadFile)=0;					// ввод с учетом типа объекта
	virtual void Out(ofstream &WriteFile)=0;	
	virtual float Count() = 0;	// вывод с учетом типа объекта
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
	void InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод
	float Count();
	complex() {} // создание без инициализации.
};

class shot : public type {
private:
	double number1;
	double number2;
	string metric;
public:
	// переопределяем интерфейс класса
	void InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод
	float Count();
	shot() {} // создание без инициализации.
};

class polar : public type
{
private:
	double radius;
	double angle;
	string metric;
	const float rad = 6.2;
public:
	// переопределяем интерфейс класса
	void InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод
	float Count();
	polar() {} // создание без инициализации.
};

