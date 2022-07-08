#include <iostream>
#include <cstdlib>

const int SIZE = 10;
int* pStack;		//ָ��ջ��ָ��
int size = 0;	//�洢ջ��Ԫ�ظ���

//��ʼ��ջ
void InitStack();
//��ջ
void push(int num);
//��ջ
void pop();
//����ջ
void look();
//�ж�ջ�Ƿ�����
bool isfull();
//�ж�ջ�Ƿ�Ϊ��
bool isempty();

int main()
{
	InitStack();
	for (int i = 0; i < 10; i++)
	{
		push(i);
		look();
		std::cout<<std::endl;
	}
	pop();
	look();

	return 0;
}

void InitStack()
{
	pStack = nullptr;
}

void push(int num)
{
	int* pNew = new int[size + 1];
	if (pStack!=nullptr)
	{
		memcpy(pNew, pStack, sizeof(int)*size);
		free(pStack);
	}
	pStack = pNew;
	pStack[size++] = num;
}

void pop()
{
	if (!isempty())
	{
		int* pNew = new int[size - 1];
		memcpy(pNew, pStack, sizeof(int)*(size - 1));
		free(pStack);
		pStack = pNew;
		size--;
	}
}

bool isfull()
{
	return size == SIZE;
}

bool isempty()
{
	return size == 0;
}

void look()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << pStack[i] << " ";
	}
}
