#include "stdafx.h"
#include "Header.h"

void container::In(ifstream &ReadFile)
{
	Node *temp;
	Node *Help = NULL;
	while (!ReadFile.eof()) {
		temp = new Node;
		temp->info = type::In(ReadFile);
		++len;

		if (head == NULL)
		{
			temp->next = temp;
			head = temp;
			Help = temp;
		}
		else//порядок элементов будет отличаться, от процедурного
		{
			temp->next = head;
			Help->next = temp;                    //Запись данных в следующее за последним элементом поле
			Help = temp;                          //Последний активный элемент=только что созданный.
		}
	}
}

void container::Out(ofstream &WriteFile)
{
	Node *current = head;
	for (int i = 0; i < len; i++) {
		WriteFile << i + 1 << ": ";
		if (len > 0)
		{
			current->info->Out(WriteFile);
			current = current->next;
		}
	}
}

void container::Clear()
{
	while (len > 0)
	{
		if (len == 1)
		{
			Node *temp = head;
			head = NULL;
			free(temp);
			len = len - 1;
			break;
		}
		Node *temp;
		temp = head->next;
		while (temp->next != head)
			temp = temp->next;

		temp->next = head->next;
		free(head);
		head = temp;
		len = len - 1;
	}
}

void container::Sorting()
{
	
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (head->info->Count() > head->next->info->Count())
			{
				Node *prediudushiy = head;

				while (prediudushiy->next != head)
					prediudushiy = prediudushiy->next;

				Node *next1 = head->next;
				Node *next2 = head->next->next;

				next1->next = head;
				head->next = next2;
				prediudushiy->next = next1;
				head = next1;
			}
			head = head->next;
		}
		head = head->next;
	}
}

container::container()
{
	head = NULL;
	len = 0;
}

type* type::In(ifstream &ReadFile)
{

	type *temp;	//Временные указатели
	int k;
	ReadFile >> k;
	switch (k) {
	case 1:
		temp = new complex;
		break;
	case 2:
		temp = new shot;
		break;
	case 3:
		temp = new polar;
		break;
	default:
		return 0;
	}

	temp->InData(ReadFile);
	return temp;
}


void complex::InData(ifstream &ReadFile)
{
	ReadFile >> number1;
	ReadFile >> number2;
	getline(ReadFile, metric, ' ');
}

void complex::Out(ofstream &WriteFile)
{

	WriteFile << "Комплексное число:    Z=" << Count() << "|||"  << number1;
	if (number2 > 0)
		WriteFile << "+" << number2 << "i   || Е. И: " << metric << endl;
	else
		WriteFile << number2 << "i   || Е. И: " << metric << endl;
}

float complex::Count()
{
	double Sort = 0;
	Sort = round(sqrt(number1*number1 + number2 * number2) * 100) / 100;
	return Sort;
}


void shot::InData(ifstream &ReadFile)
{
	ReadFile >> number1;
	ReadFile >> number2;
	getline(ReadFile, metric, ' ');
}

void shot::Out(ofstream &WriteFile)
{
	int Nod;
	WriteFile << "Дробь:   " << Count() << "|||";
	Nod = NOD(number1, number2);
	WriteFile << number1 / Nod << "/" << number2 / Nod << "|| Е. И: " << metric << endl;
}

float shot::Count()
{
	double Sort = 0;
	Sort = round((number1 / number2) * 100) / 100; //до второго занака после запятой
	return Sort;
}

void container::FiltredOut(ofstream &WriteFile)
{
	Node *temp = head;
	WriteFile << endl << "Только дроби:" << endl;
	for (int i = 0; i < len; i++)
	{
		temp->info->OutOnlyShot(WriteFile);
		temp = temp->next;
	}
}


void type::OutOnlyShot(ofstream &WriteFile) //void complex::OutOnlyShot(ofstream &WriteFile)
{
	exit;
}

void shot::OutOnlyShot(ofstream &WriteFile)
{
	Out(WriteFile);
}




int NOD(int a, int b)
{
	while ((a && b) != 0)
		if (a >= b)
			a %= b;
		else
			b %= a;
	return a | b;
}

void polar::InData(ifstream &ReadFile)
{
	ReadFile >> radius;
	if (radius < 0)
		radius = -radius;
	ReadFile >> angle;
	if ((angle < 0) || (angle > rad))
		angle = rad;
	getline(ReadFile, metric, ' ');
}

void polar::Out(ofstream &WriteFile)
{
	WriteFile << "Полярные координаты:   ";
	WriteFile << "(" << radius << ";" << angle << ")" << "|| Е. И: " << metric << endl;
}

float polar::Count()
{
	double Sort = 0;
	Sort = angle;
	return Sort;
}
