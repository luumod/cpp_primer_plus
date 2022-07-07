#include <iostream>
#include "���м̳��������.h"
using std::cout;
using std::cin;
using std::endl;


/*
���ؼ̳�  �������
*/
#if 0
Worker::~Worker()
{}

void Worker::Set()
{
	cout << "�����빤������: ";
	getline(cin, fullname);
	cout << "�����빤��ID: ";
	cin >> id;
	while (cin.get() != '\n')
		;
}

void Worker::Show() const
{
	cout << "Name: " << fullname << endl;
	cout << "ID: " << id << endl;
}

//������
void Waiter::Set()
{
	Worker::Set();	//���û����Ա����
	cout << "���������ߵ���������: ";
	cin >> panache;
	while (cin.get() != '\n')
		;
}

void Waiter::Show() const
{
	cout << "������Ϣ: " << endl;
	Worker::Show();
	cout << "����: " << panache << endl;
}


void Singer::Set()
{
	Worker::Set();
	cout << "����ĸ��ֵ���ɫ����: ";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "��������!" << endl;
	while (cin.get() != '\n')
		;
}
void Singer::Show()const
{
	cout << "������Ϣ: ";
	Worker::Show();
	cout << "���֣� " << pv[voice] << endl;
}
#endif



/*
�����
*/
#if 1  
Worker::~Worker()
{}

void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "ID: " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "�����빤��ID: ";
	cin >> id;
	while (cin.get() != '\n')
		;
}


//����
void Waiter::Set()
{
	cout << "������������Ϣ: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "������Ϣ: " << endl;
	Worker::Data();
	Data();
}

void Waiter::Data() const
{
	cout << "����: " << panache << endl;
}

void Waiter::Get()
{
	cout << "������������: ";
	cin >> panache;
	while (cin.get() != '\n')
		;
}

//���ּ�
void Singer::Set()
{
	cout << "���������Ϣ: ";
	Worker::Get();
	Get();
}

void Singer::Show()const
{
	cout << "������Ϣ: " << endl;
	Worker::Data();
	Data();
}

void Singer::Data()const
{
	cout << "��ɫ: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "����ĸ��ֵ���ɫ: ";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "��������!" << endl;
	while (cin.get() != '\n')
		;
}

//��������
void SingerWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();
}

void SingerWaiter::Get()
{
	Singer::Get();
	Waiter::Get();
}

void SingerWaiter::Set()
{
	cout << "�������������ҵ���Ϣ: ";
	Worker::Get();
	Get();
}

void SingerWaiter::Show()const
{
	cout << "�������ҵ���Ϣ: ";
	Worker::Data();
	Data();
}

#endif