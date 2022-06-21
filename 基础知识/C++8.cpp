#include <iostream>
#include <ostream>
#include <fstream>
#include <istream>
using namespace std;
//引用变量

//int main()
//{
//	int a = 101, d = 5;
//	int* v = &d;
//	int& b= a;		//必须在声明引用时进行初始化
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//
//	b++;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//
//	cout << "a=" << &a << endl;
//	cout << "b=" << &b << endl;
//
//	b = 9;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//
//	int& p = *v;
//	v = &a;
//	cout << "v=" << *v << endl;
//	cout << p << endl;	//p引用的始终是以前的v值，其引用改变并不影响它自身 
//	return 0;
//}


//交换两个数字的值
//void change(int &a, int &b);
//int main()
//{
//	int a = 1,b = 5;
//	change(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}
//void change(int &a, int &b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}


//右值引用  &&
//int main()
//{
//	double&& a = sqrt(36.0);
//	double j = 5;
//	double&& t = 2 * j + 6;
//	cout << a << endl;
//	cout << t << endl;
//	return 0;
//}

//
//struct info
//{
//	char name[20];
//	int age;
//	int score;
//};
//info& change(info& a);
//int main()
//{
//	info stu = { "于良浩",18,99 };
//	info temp;
//	temp = change(stu);// 直接把一个结构复制为另一个结构
//	cout << stu.score<<endl;
//	cout << temp.score << endl;
//	return 0;
//}
//info& change(info& a)
//{
//	info w;
//	w = a;
//	a.score *= 2;
//	return w;	//返回一个引用
//}



//关于引用的一个习题
//struct A
//{
//	string name;
//	int made;
//	int attempts;
//	float precent;
//};
//void display(const A& ft);
//void set_pc(A& ft);
//A& accumulate(A& target, const A& source);
//int main()
//{
//	A one = { "我是一",11,11 };
//	A two = { "我是二",22,22 };
//	A three = { "我是三",33,33 };
//	A four = { "我是四",44,44 };
//	A five = { "我是五",55,55 };
//	A team = { "我是六",0,0 };
//	A dup;
//
//	/*set_pc(one);
//	display(one);
//	accumulate(team, one);
//	display(team);
//	cout << endl;
//	display(accumulate(team, three));*/
//
//	accumulate(accumulate(team, three), four);
//	display(team);
//	return 0;
//}
//void display(const A& ft)
//{
//	cout << "Name: " << ft.name << endl;
//	cout << " Made:" << ft.made << '\t';
//	cout << "Attempts" << ft.attempts << '\t';
//	cout << "Present: " << ft.precent << '\t';
//	cout << endl;
//}
//void set_pc(A& ft)
//{
//	if (ft.attempts != 0)
//		ft.precent = 100.0f * float(ft.made) / float(ft.attempts);
//	else
//		ft.precent = 0;
//}
//A& accumulate(A& target, const A& source)
//{
//	target.attempts += source.attempts;
//	target.made += source.made;
//	set_pc(target);
//	
//	return target;
//}



//string sum(const string &a, const string& b);
//string& sum2(string& a, const string& b);
//string& sum3(string& a, const string& b);
//int main()
//{
//	string n = "woaini";
//	string o = "***";
//	string r = sum3(o, n);	//返回o的引用，将会改变o的值
//	//此时o被引用修改
//	cout << o << endl;
//	cout << r << endl;
//	return 0;
//}
//string sum(const string &a, const string& b)
//{
//	string temp;
//	temp = a + b + a;
//	return temp;
//}
//string& sum2(string& a, const string& b)
//{
//	a = a + b + a;
//	return a;
//}
//string& sum3(string& a, const string& b)
//{
//	//程序试图引用已经释放的内存
//	string temp;
//	temp = a + b + a;
//	return temp;
//}


//ostream可以指向ostream对象cout和ofstream对象fout
//void file_it(ostream& os, double fo, const double fe[], int n);
//const int LIMIT = 5;
//int main()
//{
//	ofstream fout;
//	const char* fn = "ep-data.txt";
//	fout.open(fn);
//	if (!fout.is_open())
//	{
//		//打开失败
//		cout << "Cann't opne" << fn << ". Bye!" << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	double objective;
//	cout << "Enter the focal lenth of your "
//		"telescope object in mm: ";
//	cin >> objective;	//输入
//	double epes[LIMIT];
//	cout << "Enter the focal lengh in mm, of " << LIMIT << " eyepiceces:\n";
//	for (int i = 0; i < LIMIT; i++)
//	{
//		cout << "Eyepiece #" << i + 1 << ": ";
//		cin >> epes[i];
//	}
//	file_it(fout, objective, epes, LIMIT);
//	file_it(cout, objective, epes, LIMIT);
//	cout << "Done!" << endl;
//	return 0;
//}
//void file_it(ostream& os, double fo, const double fe[], int n)
//{
//	/*
//	ios_base::fmtflags 存储这种信息所需的数据类型的名称
//	*/
//	ios_base::fmtflags initial;	//存储调用file_it之前的格式化模式
//	//将对象置于使用定点表示法的模式
//	initial = os.setf(ios_base::fixed);
//	//指定显示多少位小数
//	os.precision(0);
//	os << "Focal length of object: " << fo << " mm" << endl;
//	//将对象置于显示小数点的模式
//	os.setf(ios_base::showpoint);
//	os.precision(1);
//	//设定下一次输出的字段宽度  只在显示下一个值有效
//	//然后将重新恢复默认
//	os.width(12);
//	os << "f.1. eyepiece";
//	os.width(15);
//	os << "magnification" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		os.width(12);
//		os << fe[i];
//		os.width(15);
//		os << int(fo / fe[i] + 0.5) << endl;
//	}
//	/*
//	返回调用这个对象之前的状态
//	*/
//	os.setf(initial);
//}



//函数默认参数
//const int ArSize = 80;
//char* left(const char* strr, int n = 1);
//int main()
//{
//	char sym[ArSize];
//	cout << "请输入字符串:";
//	while (!(cin.get(sym, ArSize)))
//	{
//		cin.clear();
//		while (cin.get() != '\n')
//			continue;
//	}
//	char* ps = left(sym, 4);
//	cout << ps << endl;
//	ps = left(sym);	//默认参数为n=1
//	cout << ps << endl;
//	delete[]ps;	//释放新开辟的内存
//	return 0;
//}
//char* left(const char* strr, int n)
//{
//	if (n < 0)
//		n = 0;
//	char* p = new char[n + 1];	//分配空间
//	int i;
//	for (i = 0; i < n && strr[i]; i++)
//	{
//		p[i] = strr[i];
//	}
//	while (i <= n)
//	{
//		p[i++] = '\0';
//	}
//	return p;
//}



//函数重载
//void Printf(const char* str, int n);
//void Printf(const char* str, int n, int m);
//void sink(double& a);
//void sink(const double& a);
//void sink(double&& a);
//int main()
//{
//	double a = 3;
//	const double t = 3;
//	sink(t);	//会自动匹配最合适的
//	sink(a + t);
//	return 0;
//}


//unsigned long left(unsigned long num, unsigned st);
//char* left(const char* str, int n = 1);
//int main()
//{
//	const char* str = "Hawaii!!";
//	unsigned int n = 12345678;
//	int i;
//	char* temp;
//
//	for (i = 1; i < 10; i++)
//	{
//		cout << left(n, i) << endl;
//		temp = left(str, i);
//		cout << temp << endl;
//		delete[] temp;
//	}
//	return 0;
//}
//unsigned long left(unsigned long num, unsigned st)
//{
//	unsigned digits = 1;
//	unsigned long n = num;
//	if (st == 0 || num == 0)
//	{
//		return 0;
//	}
//	while (n /= 10)
//		digits++;
//	if (digits > st)
//	{
//		st = digits - st;
//		while (st--)
//		{
//			num /= 10;
//		}
//		return num;
//	}
//	else
//	{
//		return num;
//	}
//}
//char* left(const char* str, int n )
//{
//	if (n < 0)
//		n = 0;
//
//	char* p = new char[n + 1];
//	int i;
//	for (i = 0; i < n && str[i]; i++)
//	{
//		p[i] = str[i];
//	}
//	while (i <= n)
//	{
//		p[i++] = '\0';
//	}
//	return p;
//}


//当且仅当函数实现相同的任务，但是用不同的函数形式的数据


//函数模板
/*
指定任意的函数类型
*/
//template <typename T>
//void Swap(T& a, T& b);
//int main()
//{
//	int i = 1, j = 5;
//	double a = 2, b = 4;
//	cout << "交换前:"<<endl;
//	cout << "i=" << i << " j=" << j << endl;
//	cout << "a=" << a << " b=" << b << endl;
//	Swap(a, b);
//	Swap(i, j);
//	cout << "交换后:" << endl;
//	cout << "i=" << i << " j=" << j << endl;
//	cout << "a=" << a << " b=" << b << endl;
//	return 0;
//}
//template <typename T>
//void Swap(T& a, T& b)
//{
//	T temp;
//	temp = a;
//	a = b;
//	b = temp;
//}



//重载函数模板
//template <typename T>
//void Swap(T& a, T& b);
//
//template <typename T>
//void Swap(T *a, T *b,int n);
//void show(int a[]);
//const int LIM = 8;
//int main()
//{
//	int i = 1, j = 5;
//	double a = 2, b = 4;
//	cout << "交换前:"<<endl;
//	cout << "i=" << i << " j=" << j << endl;
//	cout << "a=" << a << " b=" << b << endl;
//	Swap(a, b);
//	Swap(i, j);
//	cout << "交换后:" << endl;
//	cout << "i=" << i << " j=" << j << endl;
//	cout << "a=" << a << " b=" << b << endl;
//	int s[LIM]{ 1,2,3,4,5,6,7,8 };
//	int d[LIM]{ 9,8,7,6,5,4,3,2 };
//	show(s);
//	cout << endl;
//	Swap(s, d, LIM);	//交换两个数组的元素
//	show(s);
//	char str[LIM] = "woaini";
//	char strr[LIM] = "woshish";
//	Swap(str, strr, LIM);	//字符串也可以交换
//	cout << str << endl;
//	return 0;
//}
//template <typename T>
//void Swap(T& a, T& b)
//{
//	T temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//template <typename T>
//void Swap(T a[], T b[], int n)
//{
//	T temp;
//	for (int i = 0; i < n;i++)
//	{
//		temp = a[i];
//		a[i] = b[i];
//		b[i] = temp;
//	}
//}
//void show(int a[])
//{
//	for (int i = 0; i < LIM; i++)
//	{
//		cout << a[i] << " ";
//	}
//}


/*
非模板函数>具体化>模板函数
*/
//显式具体化
//template <typename T>
//void Swap(T& a, T& b);
//
//struct job
//{
//	char name[40];
//	double salary;
//	int floor;
//};
//template <>void Swap<job>(job& j1, job& j2);
//void Show(job& j);
//int main()
//{
//	int a = 1, b = 5;
//	Swap(a, b);
//	cout << "a=" << a << " b=" << b << endl;
//
//	//交换两个特定的值，不是整个结构
//	//整个结构也可以直接交换
//	job t1 = { "于良浩",999,666 };
//	job t2 = { "是我小",555,222 };
//	Swap(t1, t2);
//	Show(t1);
//	Show(t2);
//	return 0;
//}
//template <typename T>
//void Swap(T& a, T& b)
//{
//	T temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
////显式具体化函数
//template <>void Swap<job>(job& j1, job& j2)
//{
//	double t1;
//	int t2;
//	t1 = j1.salary;
//	j1.salary = j2.salary;
//	j2.salary = t1;
//
//	t2 = j1.floor;
//	j1.floor = j2.floor;
//	j2.floor = t2;
//}
//
//void Show(job& j)
//{
//	cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
//}


/*
具体化:
	显式具体化:
		template <>void Swap<int>(int,int);  有<>
	显式实例化:
		根据特定的类型来创建模板函数
		template void Swap<int>(int,int);  没有<>
		使用Swap模板生成int类型的函数定义
	隐式实例化:
		通过调用模板函数来推断类型
*/


//template <typename T>
//void Show(T arr[], int n);
//
////template <typename T>
////void Show(T* arr[], int n);
//int main()
//{
//	int* a[8];
//	for (int i = 0; i < 8; i++)
//		a[i] = &i;
//	Show(a,8);
//	return 0;
//}
//template <typename T>
//void Show(T arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//}
////template <typename T>
////void Show(T* arr[], int n)
////{
////	for (int i = 0; i < n; i++)
////	{
////		cout << *arr[i] << " ";
////	}
////}


// 标记<>一定要使用模板函数
template <typename T1,typename T2>
void ft(T1 a, T2 b)
{
	decltype(a + b) xpy;
	xpy = a + b;
	/*	1. 没有用括号括起的标识符
			目标类型与标识符类型相同
		2.括号括起来的内容是一个函数调用
			目标类型与函数的返回类型相同
		3.括号括起来一个标识符并且再用花括号括起来
			目标类型是一个对该标识符的引用
		4.如果都不满足
			目标类型为表达式的类型 如相加或者 L l

	*/

}
auto h(int x, float y)->double;	//后置返回类型

//指定返回值类型
template <typename T1, typename T2>
auto gt(T1 x, T2 y)->decltype(x + y)
{
	return x + y;
}

