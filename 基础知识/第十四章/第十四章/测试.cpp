#include <iostream>
using namespace std;

/*
��Ԫ��������ģ��
*/


//1. ��ģ����Ԫ����
#if 0
template <typename T>
class A
{
private:
	T item;
public:
	//Ĭ�Ϲ��캯��
	A(T i=10) :item(i) {}
	friend void HowSize();	//��ʾԪ��
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

//2. Լ��ģ����Ԫ
#if 0
template <typename TT>void HowSize();
template <typename TT>void HowNum(const TT&);

template <typename T>
class A
{
private:
	T item;
public:
	//Ĭ�Ϲ��캯��
	A(T i = 10) :item(i) {}
	friend void HowSize<T>();	//��ʾԪ��
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

//3. ��Լ��ģ����Ԫ
template <typename T>
class A
{
private:
	T item;
public:
	//Ĭ�Ϲ��캯��
	A(T i = 10) :item(i) {}
	template <typename T1>
	friend void HowNum(const A<T1>& t);	//��ʾԪ��
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
	A<string> d("�Ұ���");
#if 0
	//1. ��ģ����Ԫ

	HowNum(c);
	HowSize();
#elif 0
	//2. Լ��ģ����Ԫ

	HowNum(a);
	HowSize<int>();

	HowNum(b);
	HowSize<short>();

	HowNum(c);
	HowSize<double>();

	HowNum(d);
	HowSize<string>();
#elif 1
	//3. ��Լ��ģ����Ԫ

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