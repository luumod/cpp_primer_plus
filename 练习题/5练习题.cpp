#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

//1
//int main()
//{
//	int a_num, b_num;
//	cout << "���������������ķ�Χ:";
//	cin >> a_num;
//	cin >> b_num;
//	int sum = 0;
//	for (int i = a_num; i <= b_num; i++)
//	{
//		sum += i;
//	}
//	cout << "��" << a_num << "��" << b_num << "֮������������ĺ�Ϊ:" << sum << endl;
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
//	cout << "����������:";
//	cin >> i;
//	long sum = 0;
//	while (i != 0)
//	{
//		cout << "��������룬ֱ������Ϊ0:";
//		cin >> i;
//		sum += i;
//	}
//	cout << "�ܺ�Ϊ: " << sum << endl;
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
//		sumD += 10;	//ÿ��10��Ԫ
//		sumC = sumC + sumC * 0.05;	//ǰ�������İٷ�֮5
//		++year;
//	}
//	cout << "Daphne������Ϊ: " << sumD << endl;
//	cout << "Cleo������Ϊ: " << sumC << endl;
//	cout << "��" << year << "��֮��Cleo������Daphne" << endl;
//	return 0;
//}


//5
//int main()
//{
//	//Ҳ����ʹ��char* months[12] ���� char[12][99]
//	string months[12] = {
//		"һ��","����","����","����","����",
//		"����","����","����","����","ʮ��","ʮһ��","ʮ����",
//	};
//	int num[12]{};
//	for (int i = 0; i < 12; i++)
//	{
//		cout << "�������" << i + 1 << "�µ�������: ";
//		cin >> num[i];
//	}
//	cout << "�������:" << endl;
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
//		cout << "��" << i + 1 << "���������" << sum << endl;
//	}
//	return 0;
//}



//7
//struct Car
//{
//	string name;	//������
//	int year;		//�������
//};
//int main()
//{
//	int num;
//	cout << "���ж�������?";
//	cin >> num;
//	cin.get();
//	Car* car_info = new Car[num];
//
//	for (int i = 0; i < num; i++)
//	{
//		cout << "��" << i + 1 << "������������:";
//		getline(cin, car_info[i].name);
//		cout << "��" << i + 1 << "�������������:";
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
//	cout << "�����뵥��:";
//	cin >> str;
//	while (strcmp(str,"done"))
//	{
//		++count;
//		cout << "�����뵥��:";
//		cin >> str;
//	}
//	cout << count << endl;
//	return 0;
//}



//9
//int main()
//{
//	//ֻ��string�����ʹ���ַ�����== �ȱȽϲ���
//	string str;
//	int count = 0;
//	cout << "�����뵥��:";
//	while (cin>>str)
//	{
//		if (str == "done")
//			break;
//		++count;
//		cout << "�����뵥��:";
//	}
//	cout << count << endl;
//	return 0;
//}


//10
//int main()
//{
//	int line;
//	cout << "��Ҫ���������?";
//	cin >> line;
//	for (int i = 0; i < line; i++)
//	{
//		//��ӡ��
//		for (int j = line - i - 1; j > 0; j--)
//		{
//			cout << ".";
//		}
//		//��ӡ��
//		for (int k = 0; k <= i; k++)
//		{
//			cout << "*";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}


