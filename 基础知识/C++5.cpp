#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//int main()
//{
//	int x, y, z;
//	x = y = z = 1;
//	cout << x << y << z << endl;
//	return 0;
//}

//int main()
//{
//	int x;
//	cout << "The expression x=100 has the value";
//	cout << (x = 100) << endl;
//	cout << "Now x= " << x << endl;
//	cout << "The expression x<3 has the value ";
//	cout << (x < 3) << endl;
//	cout << "The expression x>3 has the value ";
//	cout << (x > 3) << endl;
//	//��ʾ����ֵ
//	cout.setf(ios::boolalpha);
//
//	cout << "The expression x<3 has the value ";
//	cout << (x < 3) << endl;
//	cout << "The expression x>3 has the value ";
//	cout << (x > 3) << endl;
//	return 0;
//}



//�׳�
//const int SIZE=16;
//int main()
//{
//	long long num[SIZE];
//	num[0] = num[1] = 1LL;
//	for (int i = 2; i < SIZE; i++)
//	{
//		num[i] = i * num[i - 1];
//	}
//	for (int i = 0; i < SIZE; i++)
//	{
//		cout << i << "!" << " = " << num[i] << endl;
//	}
//	return 0;
//}

//
//int main()
//{
//	int num;
//	cout << "�����벽��:";
//	cin >> num;
//	for (int i = 0; i < 100; i += num)
//	{
//		cout << i << endl;
//	}
//	return 0;
//}


//�����ַ���
//int main()
//{
//	string str;
//	cout << "�������ַ���:";
//	getline(cin, str);
//	for (int i = str.size() - 1; i >= 0; i--)
//	{
//		cout << str[i];
//	}
//	return 0;
//}


//��ͬ�ı���
//int main()
//{
//	int x = 20;
//	{
//		cout << x << endl;
//		//���ص�һ��x
//		int x = 100;
//		cout << x << endl;
//		//x��ʧ
//	}
//	cout << x << endl;
//
//	return 0;
//}


//ʹ��string�����Ƚ��ַ���
//int main()
//{
//	string str = "1ate";
//	for (char ch = 'a'; str != "mate"; ++ch)
//	{
//		cout << str << endl;
//		str[0] = ch;
//		//int(ch)��ʾASCII��
//		//cout << int(ch) << endl;
//	}
//	cout << "str= " << str << endl;
//	return 0;
//}



//�����ӳ�ѭ��
//int main()
//{
//	cout << "Enter the delay time,in seconds: ";
//	float secs;
//	//�����ӳ�����
//	cin >> secs;
//	//�õ�ϵͳʱ�䵥λ��ʱ��
//	clock_t delay = secs * CLOCKS_PER_SEC;
//	cout << "starting\a" << endl;
//	//��ȡ��ʼ��ϵͳʱ��
//	clock_t start = clock();
//	while ((clock() - start) < delay)
//		;
//	cout << "Done!\a" << endl;
//	return 0;
//}



//���ڷ�Χ��forѭ��
//int main()
//{
//	double num[5] = { 1.1,2.2,3.3,4.4,5.5 };
//	//��ʾ�����е�ÿ��Ԫ��
//	for (double x : num)
//		cout << x << endl;
//	cout << endl;
//	//�޸������е�Ԫ��  ���ò���
//	for (double& x : num)
//		x = x * 0.8;
//	for (double x : num)
//		cout << x << endl;
//	return 0;
//}



//�����ַ��� ����ַ��ĸ���
//int main()
//{
//	//��һ�γ���: cin
//#if 0
//	int count = 0;
//	char ch;
//	cout << "�������ַ���:";
//	cin >> ch;
//	//cin �������Կո�ͻس�
//	//����#��ʱֹͣ���������
//	while (ch != '#')
//	{
//		cout << ch;
//		cin >> ch;
//		count++;
//	}
//	cout << endl << count << "���ַ�" << endl;
//#elif 0
//	//�ڶ��γ���: cin.get(char)
//	int count = 0;
//	char ch;
//	cout << "�������ַ���:";
//	cin.get(ch);
//	//cin.get ������Կ���
//	//����#��ʱֹͣ���������
//	while (ch != '#')
//	{
//		cout << ch;
//		cin.get(ch);
//		count++;
//	}
//	cout << endl << count << "���ַ�" << endl;
//	
//#elif 0
//	int count = 0;
//	char ch;
//	cout << "�������ַ���:";
//	//cin.get(ch);
//	//cin.get ������Կ���
//	//��ʾû�е����ļ�������Ľ�β
//	//ʹ��CTRL+Z + �س���ģ�� EOF ����
//	//while (cin.fail()==false)
//	//while (cin)	//��򵥵�д��
//	while (cin.get(ch))
//	{
//		cout << ch;
//		//cin.get(ch);
//		count++;
//	}
//	cout << endl << count << "���ַ�" << endl;
//#elif 1
//	int count = 0;
//	int ch;
//	while ((ch = cin.get()) != EOF)
//	{
//		cout.put(char(ch));
//		count++;
//	}
//	cout << endl << count << "���ַ�" << endl;
//#endif
//	return 0;
//}


