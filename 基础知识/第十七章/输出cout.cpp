#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>	//����

using namespace std;
/* 
* �������� *
ostream ��
	<<  
	put  �ַ�
	write �ַ���
*/

#if 0
int main()
{
	const char* s1 = "abcdfsefs";
	const char* s2 = "ondwao";
	const char* s3 = "dwalcacw";

	/*
	write �ַ�����ַ�����ʾ���ַ�����
	*/
	for (int i = 0; i < strlen(s1); i++)
	{
		cout.write(s1, i);
		cout << endl;
	}

	for (int i = strlen(s2); i >= 0; i--)
	{
		cout.write(s2, i) << endl;
	}
	cout << endl;
	long val = 560646561;
	cout.write((char*)&val, sizeof(val));
	return 0;
}
#elif 0
int main()
{
	int a = 110;
	int b = 9595;
	int c = 652;
	cout << hex;		//ʮ������
	cout << a<<endl;
	cout << oct;		//�˽���
	cout << b<<endl;
	cout << dec;		//ʮ����
	cout << c<<endl;
	return 0;
}

#elif 0

int main()
{
	/*
	�ı�����ַ�
	   һֱ��Ч
	*/
	cout.fill('*');
	long b[2] = { 200,1000 };

	for (int i = 0; i < 2; i++)
	{
		/*
		���ÿ��
		ֻ����Чһ��
		*/
		cout.width(10);
		cout << b[i]<<endl;
	}
	
	return 0;
}

#elif 0

int main()
{
	float a = 20.5621;
	double x = 95.23614;

	/*
	���þ���λ��
	һֱ��Ч
	*/
	cout.precision(3);
	cout << a << endl;
	cout << x << endl;

	return 0;
}

#elif 0

int main()
{
	float a = 20.1;
	double x = 95.236;

	/*
	Ĭ����ʾ��λС�� С��λ�����������
	*/
	cout.setf(ios_base::showpoint);
	cout << a << endl;
	cout << x << endl;

	/*
	����С����λ��
	*/
	cout.precision(7);
	cout << a << endl;
	cout << x << endl;
	return 0;
}
#elif 0

int main()
{
	int a = 60;
	/*
	������ǰ��� + 
	������ʮ����ʱ��Ч  ����Ѿ�����Ϊhex��oct����Ч
	*/
	cout.setf(ios_base::showpos);
	cout << a << endl;

	//����ʮ��������� ʹ�ô�д��ĸ
	cout.setf(ios_base::uppercase);
	cout << hex << a << endl;

	//��ʾboolֵ
	cout.setf(ios_base::boolalpha);
	cout << true << " " << false << endl;

	//��ʾ 0  0Xǰ׺
	cout.setf(ios_base::showbase);
	cout << oct << a << endl;

	//��ʾС����
	cout.setf(ios_base::showpoint);
	return 0;
}

#elif 0

int main()
{
	/*
	��һ������					�ڶ�������
	dec oct hex					basefield		
	fixed  scientific			floatfield		
	left right internal			adjustfield		
	*/
	//�����Ҷ��� 
	cout.setf(ios_base::left, ios_base::adjustfield);
	//����ǰ�� +
	cout.setf(ios_base::showpos);
	//��ʾС��λ 0
	cout.setf(ios_base::showpoint);
	//����С��λ��
	cout.precision(3);

	//���  ���������  ��ѧ������
	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
	cout << "Left adjustment: \n";
	for (int i = 1; i <= 41; i += 10)
	{
		cout.width(4);
		cout << i << "|";
		cout.width(12);
		cout << sqrt(double(i)) << "|\n";
	}
	
	//���÷�����ǰ �����ں����
	cout.setf(ios_base::internal, ios_base::adjustfield);
	//�ص���ʼλ�� ��ȡ����ѧ��������ʾ
	cout.setf(old, ios_base::floatfield);

	cout << "internal adjustment:\n";
	for (int i = 1; i <= 41; i += 10)
	{
		cout.width(4);
		cout << i << "|";
		cout.width(12);
		cout << sqrt(double(i)) << "|\n";
	}

	//�Ҷ���
	cout.setf(ios_base::right, ios_base::adjustfield);
	//�����ʾ��
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "right adjustment:\n";
	for (int i = 1; i <= 41; i += 10)
	{
		cout.width(4);
		cout << i << "|";
		cout.width(12);
		cout << sqrt(double(i)) << "|\n";
	}

	return 0;
}

#elif 0

int main()
{
	//�����ʾ �Ҷ���
	cout << fixed << right;

	/*
	setw			���ÿ��
	setfill			��������ַ�
	setprecision	����С��λ��
	*/
	cout << setw(6) << "N" << setw(14) << "square root"
		<< setw(15) << "fourth root\n";
	double root;
	for (int n = 10; n <= 100; n += 10)
	{
		root = sqrt(double(n));
		cout << setw(6) << setfill('-') << n << setfill(' ')
			<< setw(12) << setprecision(3) << root
			<< setw(14) << setprecision(4) << sqrt(root) << endl;
	}

	return 0;
}


#endif // 1
