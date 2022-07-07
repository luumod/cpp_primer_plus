#include <iostream>
using namespace std;

/*
友元函数与类模板
*/


//1. 非模板友元函数
#if 0
template <typename T>
class A
{
private:
	T item;
public:
	//默认构造函数
	A(T i=10) :item(i) {}
	friend void HowSize();	//显示元素
	friend void HowNum(const A<T>& i);
};

void HowSize()
{
	cout << "HowSize: " << sizeof(A<int>) << endl;
	/*cout << "HowSize: " << sizeof(A<double>) << endl;
	cout << "HowSize: " << sizeof(A<string>) << endl;*/
}

void HowNum(const A<int>& i)
{
	cout << "HowNum: " << i.item << endl;
}
void HowNum(const A<double>& i)
{
	cout << "HowNum: " << i.item << endl;
}
void HowNum(const A<string>& i)
{
	cout << "HowNum: " << i.item << endl;
}
#endif

//2. 约束模板友元
#if 0
template <typename TT>void HowSize();
template <typename TT>void HowNum(const TT&);

template <typename T>
class A
{
private:
	T item;
public:
	//默认构造函数
	A(T i = 10) :item(i) {}
	friend void HowSize<T>();	//显示元素
	friend void HowNum<>(const A<T>& i);
};

template <typename T>
void HowSize()
{
	cout << "HowSize: " << sizeof(A<T>) << endl;
}

template <typename T>
void HowNum(const A<T>& i)
{
	cout << "HowNum: " << i.item << endl;
}
#endif

//3. 非约束模板友元
template <typename T>
class A
{
private:
	T item;
public:
	//默认构造函数
	A(T i = 10) :item(i) {}
	template <typename T1>
	friend void HowNum(const A<T1>& t);	//显示元素
	template <typename T1>
	friend void HowSize(const A<T1>& t);
};

template<typename T1>
void HowNum(const A<T1>& t )
{
	cout << "HowNum: " << t.item << endl;
}

template<typename T1>
void HowSize(const A<T1>& t)
{
	cout << "HowSize: " << sizeof(t.item) << endl;
}

int main()
{
	A<int> a;
	A<short> b(20);
	A<double> c(50);
	A<string> d("我爱你");
#if 0
	//1. 非模板友元

	HowNum(c);
	HowSize();
#elif 0
	//2. 约束模板友元

	HowNum(a);
	HowSize<int>();

	HowNum(b);
	HowSize<short>();

	HowNum(c);
	HowSize<double>();

	HowNum(d);
	HowSize<string>();
#elif 1
	//3. 非约束模板友元

	HowNum(a);
	HowSize(a);

	HowNum(b);
	HowSize(b);

	HowNum(c);
	HowSize(c);

	HowNum(d);
	HowSize(d);
#endif



	return 0;
}