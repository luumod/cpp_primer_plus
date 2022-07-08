

#ifndef C_H_
#define C_H_

char* pStack;
int size = 0;

const int SIZE = 12;
//初始化栈
void InitStack();
//入栈
void push(char num);
//出栈
void pop();
//遍历栈
void look();
//判断栈是否已满
bool isfull();
//判断栈是否为空
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
