

#ifndef C_H_
#define C_H_

char* pStack;
int size = 0;

const int SIZE = 12;
//��ʼ��ջ
void InitStack();
//��ջ
void push(char num);
//��ջ
void pop();
//����ջ
void look();
//�ж�ջ�Ƿ�����
bool isfull();
//�ж�ջ�Ƿ�Ϊ��
bool isempty();

void InitStack()
{
	pStack = nullptr;
}

void push(char num)
{
	char* pNew = new char[size + 1];
	if (pStack != nullptr)
	{
		memcpy(pNew, pStack, sizeof(char) * size);
		free(pStack);
	}
	pStack = pNew;
	pStack[size++] = num;
}

void pop()
{
	if (!isempty())
	{
		char* pNew = new char[size - 1];
		memcpy(pNew, pStack, sizeof(char) * (size - 1));
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


#endif // !C_H_
