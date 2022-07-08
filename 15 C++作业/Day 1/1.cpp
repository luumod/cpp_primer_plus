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
	char secrt[SIZE]{};	//密码
	char secrt1[SIZE]{};	//重复
	while (1)
	{
		std::cout << "请设置密码:(应输入小于等于12位的数字，字母，符号的组合)" << std::endl;
		std::cin >> secrt;
		std::cout << "请再次输入密码:" << std::endl;
		std::cin >> secrt1;
		if (!strcmp(secrt, secrt1))
		{
			std::cout << "密码设置成功!" << std::endl;
			break;
		}
		else
		{
			std::cout << "密码输入前后不一致:" << std::endl;
		}
	}
	InitStack();
	char* ch = new char[SIZE];
	//五次输入的机会
	for (int j = 5; j >0; j--)
	{
		std::cout << "请输入密码:(剩余次数:" << j << ")" << std::endl;
		int i = 0;
		for (; i < SIZE; i++)
		{
			ch[i] = _getch();		//读取键盘输入
			push(ch[i]);			//字符入栈
			_putch('*');
			if (ch[i] == '\r')		//回车退出
				break;
			if (ch[i] == '\b')
			{
				char* pNew = new char[i - 1];
				memcpy(pNew, ch, sizeof(char) * (i - 1));
				free(ch);
				ch = pNew;
				i--;
			}			//退格出栈
		}
		ch[i] = '\0';
		_putch('\n');
		//比较验证登录密码
		if (!strcmp(secrt, ch))
		{
			goto end;	
		}
		else
		{
			std::cout << "密码错误,请重新输入!" << std::endl;
		}
		system("cls");
	}
end:;
	std::cout << "密码正确! 登陆成功!" << std::endl;

#endif

	return 0;
}