#include "stdafx.h"
#include "Header.h"


Container::Container()
{
	head = NULL;
	len = 0;
}

void Container::In(ifstream &ReadFile)
{
	Node *temp;
	Node *Help = NULL;
	while (!ReadFile.eof()) {
		temp = new Node;
		temp->info = Type::In(ReadFile);
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

void Container::Out(ofstream &WriteFile)
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

void Container::Clear()
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

void Container::Sorting()
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

void Container::FiltredOut(ofstream &WriteFile)
{
	Node *temp = head;
	WriteFile << endl << "Только дроби:" << endl;
	for (int i = 0; i < len; i++)
	{
		temp->info->OutOnlyShot(WriteFile);
		temp = temp->next;
	}
}

void Container::MultiMethod(ofstream &WriteFile)
{
	Node *current_first = head;
	Node *current_second = current_first->next;

	WriteFile << "Multimethod." << endl;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			current_first->info->MultiMethod(current_second->info, WriteFile);
			current_first->info->Out(WriteFile);
			current_second->info->Out(WriteFile);
			current_second = current_second->next;
		}
		current_first = current_first->next;
		current_second = current_first->next;
	}

}
void Complex::MultiMethod(Type *other, ofstream &WriteFile)
{
	other->MMComplex(WriteFile);
}

void Complex::MMComplex(ofstream &WriteFile)
{
	WriteFile << "COMPLEX and COMPLEX." << endl;
}

void Complex::MMShot(ofstream &WriteFile)
{
	WriteFile << "SHOT and COMPLEX." << endl;
}

void Complex::MMPolar(ofstream &WriteFile)
{
	WriteFile << "Polar and COMPLEX." << endl;
}

void Shot::MultiMethod(Type *other, ofstream &WriteFile)
{
	other->MMShot(WriteFile);
}

void Shot::MMComplex(ofstream &WriteFile)
{
	WriteFile << "COMPLEX and SHOT." << endl;
}

void Shot::MMShot(ofstream &WriteFile)
{
	WriteFile << "SHOT and SHOT." << endl;
}

void Shot::MMPolar(ofstream &WriteFile)
{
	WriteFile << "POLAR and SHOT." << endl;
}

void Polar::MultiMethod(Type *other, ofstream &WriteFile)
{
	other->MMPolar(WriteFile);
}

void Polar::MMComplex(ofstream &WriteFile)
{
	WriteFile << "COMPLEX and POLAR." << endl;
}

void Polar::MMShot(ofstream &WriteFile)
{
	WriteFile << "SHOT and POLAR." << endl;
}

void Polar::MMPolar(ofstream &WriteFile)
{
	WriteFile << "POLAR and POLAR." << endl;
}


Type* Type::In(ifstream &ReadFile)
{

	Type *temp;	//Временные указатели
	int k;
	ReadFile >> k;
	switch (k) {
	case 1:
		temp = new Complex;
		break;
	case 2:
		temp = new Shot;
		break;
	case 3:
		temp = new Polar;
		break;
	default:
		return 0;
	}

	temp->InData(ReadFile);
	return temp;
}

void Type::OutOnlyShot(ofstream &WriteFile) //void complex::OutOnlyShot(ofstream &WriteFile)
{
	exit;
}

void Complex::InData(ifstream &ReadFile)
{
	ReadFile >> number1;
	ReadFile >> number2;
	ReadFile >> metric;
}

void Complex::Out(ofstream &WriteFile)
{

	WriteFile << "Комплексное число:    Z=" << number1;
	if (number2 > 0)
		WriteFile << "+" << number2 << "i   || Е. И: " << metric << endl;
	else
		WriteFile << number2 << "i   || Е. И: " << metric << endl;
}

double Complex::Count()
{
	double Sort = 0;
	Sort = round(sqrt(number1*number1 + number2 * number2) * 100) / 100;
	return Sort;
}


void Shot::InData(ifstream &ReadFile)
{
	ReadFile >> number1;
	ReadFile >> number2;
	ReadFile >> metric;
}

void Shot::Out(ofstream &WriteFile)
{
	int Nod;
	WriteFile << "Дробь:   ";
	Nod = NOD(number1, number2);
	WriteFile << number1 / Nod << "/" << number2 / Nod << "|| Е. И: " << metric << endl;
}

double Shot::Count()
{
	double Sort = 0;
	Sort = round((number1 / number2) * 100) / 100; //до второго занака после запятой
	return Sort;
}

void Shot::OutOnlyShot(ofstream &WriteFile)
{
	Out(WriteFile);
}

void Polar::InData(ifstream &ReadFile)
{
	ReadFile >> radius;
	if (radius < 0)
		radius = -radius;
	ReadFile >> angle;
	if ((angle < 0) || (angle > 6.2))
		angle = 6.2;
	ReadFile >> metric;
}

void Polar::Out(ofstream &WriteFile)
{
	WriteFile << "Полярные координаты:   ";
	WriteFile << "(" << radius << ";" << angle << ")" << "|| Е. И: " << metric << endl;
}

double Polar::Count()
{
	double Sort = 0;
	Sort = angle;
	return Sort;
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
