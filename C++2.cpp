#include <iostream>
//��������ָ���Ͳ��ؼ���std::ǰ׺
//using namespace std;	//using����ָ��
//int main(void)
//{
//	//����ʹ��C���ԵĻ��з�
//	cout << "Welcome to C++\n" << endl << "abcd" << endl << "woaiuin" << endl;
//
//	return 0;
//}
//
//int main(void)
//{
//	using namespace std;
//	cout << "Welcome to C++" << endl;
//	return 0;
//}

//����
//using namespace std;
//int main(void)
//{
//	//���������״�ʹ�ñ���ǰ������
//	int cat = 25;
//	cout << "cat=";
//	cout << cat << endl;
//	cat -= 1;
//	cout << "cat=" << cat << endl;
//	//C++����ʹ�����������
//	int a, b, c;
//	a = b = c = 6;
//	cout << "a=" << a << " b=" << b << " c=" << c << endl;
//	return 0;
//}


//cin���뺯��
//int main(void)
//{
//	using namespace std;
//	int num;
//	cout << "����������:";
//	cin >> num;
//	cout << "num=" << num << endl;
//
//	return 0;
//}
int stonetotal(int);
int main(void)
{
	/*using namespace std;
	int stone;
	cout << "������ʯͷ������:";
	cin >> stone;
	int pont = stonetotal(stone);
	cout<<"����: "<<pont<<endl;*/
	using std::cout;

	return 0;
}
int stonetotal(int n)
{
	return 14 * n;
}