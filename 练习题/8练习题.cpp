#include <iostream>
#include <string>
#include <string.h>
using namespace std;
///*
//��ϰ��
//*/
//
////1. �ظ����� ��С
//
////2. times=1 ����Ҫ��ĩβ
//
////3.
//void iquote(int);
//void iquote(double);
//void iquote(string);
//
///*
//---------4--------
//*/
//struct box
//{
//	char maker[40];
//	float height;
//	float width;
//	float length;
//	float volume;
//};
////a.
//void Show(box& t)
//{
//	cout << t.maker << t.height << endl;
//}
//
////b.
//void change(box& t)
//{
//	t.volume = t.height * t.width * t.length;
//}
//
///*
//----------6---------
//*/
////a.
//double mass(double density, double volume=1)
//{
//	return density * volume;
//}
//
////b.
//
//
////c.
//template <typename T>
//auto average(T a, T b)->decltype(a)
//{
//	return (a + b) / 2;
//}
//
////d.
//template <typename T>
//T mangle(T str)
//{
//	return str;
//}
//
////7	�������������Ľϴ�ֵ
//template <typename T>
//T big(T a, T b)
//{
//	return (a > b) ? a : b;
//}
//
////8. ģ�� �����������һ��
//template <> box big<box>(box& a, box& b)
//{
//
//}
//
////9.
///*
// float &���� ����  int  double
//*/


//1.
//void Printf(string str, int n = 0);
//int main()
//{
//	string str;
//	cout << "�������ַ���:";
//	getline(cin, str);
//	Printf(str);
//	cout << "����10��:" << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		Printf(str, 999);
//	}
//	return 0;
//}
//void Printf(string str, int n)
//{
//	cout << str << endl;
//}


//2.
//struct CandyBar
//{
//	char name[20];
//	double weight;
//	int hot;
//};
//void InitStr(CandyBar& sat, const char* str = "Millennium Munch",
//	const double wei = 2.85, const int n = 350);
//void Show(CandyBar& sat);
//int main()
//{
//	CandyBar a, b;
//	InitStr(a);
//	InitStr(b, "������", 99.99, 250);
//	Show(a);
//	Show(b);
//	return 0;
//}
//void InitStr(CandyBar& sat, const char* str,const double wei,const int n)
//{
//	strcpy(sat.name, str);
//	sat.weight = wei;
//	sat.hot = n;
//}
//void Show(CandyBar& sat)
//{
//	cout << "����:" << sat.name << endl;
//	cout << "����:" << sat.weight << endl;
//	cout << "����:" << sat.hot << endl;
//}


//3.
//void Change_big(string& str);
//int main()
//{
//	string str;
//	cout << "�������ַ��� ת��Ϊ��д q�˳�:";
//	while (getline(cin, str) && str != "q")
//	{
//		Change_big(str);
//		cout << str << endl;
//		cout << "�������ַ��� ת��Ϊ��д q�˳�:";
//
//	}
//	return 0;
//}
//void Change_big(string& str)
//{
//	for (int i = 0; i <str.size(); i++)
//	{
//		str[i] = toupper(str[i]);
//	}
//}


//4.
//struct stringy
//{
//	char* str;
//	int ct;	//�ַ����ĳ���
//};
//void set(stringy& sat, const char* str);
//void show(stringy& sat, int n = 1);	//�ṹ��
//void show(const char* str, int n = 1);	//�ַ���
//int main()
//{
//	stringy beany;
//	char testing[] = "Reality isn't what it used to be.";
//	set(beany, testing);
//	show(beany);
//	show(beany, 2);
//	testing[0] = 'D';
//	testing[1] = 'u';
//	show(testing);
//	show(testing, 3);
//	show("Done!");
//	return 0;
//}
//void set(stringy& sat, const char* str)
//{
//	//�ṹ�����ַ�����������ֵ
//	sat.str = new char[strlen(str) + 1];
//	strcpy(sat.str, str);
//	
//	sat.ct = strlen(sat.str);
//}
//void show(stringy& sat, int n)
//{
//	//��ʾ����
//	for (int i = 0; i < n; i++)
//	{
//		cout << "str: " << sat.str << endl;
//		cout << "len: " << sat.ct << endl;
//	}
//}
//void show(const char* str, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "str: " << str << endl;
//	}
//}



//5.
//template <typename T>
//T max5(T n[5]);
//int main()
//{
//	int ar[5] = { 1,2,3,4,5 };
//	double arr[5] = { 11.11,22.22,33.33,44.44,55.55 };
//	cout << "ar �������ֵ: " << max5(ar) << endl;
//	cout << "arr �������ֵ: " << max5(arr) << endl;
//
//	return 0;
//}
//template <typename T>
//T max5(T n[5])
//{
//	T max = n[0];
//	for (int i = 0; i < 5; i++)
//	{
//		if (max < n[i])
//			max = n[i];
//	}
//	return max;
//}


//6.
//template <typename T>
//T maxn(T ar[], int n);
//template <>const char* maxn(const char* a[], int n);
//int main()
//{
//	int ar[6] = { 1,2,3,4,5,6 };
//	double arr[4] = { 11.11,22.22,33.33,44.44 };
//	const char* str[5] = { "asd","grd","daw","dgr","jyg" };
//	cout << "ar �������ֵ: " << maxn(ar,6) << endl;
//	cout << "arr �������ֵ: " << maxn(arr,4) << endl;
//	cout << "str �������ַ�����ַ: " << maxn(str, 5) << endl;
//	return 0;
//}
//template <typename T>
//T maxn(T ar[],int n)
//{
//	T max = ar[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (max < ar[i])
//			max = ar[i];
//	}
//	return max;
//}
//template <>const char* maxn(const char* a[], int n)
//{
//	const char* temp = *a;
//	for (int i = 1; i < n; i++)
//	{
//		if (strlen(temp)< strlen(a[i]))
//		{
//			temp = a[i];
//		}
//	}
//	return temp;
//}



//7.
//struct debts
//{
//	char name[50];
//	double amount;
//};
//template <typename T>
//T SumArray(T* arr,int n);
//template <typename T>
//T SumArray(T* arr[], int n);
//
//int main()
//{
//	int things[6] = { 13,31,103,301,310,130 };
//	struct debts mr_E[3] =
//	{
//		{"waoini",2400.0},
//		{"Ura Foxa",1300.0},
//		{"Iby Stout",1800.0},
//	};
//	double* pd[3];
//	for (int i = 0; i < 3; i++)
//	{
//		pd[i] = &mr_E[i].amount;
//	}
//	cout << "things��Ԫ���ܺ�: " << SumArray(things, 6) << endl;
//	cout << "bets��Ԫ���ܺ�: " << SumArray(pd, 3) << endl;
//
//	pri("wad", "da");
//
//	return 0;
//}
//template <typename T>
//T SumArray(T* arr,int n)
//{
//	T sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += arr[i];
//	}
//	return sum;
//}
//template <typename T>
//T SumArray(T* arr[], int n)
//{
//	T sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += *arr[i];
//	}
//	return sum;
//}



//ʵ��������廯
struct asd
{
	int age;
	float score;
};
//��ʽʵ����ģ��
template <typename T>
void Swap(T& a, T& b);

//��ʽ���廯
template <>void Swap<double>(double& a, double& b);

//��ʽʵ����
template void Swap<int>(int& a, int& b);
int main()
{
	double a = 1.1, b = 2.2;
	int c = 5, d = 9;
	asd t = { 99,63.2 }, h = { 66,26.5 };
	Swap(a, b);
	//Swap(c, d);	//��ʽʵ����
	Swap<int>(c, d);
	Swap(t, h);
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
	cout << t.age << " " << t.score << endl << h.age << " " << h.score << endl;
	return 0;
}
template <typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <>void Swap<double>(double& a, double& b)
{
	double temp;
	temp = a;
	a = b;
	b = temp;
}
