#include <iostream>
#include <fstream>	//�ļ����
using namespace std;

//int main()
//{
//	char ch;
//	cout << "�������ַ���:";
//	cin.get(ch);
//	while (ch != '.')
//	{
//		if (ch == '\n')
//		{
//			cout << ch;
//		}
//		else
//			cout << ++ch<<" ";
//		cin.get(ch);
//	}
//
//	return 0;
//}

//
//const int MAX = 5;
//int main()
//{
//	int golf[MAX];
//	cout << "������" << MAX << "���÷�:";
//	for (int i = 0; i < MAX; i++)
//	{
//		cout << "�÷�" << i + 1 << ":";
//		while (!(cin >> golf[i]))
//		{
//			//�������
//			cin.clear();
//			while (cin.get() != '\n')
//			{
//				continue;
//			}
//			cout << "��������һ��:";
//		}
//	}
//	return 0;
//}


//int main()
//{
//	char ch;
//	int a;
//	double b;
//
//	char num[20];
//	cin.getline(num, 20);
//	cout << num << endl;
//	return 0;
//}


//�����ļ��Ĳ���
//int main()
//{
//
//	/*
//	ʹ���ļ�����Ĳ���:
//	1. ����ͷ�ļ� fstream
//	2. ����һ��	  ofstream����
//	3. ����fstream����ͬһ���ļ���ϵ����
//	4. ��ʹ��cout����ʹ��ofstream����
//	*/
//	//�������ڴ����������
//	ofstream outFile;
//	ofstream fout;
//	//����һ���ļ�
//	outFile.open("fish.txt");
//	char filename[50];
//	cin >> filename;
//	fout.open(filename);
//	
//	double wt = 125.8;
//	outFile << wt;	//дһ�����ֵ�fish.txt�ļ���
//	char line[80] = "Object hhh 666";
//	fout << line << endl;	//дһ���ı���foutָ�����ļ���
//
//
//	return 0;
//}


//д���ı��ļ�
//int main()
//{
//	char automobine[50];
//	int year;
//	double a_price;
//	double b_price;
//
//	//����ofstream�����
//	ofstream outFile;
//	//����һ���ı��ļ�
//	outFile.open("carinfo.txt");
//
//	cout << "Enter the make and model of automobine:";
//	cin.getline(automobine, 50);
//	cout << "Enter the model year:";
//	cin >> year;
//	cout << "Enter the original asking price:";
//	cin >> a_price;
//	b_price = a_price * 0.913;
//
//	//����Ļ����ʾ��Ϣ
//	cout << fixed;	
//	cout.precision(2);
//	cout.setf(ios_base::showpoint);
//	cout << "Make and model: " << automobine << endl;
//	cout << "Year: " << year << endl;
//	cout << "Was asking $" << a_price << endl;
//	cout << "Now asking $" << b_price << endl;
//
//	//������ݵ��ļ���
//	outFile << fixed;
//	outFile.precision(2);
//	outFile.setf(ios_base::showpoint);
//	outFile << "Make and model: " << automobine << endl;
//	outFile << "Year: " << year << endl;
//	outFile << "Was asking $" << a_price << endl;
//	outFile << "Now asking $" << b_price << endl;
//	outFile.close();	//�ر��ļ�
//
//
//	return 0;
//}



//int main()
//{
//	ifstream inFile;
//	ifstream fin;
//
//	inFile.open("bowling.txt");
//	if (!inFile.is_open())
//	{
//		//��ʧ��
//		exit(EXIT_FAILURE);
//	}
//
//	char filename[50];
//	cin >> filename;
//	fin.open(filename);
//	double wt;
//	inFile >> wt;
//	char line[80];
//	fin.getline(line, 81);
//
//	return 0;
//}



//��ȡ�ı��ļ���Ϣ
//int main()
//{
//	ifstream inFile;
//	inFile.open("fish.txt");
//	if (!inFile.is_open())
//	{
//		exit(0);
//	}
//	double num;
//	//�ж��Ƿ�ﵽ�ļ�ĩβ
//	if (inFile.eof())
//	{
//		cout << "����ĩβ" << endl;
//	}
//	//�������ƥ�����
//	if (inFile.fail())
//	{
//		cout << "���Ͳ�ƥ��" << endl;
//	}
//	inFile >> num;
//	cout << num << endl;
//
//	inFile.close();
//	return 0;
//}




/*
1��fstream��ͷ�ļ���

2��ifstream��ofstream�ֱ��������򿪺�����ļ���

3��.open()�������������ļ������磺ifs.open("m.txt", ios::in)���ͻ����Ϊ��m.txt�����ļ��ˣ�

4��is_open()�����������ж��ļ��Ƿ�򿪳ɹ�������ֵ�ǲ���ֵ�����磺ifs.is_open()��

5��good()������ָ�ļ���ȡ�ɹ���

6��.eof()�����������ж��Ƿ�������ļ�β��

7��.close()�����������ر�֮ǰ�򿪵��ļ���

8��.fail()���������ж�һ�����Ƿ񡰻������ˣ�����������ȡʧ��ʱ���Ὣ�ַ�����ԭ�����ȴ���һ�ζ�ȡ��
*/



//
int main()
{
	ofstream wrFile;
	wrFile.open("����.txt");
	int sum;
	//�����2��1000������
	for (int i = 2; i <= 1000; i++)
	{
		cout << endl;
		sum = 1;
		for (int j = 2; j <= i / 2; j++)
		{
			//�������������֮��
			if (i % j == 0)
				sum += j;
		}
		//��������֮�͵��ڱ�����Ϊ����
		if (sum == i)
		{
			wrFile << sum << "=";
			cout << sum << "=";
			//��ʽ��
			for (int k = 2; k <= i / 2; k++)
			{
				if (i % k == 0)
				{
					wrFile << k << "+";
					cout << k << "+";
				}
			}
			wrFile << endl;
			cout << endl;
		}
		//��������������
	}

	wrFile.close();
	return 0;
}


