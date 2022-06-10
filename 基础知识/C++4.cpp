#include <iostream>
#include <string>	//string类
#include <string.h>
#include <vector>
#include <array>
using namespace std;

//普通的cin输入
//int main(void)
//{
//	const int Size = 20;
//	char name[Size];
//	char fav[Size];
//	cout << "请输入你的姓名:";
//	cin>>name;
//
//	cout << "请输入你最喜欢的水果:";
//	cin>>fav;
//	cout << "欢迎你:" << name << endl << "你最喜欢的水果是:" << fav << endl;
//	return 0;
//}


//每次读取一行字符串输入
// getline丢弃换行符
//int main(void)
//{
//	const int Size = 20;
//	char name[Size];
//	char fav[Size];
//	cout << "请输入你的姓名:";
//	cin.getline(name, Size);
//
//	cout << "请输入你最喜欢的水果:";
//	cin.getline(fav, Size);
//	cout << "欢迎你:" << name << endl << "你最喜欢的水果是:" << fav << endl;
//	return 0;
//}


//使用get来读取整行，不
//int main(void)
//{
//	const int Size = 20;
//	char name[Size];
//	char fav[Size];
//	cout << "请输入你的姓名:";
//	//cin.get(name, Size);
//	////会有一个换行符在缓冲里
//	//cin.get();
//	cin.get(name, Size).get();	//连续读取，相同的作用
//	cout << "请输入你最喜欢的水果:";
//	cin.get(fav, Size);
//	cout << "欢迎你:" << name << endl << "你最喜欢的水果是:" << fav << endl;
//	return 0;
//}


//混合输入字符串和数字
//int main()
//{
//	cout << "What year was your house bulit?";
//	int year;
//	cin >> year;
//	//混合输入，会有换行存在
//	//cin.get();
//	//第二种方法
//	//(cin >> year).get();
//	cout << "What is its street address?" << endl;
//	char address[80];
//	cin.getline(address, 80);
//
//	cout << "Year bulit: " << year << endl;
//	cout << "Address: " << address << endl << "Done!" << endl;
//	return 0;
//}


//使用string类
//int main()
//{
//	//列表初始化
//	string str1 = "woaini ylh";
//	string str2 = "lxy woaini";
//	//将一个string类直接复制给另一个string
//	string str = str1;
//	//可以使用+运算符合并字符串
//	string stra = str1+str2;
//	str1 += str2;
//	string name;
//	cout << "请输入你的名字:";
//	cin >> name;
//	cout << "欢迎你! " << name<<endl;
//	//可以使用数组表示法来访问存储在string里的字符
//	cout << name[4] << endl;
//	cout << str1 << endl << stra << endl;
//	return 0;
//}


//c++字符串与c字符串的操作比较
//int main()
//{
//	string str1 = "woshiyihao";
//	string str2;
//	char arr1[20] = "woshiyihao";
//	char arr2[20];
//
//	//字符串的复制
//	str2 = str1;
//	strcpy(arr2, arr1);
//
//	//字符串拼接
//	str2 += "JUASD";
//	strcat(arr2, "ASDIJ");
//
//	//字符串长度
//	cout << "The str2 is " << str2 << ",lengh is " << str2.size() << endl;
//	cout << "The arr2 is " << arr2 << ",lengh is " << strlen(arr2) << endl;
//
//	return 0;
//}


//
//int main()
//{
//	string str1 = "woaini";
//	string str2;
//
//	//分别使用L u U来标记
//	wchar_t arr1[] = L"I love China";
//	char16_t arr2[] = u"I love China";
//	char32_t arr3[] = U"I love china";
//
//	//原始字符串，直接显示在字符串的内容 R标记
//	cout << R"("我\n是\n个\n原\n始\n字\n符\n串"!)" << endl;
//	//使用 "+*( 标记开头, )+*" 标记结尾
//	cout << R"+*("我\n是\n个\n原\n始\n字\n符\n串"!)+*" << endl;
//
//	cout << "请输入:";
//	//另一种写法 cin.getline
//	getline(cin, str2);
//	cout << "str: " << str2 << endl;
//	return 0;
//}


//使用结构
//struct Info
//{
//	string name;
//	double n;
//	float f;
//};
//int main()
//{
//	//省略struct关键字
//	//初始化列表
//	Info Peo{"与良好",20,91};
//	//cout << "于良浩" << Peo.name;
//	//cin >> Peo.n;
//	cout << Peo.n << endl;
//	cout << Peo.name << endl;
//	//同一个类型的结构可以使用 = 来复制
//
//	return 0;
//}


//关于指针
//int main()
//{
//	int a = 6;
//	int* p = &a;
//	int* q;
//	q = (int*) 0x00012;
//	cout << "p=" << p << endl;
//	cout << "&a=" << &a << endl;
//	cout << "a=" << a << endl;
//	cout << "*p=" << *p << endl;
//	cout << "*p+1=" << *p+1 << endl;
//
//	return 0;
//}


//动态内存分配
//int main()
//{
//	int night = 1001;
//	//为指针分配一个int的空间
//	int* p = new int;
//	*p = 95;
//	cout << "night= " << night << endl;
//	cout << "*p= " << *p << endl;
//	cout << "&p= " << p << endl;
//
//	double* pd = new double;
//	*pd = 999;
//	cout << "*pd= " << *pd << endl;
//	cout << "&pd= " << pd << endl;
//	//释放内存
//	delete p;
//	delete pd;
//	return 0;
//}


//数组的动态与静态联编
//int main()
//{
//	//new后面加上 类型名与大小
//	//表示10个元素的数组
//	int* ps = new int[10];
//	int* s = ps;
//	
//	for (int i = 0; i < 10; i++)
//	{
//		ps[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << s[i] << " " << endl;
//	}
//	cout << ps << endl;
//	cout << &ps << endl;
//	//释放整个数组
//	//如果分配时有方括号，则释放时也应该有方括号
//	//不允许不匹配方括号
//	delete[]ps;
//	return 0;
//}



//使用new结构
//struct inflo
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	//为结构分配空间
//	inflo* Peo = new inflo;
//	cout << "请输入姓名:";
//	cin.getline(Peo->name, 20);
//	cout << "欢迎你，" << Peo->name << endl;
//
//	return 0;
//}


//new delete实例
//char* getname()
//{
//	char temp[80];
//	cout << "请输入字符串:";
//	cin >> temp;
//	//创建动态的字符串数组
//	char* ps = new char[strlen(temp) + 1];
//	strcpy(ps, temp);
//	//返回指针
//	return ps;
//}
//int main()
//{
//	char* name;
//	name = getname();
//	cout << name << " at " << (int*)name << endl;
//	//释放
//	delete []name;
//	return 0;
//}




//模板类
//#include <vector>
//#include <array>
//int main()
//{
//	/*
//	vector
//	*/
//	//长度可变 功能强大
//	//vi是一个vector<int>的对象
//	//创建一个名为vi的vector对象，可以存储n个类型为<int>的元素,元素个数可以是常量，也能是变量
//	vector<int> vi;
//	int n;
//	cin >> n;
//	//vd是一个victor<double>的对象
//	vector<double> vd(n);
//
//	/*
//	array
//	*/
//	//长度固定 使用栈内存
//	//分别创建5个元素和4个元素的数组
//	//元素个数不能是变量
//	array<int, 5> ai;
//	array<double, 4> ad = { 1.1,2.2,3.3,4., };
//	cout << ad[0] << endl;
//	return 0;
//}



//一个简单的实例 数组 vector array
int main()
{
	//数组
	double a[4] = { 1.1,2.2,3.3,4.4 };
	//vector模板
	vector<double> b(4);	//注意是圆括号
	for (int i = 0; i < 4; i++)
	{
		b[i] = (double)i+1;
	}
	//array模板
	array<double, 4> c = { 5.5,6.6,7.7,8.8 };
	array<double, 4> d = c;	//可以直接将一个array对象复制为另一个array变量
	cout << "数组: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout  << a[i]<<" ";
	}
	cout << endl;
	cout << "vector: " << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "array: " << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	//vector和array对象具有成员函数 at()可以捕获错误的输入索引
	vector<int> e(4);
	e.at(0) = 9;
	cout << e[0] << endl;
	return 0;
}
