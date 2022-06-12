#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//int main()
//{
//	int x, y, z;
//	x = y = z = 1;
//	cout << x << y << z << endl;
//	return 0;
//}

//int main()
//{
//	int x;
//	cout << "The expression x=100 has the value";
//	cout << (x = 100) << endl;
//	cout << "Now x= " << x << endl;
//	cout << "The expression x<3 has the value ";
//	cout << (x < 3) << endl;
//	cout << "The expression x>3 has the value ";
//	cout << (x > 3) << endl;
//	//显示布尔值
//	cout.setf(ios::boolalpha);
//
//	cout << "The expression x<3 has the value ";
//	cout << (x < 3) << endl;
//	cout << "The expression x>3 has the value ";
//	cout << (x > 3) << endl;
//	return 0;
//}



//阶乘
//const int SIZE=16;
//int main()
//{
//	long long num[SIZE];
//	num[0] = num[1] = 1LL;
//	for (int i = 2; i < SIZE; i++)
//	{
//		num[i] = i * num[i - 1];
//	}
//	for (int i = 0; i < SIZE; i++)
//	{
//		cout << i << "!" << " = " << num[i] << endl;
//	}
//	return 0;
//}

//
//int main()
//{
//	int num;
//	cout << "请输入步长:";
//	cin >> num;
//	for (int i = 0; i < 100; i += num)
//	{
//		cout << i << endl;
//	}
//	return 0;
//}


//反向字符串
//int main()
//{
//	string str;
//	cout << "请输入字符串:";
//	getline(cin, str);
//	for (int i = str.size() - 1; i >= 0; i--)
//	{
//		cout << str[i];
//	}
//	return 0;
//}


//相同的变量
//int main()
//{
//	int x = 20;
//	{
//		cout << x << endl;
//		//隐藏第一个x
//		int x = 100;
//		cout << x << endl;
//		//x消失
//	}
//	cout << x << endl;
//
//	return 0;
//}


//使用string类来比较字符串
//int main()
//{
//	string str = "1ate";
//	for (char ch = 'a'; str != "mate"; ++ch)
//	{
//		cout << str << endl;
//		str[0] = ch;
//		//int(ch)显示ASCII码
//		//cout << int(ch) << endl;
//	}
//	cout << "str= " << str << endl;
//	return 0;
//}



//创建延迟循环
//int main()
//{
//	cout << "Enter the delay time,in seconds: ";
//	float secs;
//	//输入延迟秒数
//	cin >> secs;
//	//得到系统时间单位的时间
//	clock_t delay = secs * CLOCKS_PER_SEC;
//	cout << "starting\a" << endl;
//	//获取开始的系统时间
//	clock_t start = clock();
//	while ((clock() - start) < delay)
//		;
//	cout << "Done!\a" << endl;
//	return 0;
//}



//基于范围的for循环
//int main()
//{
//	double num[5] = { 1.1,2.2,3.3,4.4,5.5 };
//	//显示数组中的每个元素
//	for (double x : num)
//		cout << x << endl;
//	cout << endl;
//	//修改数组中的元素  引用操作
//	for (double& x : num)
//		x = x * 0.8;
//	for (double x : num)
//		cout << x << endl;
//	return 0;
//}



//输入字符串 获得字符的个数
//int main()
//{
//	//第一次尝试: cin
//#if 0
//	int count = 0;
//	char ch;
//	cout << "请输入字符串:";
//	cin >> ch;
//	//cin 输入会忽略空格和回车
//	//遇到#号时停止，否则继续
//	while (ch != '#')
//	{
//		cout << ch;
//		cin >> ch;
//		count++;
//	}
//	cout << endl << count << "个字符" << endl;
//#elif 0
//	//第二次尝试: cin.get(char)
//	int count = 0;
//	char ch;
//	cout << "请输入字符串:";
//	cin.get(ch);
//	//cin.get 不会忽略空行
//	//遇到#号时停止，否则继续
//	while (ch != '#')
//	{
//		cout << ch;
//		cin.get(ch);
//		count++;
//	}
//	cout << endl << count << "个字符" << endl;
//	
//#elif 0
//	int count = 0;
//	char ch;
//	cout << "请输入字符串:";
//	//cin.get(ch);
//	//cin.get 不会忽略空行
//	//表示没有到达文件或输入的结尾
//	//使用CTRL+Z + 回车来模拟 EOF 结束
//	//while (cin.fail()==false)
//	//while (cin)	//最简单的写法
//	while (cin.get(ch))
//	{
//		cout << ch;
//		//cin.get(ch);
//		count++;
//	}
//	cout << endl << count << "个字符" << endl;
//#elif 1
//	int count = 0;
//	int ch;
//	while ((ch = cin.get()) != EOF)
//	{
//		cout.put(char(ch));
//		count++;
//	}
//	cout << endl << count << "个字符" << endl;
//#endif
//	return 0;
//}


