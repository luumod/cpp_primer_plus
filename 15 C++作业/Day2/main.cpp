//C++�Ӻ����ķ�ʽʵ�ֶ�ά������ڴ�������ͷ�
//1.����ֵ�ķ�ʽ
//2.���εķ�ʽ
//3.���εķ�ʽ�ͷ��ڴ�

#include <iostream>
using std::cout;
using std::endl;

const int ROW = 4;
const int COL = 3;
//1.����ֵ�ķ�ʽ
int** Return_Value()
{
	int** p = new int* [ROW];		//�������ڴ�
	for (int i = 0; i < ROW; i++)
	{
		p[i] = new int[COL];		//�������ڴ�
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			p[i][j] = 1;
		}
	}
	return p;					//���ض�ά����
}

//2.���εķ�ʽ
int** Transfer_Parameters(int** p)
{
	p = new int* [ROW];		//�������ڴ�
	for (int i = 0; i < ROW; i++)
	{
		p[i] = new int[COL];		//�������ڴ�
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			p[i][j] = 2;
		}
	}
	return p;
}

//3.���εķ�ʽ�ͷ��ڴ�
void Delete(int** p)
{
	for (int j = 0; j < COL; j++)
	{
		delete[]p[j];
	}
	delete[]p;
}

//��������
void Show(int** p)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int** p1 = Return_Value();
	Show(p1);

	cout << endl;
	int** p2 = nullptr;
	p2 = Transfer_Parameters(p2);
	Show(p2);

	Delete(p1);
	Delete(p2);
	return 0;
}