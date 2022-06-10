#include <iostream>
#include <climits>
using namespace std;
//int main()
//{
//	unsigned long long a = ULLONG_MAX;
//	cout << "a_max=" << a<< endl;
//	return 0;
//}


//变量的初始化
//int main()
//{
//	/*int ros{};
//	int roa = {};
//	int rod{ 4 };
//	cout << ros << endl;
//	cout << roa << endl;
//	cout << rod << endl;*/
//	int a = 5, a8 = 011, a16 = 0x123;
//	cout << a << endl;
//	cout << a8 << endl;
//	cout << a16 << endl;
//	return 0;
//}


//C++特有
//int main()
//{
//	int a = 15;
//	int b = 80;
//	int c = 256;
//	char ch,ch2;
//	cout << "a=" << a << endl << hex;		//十进制
//	cout << "a=" << b << endl << oct;	//十六进制
//	cout << "a=" << c << endl << dec;	//八进制
//	cin >> ch;
//	cout << "ch=" << ch << endl << hex;
//	cin.get();	//吸收多余的回车
//	cin.get(ch2);	//相当于getchar
//	cout.put(ch) << endl;	//相当于putchar
//	cout.put(ch2) << endl;
//	return 0;
//}


//字符扩展
//int main(void)
//{
//	//宽字符类型,前缀L表示
//	wchar_t b = L'A';
//	wcout << L"tall" << endl;
//	wcout << b << endl;
//	//C++新增的类型,前缀u表示16位，前缀U表示32位
//	char16_t ch1 = u'a';
//	char32_t ch2 = U'\U0000222B';
//	cout << ch1 << endl;
//	cout << ch2 << endl;
//	//bool类型
//	bool is_ready = true;
//	cout << is_ready << endl;
//	return 0;
//}


//const限定符
//const int a = 12;	//用const代替#define
//int main()
//{
//	//字母大写 以字母k开头
//	const int Months = 12;
//	cout << a << endl;
//	cout << Months << endl;
//	double a = 9.11e-31;
//	cout << a << endl;
//	//下面这行代码防止将浮点后面的零清零
//	cout.setf(ios_base::fixed, ios_base::floatfield);
//	float n = 10.0 / 3.0;
//	double m = 10.0/3.0;
//	double million = 1.0e6;
//	//精度的差距
//	cout << "n=" << n << endl;
//	cout << "n=" << n*million << endl;
//	cout << "m=" << m << endl;
//	cout << "m=" << m*million << endl;
//
//	return 0;
//}



//强制类型转换
int main()
{
	int a, b, c;
	a = 19.99 + 11.99;

	b = (int)19.99 + (int)11.99;	//旧的C语言转换格式
	c = int(19.99) + int(11.99);	//新的C++的转换格式
	cout << "a=" << a << " b=" << b << " c=" << c << endl;
	char ch = 'Z';

	cout << "The code for " << ch << "is" << int(ch) << endl;
	//更严格的强制类型转换
	cout << "Yes,the code if " << static_cast<int>(ch) << endl;

	//auto 类型,自动识别
	auto x = 100;
	auto y = 1.3e9L;

	return 0;
}
