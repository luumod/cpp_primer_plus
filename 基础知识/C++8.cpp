#include <iostream>
#include <ostream>
#include <fstream>
#include <istream>
using namespace std;
//���ñ���

//int main()
//{
//	int a = 101, d = 5;
//	int* v = &d;
//	int& b= a;		//��������������ʱ���г�ʼ��
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
//	cout << p << endl;	//p���õ�ʼ������ǰ��vֵ�������øı䲢��Ӱ�������� 
//	return 0;
//}


//�����������ֵ�ֵ
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


//��ֵ����  &&
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
//	info stu = { "������",18,99 };
//	info temp;
//	temp = change(stu);// ֱ�Ӱ�һ���ṹ����Ϊ��һ���ṹ
//	cout << stu.score<<endl;
//	cout << temp.score << endl;
//	return 0;
//}
//info& change(info& a)
//{
//	info w;
//	w = a;
//	a.score *= 2;
//	return w;	//����һ������
//}



//�������õ�һ��ϰ��
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
//	A one = { "����һ",11,11 };
//	A two = { "���Ƕ�",22,22 };
//	A three = { "������",33,33 };
//	A four = { "������",44,44 };
//	A five = { "������",55,55 };
//	A team = { "������",0,0 };
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
//	string r = sum3(o, n);	//����o�����ã�����ı�o��ֵ
//	//��ʱo�������޸�
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
//	//������ͼ�����Ѿ��ͷŵ��ڴ�
//	string temp;
//	temp = a + b + a;
//	return temp;
//}


//ostream����ָ��ostream����cout��ofstream����fout
//void file_it(ostream& os, double fo, const double fe[], int n);
//const int LIMIT = 5;
//int main()
//{
//	ofstream fout;
//	const char* fn = "ep-data.txt";
//	fout.open(fn);
//	if (!fout.is_open())
//	{
//		//��ʧ��
//		cout << "Cann't opne" << fn << ". Bye!" << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	double objective;
//	cout << "Enter the focal lenth of your "
//		"telescope object in mm: ";
//	cin >> objective;	//����
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
//	ios_base::fmtflags �洢������Ϣ������������͵�����
//	*/
//	ios_base::fmtflags initial;	//�洢����file_it֮ǰ�ĸ�ʽ��ģʽ
//	//����������ʹ�ö����ʾ����ģʽ
//	initial = os.setf(ios_base::fixed);
//	//ָ����ʾ����λС��
//	os.precision(0);
//	os << "Focal length of object: " << fo << " mm" << endl;
//	//������������ʾС�����ģʽ
//	os.setf(ios_base::showpoint);
//	os.precision(1);
//	//�趨��һ��������ֶο��  ֻ����ʾ��һ��ֵ��Ч
//	//Ȼ�����»ָ�Ĭ��
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
//	���ص����������֮ǰ��״̬
//	*/
//	os.setf(initial);
//}



//����Ĭ�ϲ���
//const int ArSize = 80;
//char* left(const char* strr, int n = 1);
//int main()
//{
//	char sym[ArSize];
//	cout << "�������ַ���:";
//	while (!(cin.get(sym, ArSize)))
//	{
//		cin.clear();
//		while (cin.get() != '\n')
//			continue;
//	}
//	char* ps = left(sym, 4);
//	cout << ps << endl;
//	ps = left(sym);	//Ĭ�ϲ���Ϊn=1
//	cout << ps << endl;
//	delete[]ps;	//�ͷ��¿��ٵ��ڴ�
//	return 0;
//}
//char* left(const char* strr, int n)
//{
//	if (n < 0)
//		n = 0;
//	char* p = new char[n + 1];	//����ռ�
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



//��������
//void Printf(const char* str, int n);
//void Printf(const char* str, int n, int m);
//void sink(double& a);
//void sink(const double& a);
//void sink(double&& a);
//int main()
//{
//	double a = 3;
//	const double t = 3;
//	sink(t);	//���Զ�ƥ������ʵ�
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


//���ҽ�������ʵ����ͬ�����񣬵����ò�ͬ�ĺ�����ʽ������


//����ģ��
/*
ָ������ĺ�������
*/
//template <typename T>
//void Swap(T& a, T& b);
//int main()
//{
//	int i = 1, j = 5;
//	double a = 2, b = 4;
//	cout << "����ǰ:"<<endl;
//	cout << "i=" << i << " j=" << j << endl;
//	cout << "a=" << a << " b=" << b << endl;
//	Swap(a, b);
//	Swap(i, j);
//	cout << "������:" << endl;
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



//���غ���ģ��
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
//	cout << "����ǰ:"<<endl;
//	cout << "i=" << i << " j=" << j << endl;
//	cout << "a=" << a << " b=" << b << endl;
//	Swap(a, b);
//	Swap(i, j);
//	cout << "������:" << endl;
//	cout << "i=" << i << " j=" << j << endl;
//	cout << "a=" << a << " b=" << b << endl;
//	int s[LIM]{ 1,2,3,4,5,6,7,8 };
//	int d[LIM]{ 9,8,7,6,5,4,3,2 };
//	show(s);
//	cout << endl;
//	Swap(s, d, LIM);	//�������������Ԫ��
//	show(s);
//	char str[LIM] = "woaini";
//	char strr[LIM] = "woshish";
//	Swap(str, strr, LIM);	//�ַ���Ҳ���Խ���
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
��ģ�庯��>���廯>ģ�庯��
*/
//��ʽ���廯
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
//	//���������ض���ֵ�����������ṹ
//	//�����ṹҲ����ֱ�ӽ���
//	job t1 = { "������",999,666 };
//	job t2 = { "����С",555,222 };
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
////��ʽ���廯����
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
���廯:
	��ʽ���廯:
		template <>void Swap<int>(int,int);  ��<>
	��ʽʵ����:
		�����ض�������������ģ�庯��
		template void Swap<int>(int,int);  û��<>
		ʹ��Swapģ������int���͵ĺ�������
	��ʽʵ����:
		ͨ������ģ�庯�����ƶ�����
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


// ���<>һ��Ҫʹ��ģ�庯��
template <typename T1,typename T2>
void ft(T1 a, T2 b)
{
	decltype(a + b) xpy;
	xpy = a + b;
	/*	1. û������������ı�ʶ��
			Ŀ���������ʶ��������ͬ
		2.������������������һ����������
			Ŀ�������뺯���ķ���������ͬ
		3.����������һ����ʶ���������û�����������
			Ŀ��������һ���Ըñ�ʶ��������
		4.�����������
			Ŀ������Ϊ���ʽ������ ����ӻ��� L l

	*/

}
auto h(int x, float y)->double;	//���÷�������

//ָ������ֵ����
template <typename T1, typename T2>
auto gt(T1 x, T2 y)->decltype(x + y)
{
	return x + y;
}

