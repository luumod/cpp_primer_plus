//用C++ 子函数的方式实现模拟登录 
// _getch() 函数
//
//自己加头文件
#include <conio.h>
const int SIZE = 12;
void Input(char* userName, char* passWord)
{
	char str;
	int i = 0;
	std::cout << "-------登录系统-------" << std::endl;
	std::cout << "请输入用户名: " << " ";
	std::cin >> userName;
	std::cout << "请输入密码: " << " ";
	while (i <= SIZE)
	{
		str = _getch();
		if (str == '\r')
		{
			break;				//回车确定输入
		}
		passWord[i++] = str;
		_putch('*');			//密码不可见
	}
	passWord[i] = '\0';
	//登录实现密码不可见： 输入密码时候要不可见 _getch 把字符当字符串
}
int  Login(char* username, char* passWord, const char* root = "1173012900", const char* pass = "12345")
{
	if (!strcmp(username, root))
	{
		std::cout << root<<" 正在登录..." << std::endl;
		_sleep(2000);
		if (!strcmp(passWord, pass))
		{
			return 1;
		}
	}
	return 0;
	//比较验证    
}