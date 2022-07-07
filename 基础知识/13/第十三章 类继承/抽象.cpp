

#include <iostream>
#include <string>
#include "�������.h"

const int CLIENTS = 4;
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	//ָ������ ����ʾ��̬��
	AcctABC* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "������˿�����: ";
		getline(cin, temp);
		cout << "�������˺�: ";
		cin >> tempnum;
		cout << "���������: ";
		cin >> tempbal;
		cout << "������ 1 �����������; 2 �������������� ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			;
		if (kind == '1')
		{
			//����������
			p_clients[i] = new Brass(temp, tempnum, tempbal);		//(temp, tempnum, tempbal)
		}
		else
		{
			double tempmax, temprate;
			cout << "�������������: ";
			cin >> tempmax;
			cout << "������������: ";
			cin >> temprate;
			//����������
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tempmax, temprate);
		}
		while (cin.get() != '\n')
			;
	}
	cout << "\n";
	/*
	��̬��:
		��������Ա��Brass  ����Brass::ViewAcct����
		��������Ա��BrassPlus  ����BrassPlus::ViewAcct����
	*/
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}

	cout << "Done! " << endl;
	return 0;
}
