#include <iostream>
#include <climits>
using namespace std;
//int main()
//{
//	unsigned long long a = ULLONG_MAX;
//	cout << "a_max=" << a<< endl;
//	return 0;
//}


//�����ĳ�ʼ��
//int main()
//{
//	/*int ros{};
//	int roa = {};
//	int rod{ 4 };
//	cout << ros << endl;
//	cout << roa << endl;
//	cout << rod << endl;*/
//	int a = 5, a8 = 011, a16 = 0x123;
//	cout << a << endl;
//	cout << a8 << endl;
//	cout << a16 << endl;
//	return 0;
//}


//C++����
//int main()
//{
//	int a = 15;
//	int b = 80;
//	int c = 256;
//	char ch,ch2;
//	cout << "a=" << a << endl << hex;		//ʮ����
//	cout << "a=" << b << endl << oct;	//ʮ������
//	cout << "a=" << c << endl << dec;	//�˽���
//	cin >> ch;
//	cout << "ch=" << ch << endl << hex;
//	cin.get();	//���ն���Ļس�
//	cin.get(ch2);	//�൱��getchar
//	cout.put(ch) << endl;	//�൱��putchar
//	cout.put(ch2) << endl;
//	return 0;
//}


//�ַ���չ
//int main(void)
//{
//	//���ַ�����,ǰ׺L��ʾ
//	wchar_t b = L'A';
//	wcout << L"tall" << endl;
//	wcout << b << endl;
//	//C++����������,ǰ׺u��ʾ16λ��ǰ׺U��ʾ32λ
//	char16_t ch1 = u'a';
//	char32_t ch2 = U'\U0000222B';
//	cout << ch1 << endl;
//	cout << ch2 << endl;
//	//bool����
//	bool is_ready = true;
//	cout << is_ready << endl;
//	return 0;
//}


//const�޶���
//const int a = 12;	//��const����#define
//int main()
//{
//	//��ĸ��д ����ĸk��ͷ
//	const int Months = 12;
//	cout << a << endl;
//	cout << Months << endl;
//	double a = 9.11e-31;
//	cout << a << endl;
//	//�������д����ֹ����������������
//	cout.setf(ios_base::fixed, ios_base::floatfield);
//	float n = 10.0 / 3.0;
//	double m = 10.0/3.0;
//	double million = 1.0e6;
//	//���ȵĲ��
//	cout << "n=" << n << endl;
//	cout << "n=" << n*million << endl;
//	cout << "m=" << m << endl;
//	cout << "m=" << m*million << endl;
//
//	return 0;
//}



//ǿ������ת��
int main()
{
	int a, b, c;
	a = 19.99 + 11.99;

	b = (int)19.99 + (int)11.99;	//�ɵ�C����ת����ʽ
	c = int(19.99) + int(11.99);	//�µ�C++��ת����ʽ
	cout << "a=" << a << " b=" << b << " c=" << c << endl;
	char ch = 'Z';

	cout << "The code for " << ch << "is" << int(ch) << endl;
	//���ϸ��ǿ������ת��
	cout << "Yes,the code if " << static_cast<int>(ch) << endl;

	//auto ����,�Զ�ʶ��
	auto x = 100;
	auto y = 1.3e9L;

	return 0;
}
