#include <iostream>
#include <string>	//string��
#include <string.h>
#include <vector>
#include <array>
using namespace std;

//��ͨ��cin����
//int main(void)
//{
//	const int Size = 20;
//	char name[Size];
//	char fav[Size];
//	cout << "�������������:";
//	cin>>name;
//
//	cout << "����������ϲ����ˮ��:";
//	cin>>fav;
//	cout << "��ӭ��:" << name << endl << "����ϲ����ˮ����:" << fav << endl;
//	return 0;
//}


//ÿ�ζ�ȡһ���ַ�������
// getline�������з�
//int main(void)
//{
//	const int Size = 20;
//	char name[Size];
//	char fav[Size];
//	cout << "�������������:";
//	cin.getline(name, Size);
//
//	cout << "����������ϲ����ˮ��:";
//	cin.getline(fav, Size);
//	cout << "��ӭ��:" << name << endl << "����ϲ����ˮ����:" << fav << endl;
//	return 0;
//}


//ʹ��get����ȡ���У���
//int main(void)
//{
//	const int Size = 20;
//	char name[Size];
//	char fav[Size];
//	cout << "�������������:";
//	//cin.get(name, Size);
//	////����һ�����з��ڻ�����
//	//cin.get();
//	cin.get(name, Size).get();	//������ȡ����ͬ������
//	cout << "����������ϲ����ˮ��:";
//	cin.get(fav, Size);
//	cout << "��ӭ��:" << name << endl << "����ϲ����ˮ����:" << fav << endl;
//	return 0;
//}


//��������ַ���������
//int main()
//{
//	cout << "What year was your house bulit?";
//	int year;
//	cin >> year;
//	//������룬���л��д���
//	//cin.get();
//	//�ڶ��ַ���
//	//(cin >> year).get();
//	cout << "What is its street address?" << endl;
//	char address[80];
//	cin.getline(address, 80);
//
//	cout << "Year bulit: " << year << endl;
//	cout << "Address: " << address << endl << "Done!" << endl;
//	return 0;
//}


//ʹ��string��
//int main()
//{
//	//�б��ʼ��
//	string str1 = "woaini ylh";
//	string str2 = "lxy woaini";
//	//��һ��string��ֱ�Ӹ��Ƹ���һ��string
//	string str = str1;
//	//����ʹ��+������ϲ��ַ���
//	string stra = str1+str2;
//	str1 += str2;
//	string name;
//	cout << "�������������:";
//	cin >> name;
//	cout << "��ӭ��! " << name<<endl;
//	//����ʹ�������ʾ�������ʴ洢��string����ַ�
//	cout << name[4] << endl;
//	cout << str1 << endl << stra << endl;
//	return 0;
//}


//c++�ַ�����c�ַ����Ĳ����Ƚ�
//int main()
//{
//	string str1 = "woshiyihao";
//	string str2;
//	char arr1[20] = "woshiyihao";
//	char arr2[20];
//
//	//�ַ����ĸ���
//	str2 = str1;
//	strcpy(arr2, arr1);
//
//	//�ַ���ƴ��
//	str2 += "JUASD";
//	strcat(arr2, "ASDIJ");
//
//	//�ַ�������
//	cout << "The str2 is " << str2 << ",lengh is " << str2.size() << endl;
//	cout << "The arr2 is " << arr2 << ",lengh is " << strlen(arr2) << endl;
//
//	return 0;
//}


//
//int main()
//{
//	string str1 = "woaini";
//	string str2;
//
//	//�ֱ�ʹ��L u U�����
//	wchar_t arr1[] = L"I love China";
//	char16_t arr2[] = u"I love China";
//	char32_t arr3[] = U"I love china";
//
//	//ԭʼ�ַ�����ֱ����ʾ���ַ��������� R���
//	cout << R"("��\n��\n��\nԭ\nʼ\n��\n��\n��"!)" << endl;
//	//ʹ�� "+*( ��ǿ�ͷ, )+*" ��ǽ�β
//	cout << R"+*("��\n��\n��\nԭ\nʼ\n��\n��\n��"!)+*" << endl;
//
//	cout << "������:";
//	//��һ��д�� cin.getline
//	getline(cin, str2);
//	cout << "str: " << str2 << endl;
//	return 0;
//}


//ʹ�ýṹ
//struct Info
//{
//	string name;
//	double n;
//	float f;
//};
//int main()
//{
//	//ʡ��struct�ؼ���
//	//��ʼ���б�
//	Info Peo{"������",20,91};
//	//cout << "������" << Peo.name;
//	//cin >> Peo.n;
//	cout << Peo.n << endl;
//	cout << Peo.name << endl;
//	//ͬһ�����͵Ľṹ����ʹ�� = ������
//
//	return 0;
//}


//����ָ��
//int main()
//{
//	int a = 6;
//	int* p = &a;
//	int* q;
//	q = (int*) 0x00012;
//	cout << "p=" << p << endl;
//	cout << "&a=" << &a << endl;
//	cout << "a=" << a << endl;
//	cout << "*p=" << *p << endl;
//	cout << "*p+1=" << *p+1 << endl;
//
//	return 0;
//}


//��̬�ڴ����
//int main()
//{
//	int night = 1001;
//	//Ϊָ�����һ��int�Ŀռ�
//	int* p = new int;
//	*p = 95;
//	cout << "night= " << night << endl;
//	cout << "*p= " << *p << endl;
//	cout << "&p= " << p << endl;
//
//	double* pd = new double;
//	*pd = 999;
//	cout << "*pd= " << *pd << endl;
//	cout << "&pd= " << pd << endl;
//	//�ͷ��ڴ�
//	delete p;
//	delete pd;
//	return 0;
//}


//����Ķ�̬�뾲̬����
//int main()
//{
//	//new������� ���������С
//	//��ʾ10��Ԫ�ص�����
//	int* ps = new int[10];
//	int* s = ps;
//	
//	for (int i = 0; i < 10; i++)
//	{
//		ps[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << s[i] << " " << endl;
//	}
//	cout << ps << endl;
//	cout << &ps << endl;
//	//�ͷ���������
//	//�������ʱ�з����ţ����ͷ�ʱҲӦ���з�����
//	//������ƥ�䷽����
//	delete[]ps;
//	return 0;
//}



//ʹ��new�ṹ
//struct inflo
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	//Ϊ�ṹ����ռ�
//	inflo* Peo = new inflo;
//	cout << "����������:";
//	cin.getline(Peo->name, 20);
//	cout << "��ӭ�㣬" << Peo->name << endl;
//
//	return 0;
//}


//new deleteʵ��
//char* getname()
//{
//	char temp[80];
//	cout << "�������ַ���:";
//	cin >> temp;
//	//������̬���ַ�������
//	char* ps = new char[strlen(temp) + 1];
//	strcpy(ps, temp);
//	//����ָ��
//	return ps;
//}
//int main()
//{
//	char* name;
//	name = getname();
//	cout << name << " at " << (int*)name << endl;
//	//�ͷ�
//	delete []name;
//	return 0;
//}




//ģ����
//#include <vector>
//#include <array>
//int main()
//{
//	/*
//	vector
//	*/
//	//���ȿɱ� ����ǿ��
//	//vi��һ��vector<int>�Ķ���
//	//����һ����Ϊvi��vector���󣬿��Դ洢n������Ϊ<int>��Ԫ��,Ԫ�ظ��������ǳ�����Ҳ���Ǳ���
//	vector<int> vi;
//	int n;
//	cin >> n;
//	//vd��һ��victor<double>�Ķ���
//	vector<double> vd(n);
//
//	/*
//	array
//	*/
//	//���ȹ̶� ʹ��ջ�ڴ�
//	//�ֱ𴴽�5��Ԫ�غ�4��Ԫ�ص�����
//	//Ԫ�ظ��������Ǳ���
//	array<int, 5> ai;
//	array<double, 4> ad = { 1.1,2.2,3.3,4., };
//	cout << ad[0] << endl;
//	return 0;
//}



//һ���򵥵�ʵ�� ���� vector array
int main()
{
	//����
	double a[4] = { 1.1,2.2,3.3,4.4 };
	//vectorģ��
	vector<double> b(4);	//ע����Բ����
	for (int i = 0; i < 4; i++)
	{
		b[i] = (double)i+1;
	}
	//arrayģ��
	array<double, 4> c = { 5.5,6.6,7.7,8.8 };
	array<double, 4> d = c;	//����ֱ�ӽ�һ��array������Ϊ��һ��array����
	cout << "����: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout  << a[i]<<" ";
	}
	cout << endl;
	cout << "vector: " << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "array: " << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	//vector��array������г�Ա���� at()���Բ���������������
	vector<int> e(4);
	e.at(0) = 9;
	cout << e[0] << endl;
	return 0;
}
