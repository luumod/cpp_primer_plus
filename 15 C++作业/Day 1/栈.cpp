#include <iostream>
#include <cstdlib>

const int SIZE = 10;
int* pStack;		//指向栈的指针
int size = 0;	//存储栈的元素个数

//初始化栈
void InitStack();
//入栈
void push(int num);
//出栈
void pop();
//遍历栈
void look();
//判断栈是否已满
bool isfull();
//判断栈是否为空
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
