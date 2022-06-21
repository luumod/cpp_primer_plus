#include <iostream>
#include <string>
#include <array>
//using namespace std;
//
////使用...来表示参数可变的函数
//void say_be(...);
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		say_be();
//	}
//
//	return 0;
//}
//void say_be(...)
//{
//	printf("H");
//}

//const int ArSize = 8;
//int sum_arr(int arr[], int n);
//int main()
//{
//	int cookies[ArSize] = { 1,2,3,4,5,6,7,8 };
//	std::cout << cookies << "=array address, ";	//地址
//	std::cout << sizeof cookies << "=sizeof cookies";	//数组的长度
//	int sum = sum_arr(cookies, ArSize);
//	std::cout << "Total cookies eaten: " << sum << " cookies." << std::endl;
//
//	return 0;
//}
//int sum_arr(int arr[], int n)
//{
//
//	int total = 0;
//	std::cout << arr << "= arr";
//	std::cout << sizeof arr << "= sizeof arr" << std::endl;
//
//	for (int i = 0; i < n; i++)
//	{
//		total = total + arr[i];
//	}
//	return total;
//}

using namespace std;
const int ArSize = 8;

//int main()
//{
//	int a[5] = { 5,6, };
//	cout << sizeof a << endl;
//
//	return 0;
//}

//双指针初步
//int sum_arr(const int* begin, const int* end);
//int main()
//{
//	int c[ArSize] = { 1,2,3,4,5,6,7,8 };
//	int sum = sum_arr(c, c + ArSize);
//	cout << sum << endl;
//	sum = sum_arr(c + 2, c + 5);
//	cout << sum << endl;
//	return 0;
//}
//int sum_arr(const int* begin, const int* end)
//{
//	const int* pt;
//	int total = 0;
//
//	for (pt = begin; pt != end; pt++)
//	{
//		total += *pt;
//	}
//	return total;
//}
//
//void sum(int month[], int n);
//int main()
//{
//	int a = 5;
//	const int* p = &a;	//常量指针
//	// *p的值无法改变，但是p所指向的值可以改变
//	a = 6;
//	cout << *p << endl;
//
//	int b = 6, c = 1;
//	int* const q = &b;	//指针常量
//	// q = &c; 指针指向的位置不能改变	
//	*q = 5;	// *q的值可以改变
//	cout << *q << endl;
//
//	//不能使const类型的地址赋值给非const的指针
//	const int amont[5] = { 1,2,5,6,8 };
//	//sum(amont, 5); 不能使const的地址赋值给非const的指针
//	return 0;
//}


//char* builder(char c, int n);
//int main()
//{
//	unsigned int times;
//	char ch;
//	cout << "Enter a character:";
//	cin >> ch;
//	cout << "Enter an interger:";
//	cin >> times;
//	char* ps = builder(ch, times);
//	cout << ps << endl;
//	delete[]ps;	//释放空间
//	ps = builder('!', 20);
//	cout << ps << endl;
//	delete[]ps;
//	return 0;
//}
//char* builder(char c, int n)
//{
//	char* pstr = new char[n + 1];	//分配合适的空间
//	pstr[n] = '\0';
//	while (n-- > 0)
//	{
//		pstr[n] = c;
//	}
//	return pstr;
//}


//int main()
//{
//	int a, b;
//	/*
//	常用的处理错误输入手段
//	*/
//	while (!(cin >> a>>b))
//	{
//		cin.clear();
//		while (cin.get() != '\n')
//			continue;
//		cout << "Bad! again" << endl;
//	}
//	return 0;
//}


//string和函数
//const int SIZE = 5;
//void display(const string str[], int n);
//int main()
//{
//	string list[SIZE];
//	cout << "Enter your " << SIZE << "favourite words" << endl;
//	for (int i = 0; i < SIZE; i++)
//	{
//		cout << i + 1 << ":";
//		getline(cin, list[i]);
//	}
//	cout << "Your list:" << endl;
//	display(list, SIZE);
//	return 0;
//}
//void display(const string str[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << i + 1 << ": " << str[i] << endl;
//	}
//}


//使用array类
//const int season = 4;
//const array<string, season>Snames = { "Spring",
//"Summer","Fall","Winter" };
////使用array类的指针形参
//void fill(array<double, season>* pa);
//void show(array<double, season>da);
//
//int main()
//{
//	array<double, season> expenses;
//	fill(&expenses);//传址
//	show(expenses);	//传值
//	return 0;
//}
//void fill(array<double, season>* pa)
//{
//	for (int i = 0; i < season; i++)
//	{
//		cout << "Enter " << Snames[i] << "expenses: ";
//		cin >> (*pa)[i];
//	}
//}
//void show(array<double, season>da)
//{
//	double total = 0;
//	cout << "\nEXPENSES\n";
//	for (int i = 0; i < season; i++)
//	{
//		cout << Snames[i] << ":$" << da[i] << endl;
//		total += da[i];
//	}
//	cout << "Total Expenses: $" << total << endl;
//}



//递归
//void countdown(int n);
//int main()
//{
//	countdown(5);
//	return 0;
//}
//void countdown(int n)
//{
//
//	cout << "Counting down ..." << n << endl;
//	if (n > 0)
//		countdown(n - 1);
//	cout << n << ": Kaboom!" << endl;
//}


//递归的方便
//const int Len = 66;
//const int Divs = 6;
//void subdivde(char ar[], int low, int high, int level);
//
//int main()
//{
//	char ruler[Len];
//	for (int i = 1; i < Len - 2; i++)
//	{
//		ruler[i] = ' ';
//	}
//	ruler[Len - 1] = '\0';
//	int max = Len - 2, min = 0;
//	ruler[max] = ruler[min] = '|';
//	cout << ruler << endl;	//打印第一行
//	for (int i = 1; i <= Divs; i++)
//	{
//		subdivde(ruler, min, max, i);
//		cout << ruler << endl;
//		for (int j = 1; j < Len - 2; j++)
//		{
//			ruler[j] = ' ';
//		}
//	}
//	return 0;
//}
//void subdivde(char ar[], int low, int high, int level)
//{
//	if (level == 0)
//		return;
//	int mid = (high + low) / 2;
//	ar[mid] = '|';
//	subdivde(ar, low, mid, level - 1);
//	subdivde(ar, mid, high, level - 1);
//
//}


//函数指针
//double besty(int n);
//double pam(int n);
//void estimate(int line, double (*pf)(int));
//int main()
//{
//	estimate(100, besty);
//	estimate(100, pam);
//
//	return 0;
//}
//double besty(int n)
//{
//	return 0.05 * n;
//}
//double pam(int n)
//{
//	return 0.03 * n + 0.0004 * n * n;
//}
//void estimate(int line, double (*pf)(int))
//{
//	cout << line << ": will take " << (*pf)(line) << " hours" << endl;
//}

