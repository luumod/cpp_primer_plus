#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

//1
//int main()
//{
//	int a_num, b_num;
//	cout << "请输入两个整数的范围:";
//	cin >> a_num;
//	cin >> b_num;
//	int sum = 0;
//	for (int i = a_num; i <= b_num; i++)
//	{
//		sum += i;
//	}
//	cout << "在" << a_num << "和" << b_num << "之间的所有整数的和为:" << sum << endl;
//	return 0;
//}


//2
//int main()
//{
//	array<long double, 100> num{ 1 };
//	for (int i = 1; i < 100; i++)
//	{
//		num[i] = i * num[i - 1];
//	}
//	for (int i = 1; i <= 100; i++)
//	{
//		cout << i << "! = " << num[i - 1] << endl;
//	}
//	return 0;
//}


//3
//int main()
//{
//	int i;
//	cout << "请输入数字:";
//	cin >> i;
//	long sum = 0;
//	while (i != 0)
//	{
//		cout << "请继续输入，直到输入为0:";
//		cin >> i;
//		sum += i;
//	}
//	cout << "总和为: " << sum << endl;
//	return 0;
//}



//4
//int main()
//{
//	const double D = 0.1;
//	const double C = 0.05;
//	int year = 0;
//	double sumD = 0.1 * 100+100;
//	double sumC = 0.05 * 100 + 100;
//	while (sumD >= sumC)
//	{
//		sumD += 10;	//每年10美元
//		sumC = sumC + sumC * 0.05;	//前年的利润的百分之5
//		++year;
//	}
//	cout << "Daphne的利润为: " << sumD << endl;
//	cout << "Cleo的利润为: " << sumC << endl;
//	cout << "在" << year << "年之后，Cleo超过了Daphne" << endl;
//	return 0;
//}


//5
//int main()
//{
//	//也可以使用char* months[12] 或者 char[12][99]
//	string months[12] = {
//		"一月","二月","三月","四月","五月",
//		"六月","七月","八月","九月","十月","十一月","十二月",
//	};
//	int num[12]{};
//	for (int i = 0; i < 12; i++)
//	{
//		cout << "请输入第" << i + 1 << "月的销售量: ";
//		cin >> num[i];
//	}
//	cout << "销售情况:" << endl;
//	for (int i = 0; i < 12; i++)
//	{
//		cout << months[i] << "\t";
//	}
//	cout << endl;
//	for (int i = 0; i < 12; i++)
//	{
//		cout << num[i] << "\t";
//	}
//	cout << endl;
//	return 0;
//}



//6
//int main()
//{
//	int num[3][12] =
//	{
//		{1,2,3,4,5,6,7,8,9,10,11,12},
//		{2,3,4,5,6,7,8,9,10,11,12,13},
//		{3,4,5,6,7,8,9,10,11,12,13,14},
//	};
//	int sum;
//	for (int i = 0; i < 3; i++)
//	{
//		sum = 0;
//		for (int j = 0; j < 12; j++)
//		{
//			sum += j;
//		}
//		cout << "第" << i + 1 << "年的销售量" << sum << endl;
//	}
//	return 0;
//}



//7
//struct Car
//{
//	string name;	//生产商
//	int year;		//生产年份
//};
//int main()
//{
//	int num;
//	cout << "你有多少汽车?";
//	cin >> num;
//	cin.get();
//	Car* car_info = new Car[num];
//
//	for (int i = 0; i < num; i++)
//	{
//		cout << "第" << i + 1 << "辆车的生产商:";
//		getline(cin, car_info[i].name);
//		cout << "第" << i + 1 << "辆车的生产年份:";
//		cin >> car_info[i].year;
//		cin.get();
//	}
//	for (int i = 0; i < num; i++)
//	{
//		cout << car_info[i].name << endl;
//		cout << car_info[i].year << endl;
//	}
//	return 0;
//}



//8
//int main()
//{
//	char str[20];
//	int count = 0;
//	cout << "请输入单词:";
//	cin >> str;
//	while (strcmp(str,"done"))
//	{
//		++count;
//		cout << "请输入单词:";
//		cin >> str;
//	}
//	cout << count << endl;
//	return 0;
//}



//9
//int main()
//{
//	//只有string类才能使用字符串的== 等比较操作
//	string str;
//	int count = 0;
//	cout << "请输入单词:";
//	while (cin>>str)
//	{
//		if (str == "done")
//			break;
//		++count;
//		cout << "请输入单词:";
//	}
//	cout << count << endl;
//	return 0;
//}


//10
//int main()
//{
//	int line;
//	cout << "你要输入多少行?";
//	cin >> line;
//	for (int i = 0; i < line; i++)
//	{
//		//打印点
//		for (int j = line - i - 1; j > 0; j--)
//		{
//			cout << ".";
//		}
//		//打印星
//		for (int k = 0; k <= i; k++)
//		{
//			cout << "*";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}


