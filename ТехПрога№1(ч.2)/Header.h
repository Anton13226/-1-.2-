#pragma once
#include "stdafx.h"
#include "iostream"
#include "fstream"

using namespace std;

int NOD(int a, int b);

class type
{
public:
	// иденитфикация, порождение и ввод объекта из потока
	static type* In(ifstream &ReadFile);				//Для ввода последующих эл-ов

	virtual void InData(ifstream &ReadFile)=0;					// ввод с учетом типа объекта
	virtual void Out(ofstream &WriteFile)=0;		// вывод с учетом типа объекта
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
	
	void In(ifstream &ReadFile);	//ввод матриц
	void Out(ofstream &WriteFile);	//вывод матриц
	void Clear();				//очистка контейнера
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
	int number1;
	int number2;
public:
	// переопределяем интерфейс класса
	void InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод

	complex() {} // создание без инициализации.
};

class shot : public type {
private:
	int number1;
	int number2;

public:
	// переопределяем интерфейс класса
	void InData(ifstream &ReadFile); // ввод
	void Out(ofstream &WriteFile); // вывод
	void OutOnlyShot(ofstream &WriteFile);
	shot() {} // создание без инициализации.
}
;



/*
class Base {
public:
	virtual void who() { // определение виртуальной функции
		cout << *Base\n";
	}
};
class first_d : public Base {
public:
	void who() { // определение who() применительно к first_d
		cout << "First derivation\n";
	}
};
class second_d : public Base {
public:
	void who() { // определение who() применительно к second_d
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
	p->who(); // доступ к who класса Base
	p = &first_obj;
	p->who(); // доступ к who класса first_d
	p = &second_obj;
	p->who(); // доступ к who класса second_d
	return 0;
}

 Здесь ссылка на базовый класс используется для доступа к виртуальной функции 

class Base {
public:
	virtual void who() { // определение виртуальной функции
		cout << "Base\n";
	}
};
class first_d : public Base {
public:
	void who() { // определение who() применительно к first_d
		cout << "First derivation\n";
	}
};
class second_d : public Base {
public:
	void who() { // определение who() применительно к second_d
		cout << "Second derivation\n*";
	}
};
// использование в качестве параметра ссылки на базовый класс
void show_who(Base &r) {
	r.who();
}
int main()
{
	Base base_obj;
	first_d first_obj;
	second_d second_obj;
	show_who(base_obj); // доступ к who класса Base
	show_who(first_obj); // доступ к who класса first_d
	show_who(second_obj); // доступ к who класса second_d
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
	// who() не определяется
};
int main()
{
	Base base_obj;
	Base *p;
	first_d first_obj;
		second_d second_obj;
	p = &base_obj;
	p->who(); // доступ к who класса Base
	p = &first obj;
	p->who(); // доступ к who класса first_d
	p = &sepond_obj;
	p->who(); /* доступ к who() класса Base, поскольку second_d не переопределяет 
	return 0;
}

Эта программа выдаст следующий результат :

Base
First derivation
Base

Надо иметь в виду, что характеристики наследования носят иерархический характер.
Чтобы проиллюстрировать это, предположим, что в предыдущем примере класс second_d
порожден от класса first_d вместо класса Base.Когда функцию who() вызывают,
используя указатель на объект типа second_d(в котором функция who() не определялась),
то будет вызвана версия функции who(), объявленная в классе first_d,
поскольку этот класс — ближайший к классу second_d.В общем случае, когда класс
не переопределяет виртуальную функцию, С++ использует первое из определений, которое он находит,
идя от потомков к предкам.*/