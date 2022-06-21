#include <iostream>
#include <string>
#include <array>
#include <ctime>
using namespace std;

//1.
// #define TIAOHE(x,y) (2.0*(x)*(y))/((x)+(y))
//int main()
//{
//	int num1, num2;
//	cout << "请输入两个数字,计算调和平均数:";
//	while (cin >> num1 >> num2)
//	{
//		if (num1 == 0 || num2 == 0)
//			break;
//		cout << TIAOHE(num1, num2) << endl;
//		cout << "请输入两个数字,计算调和平均数:";
//	}
//	return 0;
//}


//2.
//const int MAX = 10;
//int input(int* ar, int n);
//void show(int* ar, int n);
//double jisuan(int* ar, int n);
//
//int main()
//{
//	int score[MAX], n = 0;
//	n = input(score, MAX);
//	show(score, n);
//	cout << "平均成绩:" << jisuan(score, n) << endl;
//	return 0;
//}
////返回输入的数组的元素个数
//int input(int* ar, int n)
//{
//	int i = 0;
//	cout << "请输入最多10个成绩,输入q退出:"<<endl;
//	cout << "请输入第" << i + 1 << "个成绩" ;
//	while (cin >> ar[i] && ++i<n)
//	{
//		cout << "请输入第" << i+1 << "个成绩,输入q退出" ;
//	}
//	cout << "输入完毕" << endl;
//	return i;
//}
//void show(int* ar,int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << i + 1 << ": " << ar[i] << endl;
//	}
//}
//double jisuan(int* ar, int n)
//{
//	double av_sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		av_sum += ar[i];
//	}
//	return av_sum;
//}


//3.
//struct box
//{
//	char maker[40];
//	float height;
//	float width;
//	float length;
//	float volume;
//};
//void fun1(struct box p);
//void fun_address(struct box* p);
//int main()
//{
//	box info = { "ylh",11.11,11.11,11.11,11.11 };
//	fun1(info);
//	fun_address(&info);
//	fun1(info);
//	return 0;
//}
//void fun1(struct box p)
//{
//	cout << p.maker << " " << p.height << " " << p.width << " " << p.length << " " << p.volume << endl;
//
//}
//void fun_address(struct box* p)
//{
//	p->volume = p->height * p->length * p->width;
//}


//4.



//5.
//int fun(int n);
//int main()
//{
//	int n;
//	cout << "输入一个数字,计算阶乘:";
//	cin >> n;
//	cout << "n的阶乘为:" << fun(n) << endl;
//	return 0;
//}
//int fun(int n)
//{
//	if (n == 1 || n == 0)
//		return 1;
//	else
//	{
//		return n*fun(n - 1);
//	}
//}


//6.
//#include <iostream>
//using namespace std;
//
//int Fill_array(double arr[], int n);
//void Show_array(const double arr[], int n);
//void Reverse_average(double arr[], int n);
//
//const int ArSize = 10;
//
//int main()
//{
//    int n;
//    double arr[ArSize];
//
//    n = Fill_array(arr, ArSize);
//    Show_array(arr, n);
//    Reverse_average(arr, n);
//    Show_array(arr, n);
//    cout << "Bye." << endl;
//
//    return 0;
//}
//
//int Fill_array(double arr[], int n)
//{
//    int i = 0;
//
//    cout << "You can enter up to " << ArSize;
//    cout << " numbers (q to terminate)." << endl;
//
//    cout << "Number #1: ";
//    while (i < n && cin >> arr[i])
//    {
//        if (++i < ArSize)
//        {
//            cout << "Number #" << i + 1 << ": ";
//        }
//    }
//    return i;
//}
//
//void Show_array(const double arr[], int n)
//{
//    cout << "All numbers:" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << ' ';
//    }
//    cout.put('\n');
//    return;
//}
//
//void Reverse_average(double arr[], int n)
//{
//    double temp;
//    int i_idx = 1, j_idx = n-2;
//    while (i_idx <= j_idx)
//    {
//        temp = arr[i_idx];
//        arr[i_idx++] = arr[j_idx];
//        arr[j_idx--] = temp;
//    }
//}


//10 .  计算器函数指针数组
//double calculate(double a, double b, double (*pf)(double n, double m));
//double add(double a, double b);
//double sub(double a, double b);
//double div(double a, double b);
//double che(double a, double b);
//
//int main()
//{
//	//函数指针数组
//	double (*p[4])(double, double) = { add,sub,div,che };
//	while (1)
//	{
//		system("cls");
//		cout << "--------------简易计算器-----------------" << endl;
//		cout << "-------------1.加法" << endl;
//		cout << "-------------2.减法" << endl;
//		cout << "-------------3.除法" << endl;
//		cout << "-------------4.乘法" << endl;
//		cout << "你的选择:";
//		int choice;
//		int num1, num2;
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:cout << "输入两个数字:";
//			cin >> num1 >> num2;
//			cout << num1 << "+" << num2 << "=" << p[0](num1, num2) << endl;
//			break;
//		case 2:
//			cout << "输入两个数字:";
//			cin >> num1 >> num2;
//			cout << num1 << "-" << num2 << "=" << p[1](num1, num2) << endl;
//			break;
//		case 3:
//			cout << "输入两个数字:";
//			cin >> num1 >> num2;
//			cout << num1 << "/" << num2 << "=" << p[2](num1, num2) << endl;
//			break;
//		case 4:
//			cout << "输入两个数字:";
//			cin >> num1 >> num2;
//			cout << num1 << "*" << num2 << "=" << p[3](num1, num2) << endl;
//			break;
//		default:
//			break;
//		}
//		_sleep(3000);
//	}
//	return 0;
//}
//double add(double a, double b)
//{
//	return a + b;
//}
//double sub(double a, double b)
//{
//	return a - b;
//}
//double div(double a, double b)
//{
//	return a / b;
//}
//double che(double a, double b)
//{
//	return a * b;
//}
//double calculate(double a, double b, double (*pf)(double n, double m));