#include <iostream>
#include <conio.h>
#include <ctime>
#include "c.hpp"
using Chioce = int;
//const int SIZE = 12;
//extern const int SIZE;
#define OK 1
#define NO 0
int main()
{
#if 1
	Chioce cfg;
	char secrt[SIZE]{};	//����
	char secrt1[SIZE]{};	//�ظ�
	while (1)
	{
		std::cout << "����������:(Ӧ����С�ڵ���12λ�����֣���ĸ�����ŵ����)" << std::endl;
		std::cin >> secrt;
		std::cout << "���ٴ���������:" << std::endl;
		std::cin >> secrt1;
		if (!strcmp(secrt, secrt1))
		{
			std::cout << "�������óɹ�!" << std::endl;
			break;
		}
		else
		{
			std::cout << "��������ǰ��һ��:" << std::endl;
		}
	}
	InitStack();
	char* ch = new char[SIZE];
	//�������Ļ���
	for (int j = 5; j >0; j--)
	{
		std::cout << "����������:(ʣ�����:" << j << ")" << std::endl;
		int i = 0;
		for (; i < SIZE; i++)
		{
			ch[i] = _getch();		//��ȡ��������
			push(ch[i]);			//�ַ���ջ
			_putch('*');
			if (ch[i] == '\r')		//�س��˳�
				break;
			if (ch[i] == '\b')
			{
				char* pNew = new char[i - 1];
				memcpy(pNew, ch, sizeof(char) * (i - 1));
				free(ch);
				ch = pNew;
				i--;
			}			//�˸��ջ
		}
		ch[i] = '\0';
		_putch('\n');
		//�Ƚ���֤��¼����
		if (!strcmp(secrt, ch))
		{
			goto end;	
		}
		else
		{
			std::cout << "�������,����������!" << std::endl;
		}
		system("cls");
	}
end:;
	std::cout << "������ȷ! ��½�ɹ�!" << std::endl;

#endif

	return 0;
}