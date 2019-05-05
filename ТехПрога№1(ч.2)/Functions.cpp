#include "stdafx.h"
#include "Header.h"

void container::In(ifstream &ReadFile)
{
	Node *temp;
	Node *Help = NULL;
	while (!ReadFile.eof()) {
		temp = new Node;
		if((temp->info = type::In(ReadFile)) != NULL)
		{
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
	
	string chek;
	ReadFile >> chek;

	if (chek == "\0")
	{
		return NULL;
	}

	if (chek.length()  > 1)
	{
		ReadFile.get();
		getline(ReadFile, chek, '\n');
		return NULL;
	}

	if (!isdigit(int(unsigned char(chek.front()))))
	{
		ReadFile.get();
		getline(ReadFile, chek, '\n');
		return NULL;
	}

	int k = stoul(chek);

	//int k;
	//ReadFile >> k;
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
	if (!temp->InData(ReadFile))
	{
		return NULL;
	}
	else
	{
		return temp;
	}
	//temp->InData(ReadFile);
	//return temp;
}


bool complex::InData(ifstream &ReadFile)
{

	string chek;
	string chek2;
	bool chekMinus = false;
	ReadFile >> chek;
	if (chek == "\0")
	{
		return false;
	}

	if (chek[0] == '-')
	{
		char *buff = new char[chek.size()-1];
		for (int i = 1; i < chek.size(); i++)
		{
			buff[i - 1] = chek[i];
		}
		buff[chek.size() - 1] = '\0';
		chek = buff;
		chekMinus = true;
	}

	for (int i = 0; i < chek.size(); i++)
	{
		if (!isdigit(double(unsigned char(chek[i]))))
		{
			ReadFile.get();
			getline(ReadFile, chek, '\n');
			return false;
		}
	}
	number1 = stoul(chek);
	if (chekMinus)
	{
		number1 = (-1)*number1;
	}
	ReadFile >> chek2;
	if (chek2 == "\0")
	{
		return false;
	}
	if (chek2[0] == '-')
	{
		char *buff = new char[chek2.size() - 1];
		for (int i = 1; i < chek2.size(); i++)
		{
			buff[i - 1] = chek2[i];
		}
		buff[chek2.size() - 1] = '\0';
		chek2 = buff;
		chekMinus = true;
	}

	for (int i = 0; i < chek2.size(); i++)
	{
		if (!isdigit(double(unsigned char(chek2[i]))))
		{
			ReadFile.get();
			getline(ReadFile, chek2, '\n');
			return false;
		}
	}
	number2 = stoul(chek2);
	if (chekMinus)
	{
		number2 = (-1)*number2;
	}
	getline(ReadFile, metric, '\n');
	return true;
}

void complex::Out(ofstream &WriteFile)
{

	WriteFile << "Комплексное число:    Z=" << number1;
	if (number2 > 0)
		WriteFile << "+" << number2 << "i   || Е. И: " << metric << endl;
	else
		WriteFile << number2 << "i   || Е. И: " << metric << endl;
}

double complex::Count()
{
	double Sort = 0;
	Sort = round(sqrt(number1*number1 + number2 * number2) * 100) / 100;
	return Sort;
}


bool shot::InData(ifstream &ReadFile)
{
	string chek;
	string chek2;
	bool chekMinus = false;
	ReadFile >> chek;
	if (chek == "\0")
	{
		return false;
	}

	if (chek[0] == '-')
	{
		char *buff = new char[chek.size() - 1];
		for (int i = 1; i < chek.size(); i++)
		{
			buff[i - 1] = chek[i];
		}
		buff[chek.size() - 1] = '\0';
		chek = buff;
		chekMinus = true;
	}

	for (int i = 0; i < chek.size(); i++)
	{
		if (!isdigit(double(unsigned char(chek[i]))))
		{
			ReadFile.get();
			getline(ReadFile, chek, '\n');
			return false;
		}
	}
	number1 = stoul(chek);
	if (chekMinus)
	{
		number1 = (-1)*number1;
	}
	ReadFile >> chek2;
	if (chek2 == "\0")
	{
		return false;
	}
	if (chek2[0] == '-')
	{
		char *buff = new char[chek2.size() - 1];
		for (int i = 1; i < chek2.size(); i++)
		{
			buff[i - 1] = chek2[i];
		}
		buff[chek2.size() - 1] = '\0';
		chek2 = buff;
		chekMinus = true;
	}

	for (int i = 0; i < chek2.size(); i++)
	{
		if (!isdigit(double(unsigned char(chek2[i]))))
		{
			ReadFile.get();
			getline(ReadFile, chek2, '\n');
			return false;
		}
	}
	number2 = stoul(chek2);
	if (chekMinus)
	{
		number2 = (-1)*number2;
	}
	getline(ReadFile, metric, '\n');
	return true;
}

void shot::Out(ofstream &WriteFile)
{
	int Nod;
	WriteFile << "Дробь:   ";
	Nod = NOD(number1, number2);
	WriteFile << number1 / Nod << "/" << number2 / Nod << "|| Е. И: " << metric << endl;
}

double shot::Count()
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

bool polar::InData(ifstream &ReadFile)
{
	string chek;
	string chek2;
	ReadFile >> chek;
	if (chek == "\0")
	{
		return false;
	}

	if (chek[0] == '-')
	{
		return false;
	}

	for (int i = 0; i < chek.size(); i++)
	{
		if (!isdigit(double(unsigned char(chek[i]))))
		{
			ReadFile.get();
			getline(ReadFile, chek, '\n');
			return false;
		}
	}
	radius = stoul(chek);
	ReadFile >> chek2;
	if (chek2 == "\0")
	{
		return false;
	}
	if (chek2[0] == '-')
	{
		return false;
	}

	for (int i = 0; i < chek2.size(); i++)
	{
		if (!isdigit(double(unsigned char(chek2[i]))))
		{
			ReadFile.get();
			getline(ReadFile, chek2, '\n');
			return false;
		}
	}
	angle = stoul(chek2);
	getline(ReadFile, metric, '\n');
	return true;
}

void polar::Out(ofstream &WriteFile)
{
	WriteFile << "Полярные координаты:   ";
	WriteFile << "(" << radius << ";" << angle << ")" << "|| Е. И: " << metric << endl;
}

double polar::Count()
{
	double Sort = 0;
	Sort = angle;
	return Sort;
}
